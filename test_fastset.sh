#!/bin/bash
echo "FastSet tests"
echo "Running cxxtestgen..."
cxxtestgen --error-printer -o test/tmp/fastset_test_runner.cpp test/fastset_tests.h

echo "Compiling..."
g++ test/tmp/fastset_test_runner.cpp -o test/bin/test_fastset -Iinclude -O3 -std=c++17 -ftest-coverage -fprofile-arcs

RET=$?;
if [ $RET == 0 ] 
then
    mv *.gcno test/coverage_files/
    echo "running test/bin/test_fastset" 
    test/bin/test_fastset
    mv *.gcda test/coverage_files/
    gcov test/coverage_files/fastset_test_runner > test/coverage_files/fastset_gcov_output.txt
    mv *.gcov test/coverage_files/
else 
    echo "Compiler error.";
fi

echo "";
