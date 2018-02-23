#!/bin/bash
echo "Vector tests"
echo "Running cxxtestgen..."
cxxtestgen --error-printer -o test/tmp/pair_test_runner.cpp test/pair_tests.h

echo "Compiling..."
g++ test/tmp/pair_test_runner.cpp -o bin/test_pair -Iinclude -O3 -std=c++17

RET=$?;
if [ $RET == 0 ] 
then 
    echo "running bin/test_pair" 
    bin/test_pair
else 
    echo "Compiler error.";
fi

