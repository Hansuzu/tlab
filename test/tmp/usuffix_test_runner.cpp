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
#include "/home/haih/k/tlab/tlab/test/usuffix_tests.h"

static Tests suite_Tests;

static CxxTest::List Tests_Tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Tests( "test/usuffix_tests.h", 7, "Tests", suite_Tests, Tests_Tests );

static class TestDescription_suite_Tests_testPushInt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testPushInt() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 13, "testPushInt" ) {}
 void runTest() { suite_Tests.testPushInt(); }
} testDescription_suite_Tests_testPushInt;

static class TestDescription_suite_Tests_testPushIntVector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testPushIntVector() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 25, "testPushIntVector" ) {}
 void runTest() { suite_Tests.testPushIntVector(); }
} testDescription_suite_Tests_testPushIntVector;

static class TestDescription_suite_Tests_testPushStdString1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testPushStdString1() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 38, "testPushStdString1" ) {}
 void runTest() { suite_Tests.testPushStdString1(); }
} testDescription_suite_Tests_testPushStdString1;

static class TestDescription_suite_Tests_testPushStdString2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testPushStdString2() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 51, "testPushStdString2" ) {}
 void runTest() { suite_Tests.testPushStdString2(); }
} testDescription_suite_Tests_testPushStdString2;

static class TestDescription_suite_Tests_testIsSubstring1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testIsSubstring1() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 64, "testIsSubstring1" ) {}
 void runTest() { suite_Tests.testIsSubstring1(); }
} testDescription_suite_Tests_testIsSubstring1;

static class TestDescription_suite_Tests_testIsSubstring2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testIsSubstring2() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 81, "testIsSubstring2" ) {}
 void runTest() { suite_Tests.testIsSubstring2(); }
} testDescription_suite_Tests_testIsSubstring2;

static class TestDescription_suite_Tests_testIsSubstring3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testIsSubstring3() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 97, "testIsSubstring3" ) {}
 void runTest() { suite_Tests.testIsSubstring3(); }
} testDescription_suite_Tests_testIsSubstring3;

static class TestDescription_suite_Tests_testLCS : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Tests_testLCS() : CxxTest::RealTestDescription( Tests_Tests, suiteDescription_Tests, 104, "testLCS" ) {}
 void runTest() { suite_Tests.testLCS(); }
} testDescription_suite_Tests_testLCS;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
