#!/bin/bash
echo "UkkonenTree tests"
echo "Running cxxtestgen..."
cxxtestgen --error-printer -o test/tmp/usuffix_test_runner.cpp test/usuffix_tests.h

echo "Compiling..."
g++ test/tmp/usuffix_test_runner.cpp src/usuffixnode_vector.cpp -o test/bin/test_usuffix  -Iinclude -O3 -std=c++17 -ftest-coverage -fprofile-arcs

RET=$?;
if [ $RET == 0 ] 
then 
    echo "running test/bin/usuffix_test"
    test/bin/test_usuffix
    mv *.gcno test/coverage_files/
    mv *.gcda test/coverage_files/
    gcov test/coverage_files/usuffix_test_runner > test/coverage_files/usuffix_gcov_output.txt
    gcov test/coverage_files/usuffixnode_vector > test/coverage_files/usuffix_vector_gcov_output.txt
    mv *.gcov test/coverage_files/
else 
    echo "Compiler error.";
fi

echo "";
