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
#include "parser_tests.h"

static ParserTestSuite suite_ParserTestSuite;

static CxxTest::List Tests_ParserTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ParserTestSuite( "parser_tests.h", 14, "ParserTestSuite", suite_ParserTestSuite, Tests_ParserTestSuite );

static class TestDescription_ParserTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 19, "test_setup_code" ) {}
 void runTest() { suite_ParserTestSuite.test_setup_code(); }
} testDescription_ParserTestSuite_test_setup_code;

static class TestDescription_ParserTestSuite_test_parse_bad_syntax : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_bad_syntax() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 24, "test_parse_bad_syntax" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_bad_syntax(); }
} testDescription_ParserTestSuite_test_parse_bad_syntax;

static class TestDescription_ParserTestSuite_test_parse_sample_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_sample_1() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 31, "test_parse_sample_1" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_sample_1(); }
} testDescription_ParserTestSuite_test_parse_sample_1;

static class TestDescription_ParserTestSuite_test_parse_sample_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_sample_2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 40, "test_parse_sample_2" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_sample_2(); }
} testDescription_ParserTestSuite_test_parse_sample_2;

static class TestDescription_ParserTestSuite_test_parse_sample_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_sample_3() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 49, "test_parse_sample_3" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_sample_3(); }
} testDescription_ParserTestSuite_test_parse_sample_3;

static class TestDescription_ParserTestSuite_test_parse_sample_4 : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_sample_4() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 58, "test_parse_sample_4" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_sample_4(); }
} testDescription_ParserTestSuite_test_parse_sample_4;

static class TestDescription_ParserTestSuite_test_parse_sample_5 : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_sample_5() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 67, "test_parse_sample_5" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_sample_5(); }
} testDescription_ParserTestSuite_test_parse_sample_5;

static class TestDescription_ParserTestSuite_test_parse_mysample : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_mysample() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 76, "test_parse_mysample" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_mysample(); }
} testDescription_ParserTestSuite_test_parse_mysample;

static class TestDescription_ParserTestSuite_test_parse_forestLossV2 : public CxxTest::RealTestDescription {
public:
 TestDescription_ParserTestSuite_test_parse_forestLossV2() : CxxTest::RealTestDescription( Tests_ParserTestSuite, suiteDescription_ParserTestSuite, 85, "test_parse_forestLossV2" ) {}
 void runTest() { suite_ParserTestSuite.test_parse_forestLossV2(); }
} testDescription_ParserTestSuite_test_parse_forestLossV2;

#include <cxxtest/Root.cpp>
