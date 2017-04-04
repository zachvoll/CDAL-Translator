/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#define _CXXTEST_ABORT_TEST_ON_FAIL
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "ast_tests.h"

static AstTestSuite suite_AstTestSuite;

static CxxTest::List Tests_AstTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AstTestSuite( "ast_tests.h", 17, "AstTestSuite", suite_AstTestSuite, Tests_AstTestSuite );

static class TestDescription_AstTestSuite_test_sample_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_sample_1() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 87, "test_sample_1" ) {}
 void runTest() { suite_AstTestSuite.test_sample_1(); }
} testDescription_AstTestSuite_test_sample_1;

static class TestDescription_AstTestSuite_test_sample_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_sample_2() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 89, "test_sample_2" ) {}
 void runTest() { suite_AstTestSuite.test_sample_2(); }
} testDescription_AstTestSuite_test_sample_2;

static class TestDescription_AstTestSuite_test_sample_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_sample_3() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 91, "test_sample_3" ) {}
 void runTest() { suite_AstTestSuite.test_sample_3(); }
} testDescription_AstTestSuite_test_sample_3;

static class TestDescription_AstTestSuite_test_sample_4 : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_sample_4() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 93, "test_sample_4" ) {}
 void runTest() { suite_AstTestSuite.test_sample_4(); }
} testDescription_AstTestSuite_test_sample_4;

static class TestDescription_AstTestSuite_test_sample_5 : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_sample_5() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 95, "test_sample_5" ) {}
 void runTest() { suite_AstTestSuite.test_sample_5(); }
} testDescription_AstTestSuite_test_sample_5;

static class TestDescription_AstTestSuite_test_mysample : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_mysample() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 97, "test_mysample" ) {}
 void runTest() { suite_AstTestSuite.test_mysample(); }
} testDescription_AstTestSuite_test_mysample;

static class TestDescription_AstTestSuite_test_forest_loss : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_forest_loss() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 99, "test_forest_loss" ) {}
 void runTest() { suite_AstTestSuite.test_forest_loss(); }
} testDescription_AstTestSuite_test_forest_loss;

static class TestDescription_AstTestSuite_test_mysample_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_mysample_2() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 101, "test_mysample_2" ) {}
 void runTest() { suite_AstTestSuite.test_mysample_2(); }
} testDescription_AstTestSuite_test_mysample_2;

#include <cxxtest/Root.cpp>
