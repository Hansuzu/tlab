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
#include "/home/haih/k/tlab/tlab/test/unit_tests.h"

static Tests suite_Tests;

static CxxTest::List Tests_Tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Tests( "test/unit_tests.h", 6, "Tests", suite_Tests, Tests_Tests );

static class TestDescription_suite_Tests_testConstruction1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testConstruction1() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 9, "testConstruction1" ) {}
 void runTest() { suite_Tests.testConstruction1(); }
} testDescription_suite_Tests_testConstruction1;

static class TestDescription_suite_Tests_testConstruction2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testConstruction2() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 15, "testConstruction2" ) {}
 void runTest() { suite_Tests.testConstruction2(); }
} testDescription_suite_Tests_testConstruction2;

static class TestDescription_suite_Tests_testConstruction3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testConstruction3() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 21, "testConstruction3" ) {}
 void runTest() { suite_Tests.testConstruction3(); }
} testDescription_suite_Tests_testConstruction3;

static class TestDescription_suite_Tests_testPushInt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testPushInt() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 29, "testPushInt" ) {}
 void runTest() { suite_Tests.testPushInt(); }
} testDescription_suite_Tests_testPushInt;

static class TestDescription_suite_Tests_testPushIntVector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testPushIntVector() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 41, "testPushIntVector" ) {}
 void runTest() { suite_Tests.testPushIntVector(); }
} testDescription_suite_Tests_testPushIntVector;

static class TestDescription_suite_Tests_testPushStdString : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testPushStdString() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 54, "testPushStdString" ) {}
 void runTest() { suite_Tests.testPushStdString(); }
} testDescription_suite_Tests_testPushStdString;

static class TestDescription_suite_Tests_testAddChild1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testAddChild1() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 69, "testAddChild1" ) {}
 void runTest() { suite_Tests.testAddChild1(); }
} testDescription_suite_Tests_testAddChild1;

static class TestDescription_suite_Tests_testAddChild2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testAddChild2() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 80, "testAddChild2" ) {}
 void runTest() { suite_Tests.testAddChild2(); }
} testDescription_suite_Tests_testAddChild2;

static class TestDescription_suite_Tests_testAddAsChild1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testAddAsChild1() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 90, "testAddAsChild1" ) {}
 void runTest() { suite_Tests.testAddAsChild1(); }
} testDescription_suite_Tests_testAddAsChild1;

static class TestDescription_suite_Tests_testAddAsChild2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testAddAsChild2() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 102, "testAddAsChild2" ) {}
 void runTest() { suite_Tests.testAddAsChild2(); }
} testDescription_suite_Tests_testAddAsChild2;

static class TestDescription_suite_Tests_testAux : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testAux() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 113, "testAux" ) {}
 void runTest() { suite_Tests.testAux(); }
} testDescription_suite_Tests_testAux;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
