#!/usr/bin/env bash
rustfmt a.rs
rustc --lint a.rs && ./a < input.txt > output.txt