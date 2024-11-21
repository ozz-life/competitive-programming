package main

import (
    "crypto/rand"
    "fmt"
    "io"
)

func generateKey(length int) ([]byte, error) {
    key := make([]byte, length)
    _, err := io.ReadFull(rand.Reader, key)
    if err != nil {
        return nil, err
    }
    return key, nil
}

func main() {
    key, err := generateKey(32) // 256-bit key
    if err != nil {
        fmt.Println("Error generating key:", err)
        return
    }
    fmt.Printf("Generated secure key: %x\n", key)
}
