#!/usr/bin/env bash

# Компилируем программу на Go
gofmt -w a.go
go build -o program a.go

# Запускаем программу с использованием ввода из input.txt и вывода в output.txt
./program < input.txt > output.txt

# Удаляем скомпилированную программу
rm program