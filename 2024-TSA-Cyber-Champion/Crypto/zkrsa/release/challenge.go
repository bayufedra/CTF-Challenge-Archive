package main

import (
	"bytes"
	"crypto/rand"
	"crypto/rsa"
	"crypto/sha256"
	"encoding/hex"
	"fmt"
	"os"

	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/backend/groth16"
	"github.com/consensys/gnark/frontend"
	"github.com/consensys/gnark/frontend/cs/r1cs"
	"github.com/rs/zerolog"
)

func init() {
	zerolog.SetGlobalLevel(zerolog.Disabled)
}

func calculateHash(data string) string {
	hash := sha256.Sum256([]byte(data))
	return hex.EncodeToString(hash[:])
}

func randomHex(length int) (string, error) {
	bytes := make([]byte, length/2)
	if _, err := rand.Read(bytes); err != nil {
		return "", err
	}
	return hex.EncodeToString(bytes), nil
}

func proofOfWork() bool {
	challengeString, _ := randomHex(6)
	fmt.Println(challengeString)
	challengeHash := calculateHash(challengeString)
	fmt.Println("=== Proof of Work ===")
	fmt.Println("Provide me hexstring x such that len(x) == 6 AND SHA256(x) ==", challengeHash)

	var powInput string
	fmt.Print("x: ")
	fmt.Scanln(&powInput)

	return calculateHash(powInput) == challengeHash
}

func main() {

	// no DoS pls
	if !proofOfWork() {
		return
	}

	flag, err := os.ReadFile("flag.txt")
	if err != nil {
		panic(err)
	}

	privateKey, err := rsa.GenerateKey(rand.Reader, 2048)
	if err != nil {
		panic(err)
	}

	fmt.Println("RSA Modulus:", privateKey.N.String())

	circuit := Circuit{
		P:   0, // ignore private value
		Q:   0, // ignore private value
		RSA: privateKey.N,
	}

	witness, err := frontend.NewWitness(&circuit, ecc.BLS12_377.ScalarField())
	if err != nil {
		panic(err)
	}

	publicWitness, err := witness.Public()
	if err != nil {
		panic(err)
	}

	r1cs, _ := frontend.Compile(ecc.BLS12_377.ScalarField(), r1cs.NewBuilder, &circuit)

	pk, vk, _ := groth16.Setup(r1cs)

	var pkHex bytes.Buffer
	pk.WriteTo(&pkHex)
	fmt.Println("ProvingKey:", fmt.Sprintf("%x", pkHex.Bytes()))

	var input string
	fmt.Print("Give me a proof that you know the factors: ")
	fmt.Scanln(&input)

	proofBytes, err := hex.DecodeString(input)
	if err != nil {
		fmt.Println("Invalid proof!")
		return
	}

	proof := groth16.NewProof(ecc.BLS12_377)
	_, err = proof.ReadFrom(bytes.NewReader(proofBytes))
	if err != nil {
		fmt.Println("Invalid proof!")
		return
	}

	err = groth16.Verify(proof, vk, publicWitness)
	if err != nil {
		fmt.Println("Invalid proof!")
		return
	}

	fmt.Println("Congrats! Here is your flag:", string(flag))
}
