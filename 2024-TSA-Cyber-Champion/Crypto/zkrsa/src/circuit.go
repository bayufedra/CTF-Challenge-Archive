package main

import (
	"github.com/consensys/gnark/frontend"
)

type Circuit struct {
	P   frontend.Variable // p  --> secret visibility (default)
	Q   frontend.Variable `gnark:"q,secret"` // q  --> secret visibility
	RSA frontend.Variable `gnark:",public"`  // rsa  --> public visibility
}

// taken from official example: https://play.gnark.io/?id=rsa
// so it should be safe
func (circuit *Circuit) Define(api frontend.API) error {
	// ensure we don't accept RSA * 1 == RSA
	api.AssertIsDifferent(circuit.P, 1)
	api.AssertIsDifferent(circuit.Q, 1)

	// compute P * Q and store it in the local variable res.
	rsa := api.Mul(circuit.P, circuit.Q)

	// assert that the statement P * Q == RSA is true.
	api.AssertIsEqual(circuit.RSA, rsa)
	return nil
}
