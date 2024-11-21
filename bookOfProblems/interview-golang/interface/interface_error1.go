package main

import (
	"fmt"
)

// CustomError представляет пользовательскую ошибку с сообщением и кодом
type CustomError struct {
	Msg  string
	Code int
}

// Error реализует интерфейс error для CustomError
func (ce *CustomError) Error() string {
	return fmt.Sprintf("error: %s, code: %d", ce.Msg, ce.Code)
}

// NewCustomError создает новую ошибку CustomError
func NewCustomError(msg string, code int) *CustomError {
	return &CustomError{
		Msg:  msg,
		Code: code,
	}
}

func main() {
	// Пример использования CustomError
	err := NewCustomError("something went wrong", 123)
	if err != nil {
		fmt.Println(err)
	}
}