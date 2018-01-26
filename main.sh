#!/bin/bash
echo "Compiling..."
g++ src/main.cpp src/usuffix.cpp -std=c++17 -O3 -Wall -o bin/main -Iinclude

RET=$?;
if [ $RET == 0 ] 
then 
    echo "running bin/main"
    bin/main
else 
    echo "Compiler error.";
fi

