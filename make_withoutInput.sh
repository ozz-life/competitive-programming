#!/usr/bin/env bash
clang++ --std=c++20 -Wno-c++17-extensions -O3 a.cpp 

#g++ a.cpp -g -o segfault && ./a.out < input.txt > output.txt