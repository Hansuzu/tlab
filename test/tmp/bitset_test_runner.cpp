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
#include "/home/haih/k/tlab/tlab/test/bitset_tests.h"

static Tests suite_Tests;

static CxxTest::List Tests_Tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Tests( "test/bitset_tests.h", 5, "Tests", suite_Tests, Tests_Tests );

static class TestDescription_suite_Tests_testInsert : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testInsert() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 8, "testInsert" ) {}
 void runTest() { suite_Tests.testInsert(); }
} testDescription_suite_Tests_testInsert;

static class TestDescription_suite_Tests_testAnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testAnd() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 20, "testAnd" ) {}
 void runTest() { suite_Tests.testAnd(); }
} testDescription_suite_Tests_testAnd;

static class TestDescription_suite_Tests_testOr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testOr() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 44, "testOr" ) {}
 void runTest() { suite_Tests.testOr(); }
} testDescription_suite_Tests_testOr;

static class TestDescription_suite_Tests_testPopcount : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testPopcount() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 69, "testPopcount" ) {}
 void runTest() { suite_Tests.testPopcount(); }
} testDescription_suite_Tests_testPopcount;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
