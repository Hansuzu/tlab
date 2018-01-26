#!/bin/bash
g++ src/main.cpp src/usuffix.cpp -std=c++17 -O3 -Wall -o bin/main -Iinclude
./bin/main
