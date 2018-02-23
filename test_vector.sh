#!/bin/bash
echo "Vector tests"
echo "Running cxxtestgen..."
cxxtestgen --error-printer -o test/tmp/vector_test_runner.cpp test/vector_tests.h

echo "Compiling..."
g++ test/tmp/vector_test_runner.cpp -o bin/test_vector -Iinclude -O3 -std=c++17

RET=$?;
if [ $RET == 0 ] 
then 
    echo "running bin/test_vector" 
    bin/test_vector
else 
    echo "Compiler error.";
fi

