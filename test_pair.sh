#!/bin/bash
echo "Vector tests"
echo "Running cxxtestgen..."
cxxtestgen --error-printer -o test/tmp/pair_test_runner.cpp test/pair_tests.h

echo "Compiling..."
g++ test/tmp/pair_test_runner.cpp -o test/bin/test_pair -Iinclude -O3 -std=c++17 -ftest-coverage -fprofile-arcs

RET=$?;
if [ $RET == 0 ] 
then 
    mv *.gcno test/coverage_files/
    echo "running test/bin/test_pair" 
    test/bin/test_pair
    mv *.gcda test/coverage_files/
    gcov test/coverage_files/pair_test_runner > test/coverage_files/pair_gcov_output.txt
    mv *.gcov test/coverage_files/
else 
    echo "Compiler error.";
fi
echo "";
