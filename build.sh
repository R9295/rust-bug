#!/bin/bash
clang++ -std=c++17 -c asd.cc -o thrower.o
cargo build --release
clang++ -std=c++17 ./main.cc ./target/release/libasdf.a -o ./release

clang++ -std=c++17 -c asd.cc -o thrower.o
cargo build
clang++ -std=c++17 ./main.cc ./target/debug/libasdf.a -o ./debug
