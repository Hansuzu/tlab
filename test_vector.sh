#!/bin/bash
echo "Vector tests"
echo "Running cxxtestgen..."
cxxtestgen --error-printer -o test/tmp/vector_test_runner.cpp test/vector_tests.h

echo "Compiling..."
g++ test/tmp/vector_test_runner.cpp -o test/bin/test_vector -Iinclude -O3 -std=c++17 -ftest-coverage -fprofile-arcs


RET=$?;
if [ $RET == 0 ] 
then 
    mv *.gcno test/coverage_files/
    echo "running test/bin/test_vector" 
    test/bin/test_vector
    mv *.gcda test/coverage_files/
    gcov test/coverage_files/vector_test_runner > test/coverage_files/vector_gcov_output.txt
    mv *.gcov test/coverage_files/
else 
    echo "Compiler error.";
fi
echo "";

