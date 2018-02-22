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
#include "/home/haih/k/tlab/tlab/test/fastset_tests.h"

static Tests suite_Tests;

static CxxTest::List Tests_Tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Tests( "test/fastset_tests.h", 5, "Tests", suite_Tests, Tests_Tests );

static class TestDescription_suite_Tests_testInsert1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testInsert1() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 8, "testInsert1" ) {}
 void runTest() { suite_Tests.testInsert1(); }
} testDescription_suite_Tests_testInsert1;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
