#!/bin/bash
cxxtestgen --error-printer -o test/tmp/unit_test_runner.cpp test/unit_tests.h
g++ test/tmp/unit_test_runner.cpp -o bin/runner -Iinclude -O3 -std=c++17
bin/runner
