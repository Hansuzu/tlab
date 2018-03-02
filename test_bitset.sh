#!/bin/bash
echo "Bitset tests"
echo "Running cxxtestgen..."
cxxtestgen --error-printer -o test/tmp/bitset_test_runner.cpp test/bitset_tests.h

echo "Compiling..."
g++ test/tmp/bitset_test_runner.cpp -o test/bin/test_bitset -Iinclude -O3 -std=c++17 -ftest-coverage -fprofile-arcs

RET=$?;
if [ $RET == 0 ] 
then 
    echo "running test/bin/test_bitset" 
    test/bin/test_bitset
    mv *.gcno test/coverage_files/
    mv *.gcda test/coverage_files/
    gcov test/coverage_files/bitset_test_runner > test/coverage_files/bitset_gcov_output.txt
    mv *.gcov test/coverage_files/
else 
    echo "Compiler error.";
fi
echo "";
