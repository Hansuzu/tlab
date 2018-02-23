#!/bin/bash
echo "Bitset tests"
echo "Running cxxtestgen..."
cxxtestgen --error-printer -o test/tmp/bitset_test_runner.cpp test/bitset_tests.h

echo "Compiling..."
g++ test/tmp/bitset_test_runner.cpp -o bin/test_bitset -Iinclude -O3 -std=c++17

RET=$?;
if [ $RET == 0 ] 
then 
    echo "running bin/test_bitset" 
    bin/test_bitset
else 
    echo "Compiler error.";
fi

