package main

import (
    "crypto/rand"
    "encoding/base64"
    "fmt"
)

func generateToken(length int) (string, error) {
    token := make([]byte, length)
    _, err := rand.Read(token)
    if err != nil {
        return "", err
    }
    return base64.URLEncoding.EncodeToString(token), nil
}

func main() {
    token, err := generateToken(32) // 256-bit token
    if err != nil {
        fmt.Println("Error generating token:", err)
        return
    }
    fmt.Printf("Generated secure token: %s\n", token)
}