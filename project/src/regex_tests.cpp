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
#include "regex_tests.h"

static RegexTestSuite suite_RegexTestSuite;

static CxxTest::List Tests_RegexTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RegexTestSuite( "regex_tests.h", 6, "RegexTestSuite", suite_RegexTestSuite, Tests_RegexTestSuite );

static class TestDescription_RegexTestSuite_test_make_matchRegex_match : public CxxTest::RealTestDescription {
public:
 TestDescription_RegexTestSuite_test_make_matchRegex_match() : CxxTest::RealTestDescription( Tests_RegexTestSuite, suiteDescription_RegexTestSuite, 17, "test_make_matchRegex_match" ) {}
 void runTest() { suite_RegexTestSuite.test_make_matchRegex_match(); }
} testDescription_RegexTestSuite_test_make_matchRegex_match;

static class TestDescription_RegexTestSuite_test_make_matchRegex_no_match : public CxxTest::RealTestDescription {
public:
 TestDescription_RegexTestSuite_test_make_matchRegex_no_match() : CxxTest::RealTestDescription( Tests_RegexTestSuite, suiteDescription_RegexTestSuite, 24, "test_make_matchRegex_no_match" ) {}
 void runTest() { suite_RegexTestSuite.test_make_matchRegex_no_match(); }
} testDescription_RegexTestSuite_test_make_matchRegex_no_match;

static class TestDescription_RegexTestSuite_test_make_matchRegex_match_string_copy : public CxxTest::RealTestDescription {
public:
 TestDescription_RegexTestSuite_test_make_matchRegex_match_string_copy() : CxxTest::RealTestDescription( Tests_RegexTestSuite, suiteDescription_RegexTestSuite, 31, "test_make_matchRegex_match_string_copy" ) {}
 void runTest() { suite_RegexTestSuite.test_make_matchRegex_match_string_copy(); }
} testDescription_RegexTestSuite_test_make_matchRegex_match_string_copy;

#include <cxxtest/Root.cpp>
