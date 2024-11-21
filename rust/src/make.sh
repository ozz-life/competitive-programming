#!/usr/bin/env bash

# Определяем переменные для путей
PROJECT_DIR="/home/ozz/git/competitive-programming/rust"
SRC_DIR="$PROJECT_DIR/src"
TARGET_DIR="$PROJECT_DIR/target/debug"
INPUT_FILE="$SRC_DIR/input.txt"
OUTPUT_FILE="$SRC_DIR/output.txt"
EXECUTABLE="$TARGET_DIR/rust"

# Форматируем код, проверяем с помощью Clippy и компилируем проект
cargo fmt
cargo clippy -- -W clippy::pedantic
cargo build

# Запускаем исполняемый файл с перенаправлением ввода и вывода
"$EXECUTABLE" < "$INPUT_FILE" > "$OUTPUT_FILE"