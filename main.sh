#!/bin/bash
echo "Compiling..."
g++ src/usuffix.cpp src/main.cpp -std=c++17 -O3 -march=native -Wall -o bin/main -Iinclude

RET=$?;
if [ $RET == 0 ] 
then 
    echo "running bin/main"
    bin/main
else 
    echo "Compiler error.";
fi

