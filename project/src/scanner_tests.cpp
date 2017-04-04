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
#include "scanner_tests.h"

static ScannerTestSuite suite_ScannerTestSuite;

static CxxTest::List Tests_ScannerTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "scanner_tests.h", 8, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_ScannerTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 17, "test_setup_code" ) {}
 void runTest() { suite_ScannerTestSuite.test_setup_code(); }
} testDescription_ScannerTestSuite_test_setup_code;

static class TestDescription_ScannerTestSuite_test_scan_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 132, "test_scan_empty" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty(); }
} testDescription_ScannerTestSuite_test_scan_empty;

static class TestDescription_ScannerTestSuite_test_scan_empty_comment : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty_comment() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 139, "test_scan_empty_comment" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty_comment(); }
} testDescription_ScannerTestSuite_test_scan_empty_comment;

static class TestDescription_ScannerTestSuite_test_scan_lexicalErrors : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_lexicalErrors() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 148, "test_scan_lexicalErrors" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_lexicalErrors(); }
} testDescription_ScannerTestSuite_test_scan_lexicalErrors;

static class TestDescription_ScannerTestSuite_test_scan_nums_vars : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_nums_vars() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 168, "test_scan_nums_vars" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_nums_vars(); }
} testDescription_ScannerTestSuite_test_scan_nums_vars;

static class TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 180, "test_scan_bad_syntax_good_tokens" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_bad_syntax_good_tokens(); }
} testDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens;

static class TestDescription_ScannerTestSuite_test_scan_sample_forestLoss : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_sample_forestLoss() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 216, "test_scan_sample_forestLoss" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_sample_forestLoss(); }
} testDescription_ScannerTestSuite_test_scan_sample_forestLoss;

static class TestDescription_ScannerTestSuite_test_scan_sample_mysample : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_sample_mysample() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 221, "test_scan_sample_mysample" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_sample_mysample(); }
} testDescription_ScannerTestSuite_test_scan_sample_mysample;

static class TestDescription_ScannerTestSuite_test_additional_scan_function : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_additional_scan_function() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 226, "test_additional_scan_function" ) {}
 void runTest() { suite_ScannerTestSuite.test_additional_scan_function(); }
} testDescription_ScannerTestSuite_test_additional_scan_function;

static class TestDescription_ScannerTestSuite_test_terminal_intKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_intKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 247, "test_terminal_intKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_intKwd(); }
} testDescription_ScannerTestSuite_test_terminal_intKwd;

static class TestDescription_ScannerTestSuite_test_terminal_floatKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_floatKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 251, "test_terminal_floatKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_floatKwd(); }
} testDescription_ScannerTestSuite_test_terminal_floatKwd;

static class TestDescription_ScannerTestSuite_test_terminal_stringKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_stringKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 255, "test_terminal_stringKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_stringKwd(); }
} testDescription_ScannerTestSuite_test_terminal_stringKwd;

static class TestDescription_ScannerTestSuite_test_terminal_matrixKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_matrixKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 259, "test_terminal_matrixKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_matrixKwd(); }
} testDescription_ScannerTestSuite_test_terminal_matrixKwd;

static class TestDescription_ScannerTestSuite_test_terminal_letKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_letKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 263, "test_terminal_letKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_letKwd(); }
} testDescription_ScannerTestSuite_test_terminal_letKwd;

static class TestDescription_ScannerTestSuite_test_terminal_inKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_inKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 267, "test_terminal_inKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_inKwd(); }
} testDescription_ScannerTestSuite_test_terminal_inKwd;

static class TestDescription_ScannerTestSuite_test_terminal_endKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_endKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 271, "test_terminal_endKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_endKwd(); }
} testDescription_ScannerTestSuite_test_terminal_endKwd;

static class TestDescription_ScannerTestSuite_test_terminal_ifKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_ifKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 275, "test_terminal_ifKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_ifKwd(); }
} testDescription_ScannerTestSuite_test_terminal_ifKwd;

static class TestDescription_ScannerTestSuite_test_terminal_thenKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_thenKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 279, "test_terminal_thenKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_thenKwd(); }
} testDescription_ScannerTestSuite_test_terminal_thenKwd;

static class TestDescription_ScannerTestSuite_test_terminal_elseKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_elseKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 283, "test_terminal_elseKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_elseKwd(); }
} testDescription_ScannerTestSuite_test_terminal_elseKwd;

static class TestDescription_ScannerTestSuite_test_terminal_repeatKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_repeatKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 287, "test_terminal_repeatKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_repeatKwd(); }
} testDescription_ScannerTestSuite_test_terminal_repeatKwd;

static class TestDescription_ScannerTestSuite_test_terminal_printKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_printKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 291, "test_terminal_printKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_printKwd(); }
} testDescription_ScannerTestSuite_test_terminal_printKwd;

static class TestDescription_ScannerTestSuite_test_terminal_toKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_toKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 295, "test_terminal_toKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_toKwd(); }
} testDescription_ScannerTestSuite_test_terminal_toKwd;

static class TestDescription_ScannerTestSuite_test_terminal_intConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_intConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 300, "test_terminal_intConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_intConst(); }
} testDescription_ScannerTestSuite_test_terminal_intConst;

static class TestDescription_ScannerTestSuite_test_terminal_floatConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_floatConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 304, "test_terminal_floatConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_floatConst(); }
} testDescription_ScannerTestSuite_test_terminal_floatConst;

static class TestDescription_ScannerTestSuite_test_terminal_stringConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_stringConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 308, "test_terminal_stringConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_stringConst(); }
} testDescription_ScannerTestSuite_test_terminal_stringConst;

static class TestDescription_ScannerTestSuite_test_terminal_variableName : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_variableName() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 313, "test_terminal_variableName" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_variableName(); }
} testDescription_ScannerTestSuite_test_terminal_variableName;

static class TestDescription_ScannerTestSuite_test_terminal_leftParen : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 318, "test_terminal_leftParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftParen(); }
} testDescription_ScannerTestSuite_test_terminal_leftParen;

static class TestDescription_ScannerTestSuite_test_terminal_rightParen : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 322, "test_terminal_rightParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightParen(); }
} testDescription_ScannerTestSuite_test_terminal_rightParen;

static class TestDescription_ScannerTestSuite_test_terminal_leftCurly : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftCurly() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 326, "test_terminal_leftCurly" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftCurly(); }
} testDescription_ScannerTestSuite_test_terminal_leftCurly;

static class TestDescription_ScannerTestSuite_test_terminal_rightCurly : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightCurly() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 330, "test_terminal_rightCurly" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightCurly(); }
} testDescription_ScannerTestSuite_test_terminal_rightCurly;

static class TestDescription_ScannerTestSuite_test_terminal_leftSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftSquare() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 334, "test_terminal_leftSquare" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftSquare(); }
} testDescription_ScannerTestSuite_test_terminal_leftSquare;

static class TestDescription_ScannerTestSuite_test_terminal_rightSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightSquare() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 338, "test_terminal_rightSquare" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightSquare(); }
} testDescription_ScannerTestSuite_test_terminal_rightSquare;

static class TestDescription_ScannerTestSuite_test_terminal_semiColon : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_semiColon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 342, "test_terminal_semiColon" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_semiColon(); }
} testDescription_ScannerTestSuite_test_terminal_semiColon;

static class TestDescription_ScannerTestSuite_test_terminal_colon : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_colon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 346, "test_terminal_colon" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_colon(); }
} testDescription_ScannerTestSuite_test_terminal_colon;

static class TestDescription_ScannerTestSuite_test_terminal_assign : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_assign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 351, "test_terminal_assign" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_assign(); }
} testDescription_ScannerTestSuite_test_terminal_assign;

static class TestDescription_ScannerTestSuite_test_terminal_plusSign : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_plusSign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 355, "test_terminal_plusSign" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_plusSign(); }
} testDescription_ScannerTestSuite_test_terminal_plusSign;

static class TestDescription_ScannerTestSuite_test_terminal_star : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_star() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 359, "test_terminal_star" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_star(); }
} testDescription_ScannerTestSuite_test_terminal_star;

static class TestDescription_ScannerTestSuite_test_terminal_dash : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_dash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 363, "test_terminal_dash" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_dash(); }
} testDescription_ScannerTestSuite_test_terminal_dash;

static class TestDescription_ScannerTestSuite_test_terminal_forwardSlash : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_forwardSlash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 367, "test_terminal_forwardSlash" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_forwardSlash(); }
} testDescription_ScannerTestSuite_test_terminal_forwardSlash;

static class TestDescription_ScannerTestSuite_test_terminal_lessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_lessThan() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 371, "test_terminal_lessThan" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lessThan(); }
} testDescription_ScannerTestSuite_test_terminal_lessThan;

static class TestDescription_ScannerTestSuite_test_terminal_lessThanEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_lessThanEqual() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 375, "test_terminal_lessThanEqual" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lessThanEqual(); }
} testDescription_ScannerTestSuite_test_terminal_lessThanEqual;

static class TestDescription_ScannerTestSuite_test_terminal_greaterThan : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_greaterThan() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 379, "test_terminal_greaterThan" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_greaterThan(); }
} testDescription_ScannerTestSuite_test_terminal_greaterThan;

static class TestDescription_ScannerTestSuite_test_terminal_greaterThanEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_greaterThanEqual() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 383, "test_terminal_greaterThanEqual" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_greaterThanEqual(); }
} testDescription_ScannerTestSuite_test_terminal_greaterThanEqual;

static class TestDescription_ScannerTestSuite_test_terminal_equalsEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_equalsEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 387, "test_terminal_equalsEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_equalsEquals(); }
} testDescription_ScannerTestSuite_test_terminal_equalsEquals;

static class TestDescription_ScannerTestSuite_test_terminal_notEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_notEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 391, "test_terminal_notEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_notEquals(); }
} testDescription_ScannerTestSuite_test_terminal_notEquals;

static class TestDescription_ScannerTestSuite_test_terminal_andOp : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_andOp() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 395, "test_terminal_andOp" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_andOp(); }
} testDescription_ScannerTestSuite_test_terminal_andOp;

static class TestDescription_ScannerTestSuite_test_terminal_orOp : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_orOp() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 399, "test_terminal_orOp" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_orOp(); }
} testDescription_ScannerTestSuite_test_terminal_orOp;

static class TestDescription_ScannerTestSuite_test_terminal_notOp : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_notOp() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 403, "test_terminal_notOp" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_notOp(); }
} testDescription_ScannerTestSuite_test_terminal_notOp;

static class TestDescription_ScannerTestSuite_test_terminal_endOfFile : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_endOfFile() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 408, "test_terminal_endOfFile" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_endOfFile(); }
} testDescription_ScannerTestSuite_test_terminal_endOfFile;

static class TestDescription_ScannerTestSuite_test_terminal_lexicalError : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_lexicalError() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 412, "test_terminal_lexicalError" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lexicalError(); }
} testDescription_ScannerTestSuite_test_terminal_lexicalError;

static class TestDescription_ScannerTestSuite_test_terminal_boolKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_boolKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 418, "test_terminal_boolKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_boolKwd(); }
} testDescription_ScannerTestSuite_test_terminal_boolKwd;

static class TestDescription_ScannerTestSuite_test_terminal_trueKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_trueKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 422, "test_terminal_trueKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_trueKwd(); }
} testDescription_ScannerTestSuite_test_terminal_trueKwd;

static class TestDescription_ScannerTestSuite_test_terminal_falseKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_falseKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 426, "test_terminal_falseKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_falseKwd(); }
} testDescription_ScannerTestSuite_test_terminal_falseKwd;

static class TestDescription_ScannerTestSuite_test_terminal_whileKwd : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_whileKwd() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 430, "test_terminal_whileKwd" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_whileKwd(); }
} testDescription_ScannerTestSuite_test_terminal_whileKwd;

#include <cxxtest/Root.cpp>
