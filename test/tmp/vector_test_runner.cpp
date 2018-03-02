/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_Tests_init = false;
#include "/home/haih/k/tlab/tlab/test/vector_tests.h"

static Tests suite_Tests;

static CxxTest::List Tests_Tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Tests( "test/vector_tests.h", 6, "Tests", suite_Tests, Tests_Tests );

static class TestDescription_suite_Tests_testInsert1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testInsert1() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 9, "testInsert1" ) {}
 void runTest() { suite_Tests.testInsert1(); }
} testDescription_suite_Tests_testInsert1;

static class TestDescription_suite_Tests_testAccess : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testAccess() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 19, "testAccess" ) {}
 void runTest() { suite_Tests.testAccess(); }
} testDescription_suite_Tests_testAccess;

static class TestDescription_suite_Tests_testLargeArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testLargeArray() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 31, "testLargeArray" ) {}
 void runTest() { suite_Tests.testLargeArray(); }
} testDescription_suite_Tests_testLargeArray;

static class TestDescription_suite_Tests_test_resize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_test_resize() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 45, "test_resize" ) {}
 void runTest() { suite_Tests.test_resize(); }
} testDescription_suite_Tests_test_resize;

static class TestDescription_suite_Tests_test_shrink_to_fit : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_test_shrink_to_fit() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 52, "test_shrink_to_fit" ) {}
 void runTest() { suite_Tests.test_shrink_to_fit(); }
} testDescription_suite_Tests_test_shrink_to_fit;

static class TestDescription_suite_Tests_test_swap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_test_swap() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 62, "test_swap" ) {}
 void runTest() { suite_Tests.test_swap(); }
} testDescription_suite_Tests_test_swap;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
