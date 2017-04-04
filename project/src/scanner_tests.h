#include <cxxtest/TestSuite.h>

#include "readInput.h"
#include "scanner.h"
#include <stdio.h>
using namespace std ;

class ScannerTestSuite : public CxxTest::TestSuite 
{
public:
    /* A Scanner object is created in the test_setup_code method.
       This is a test, beginning with "test_", so that it is executed
       by the testing framework.  The scanner is used in some tests of
       the method "scan".
     */
    Scanner *s ;
    void test_setup_code ( ) {
        s = new Scanner() ;
    }

    // Tests for components and functions used by "scan"
    // --------------------------------------------------

    /* You should test the regular expressions you use to make and match 
       regular expressions,and the functions used by makeRegex and 
       matchRegex using regex_tests.h.
       However, You will likely need to write several tests to 
       adequately test  the functions that are called from "scan".
       Once you are confident that the components used by "scan" 
       work properly, then you can run tests on the "scan" method itself.
    */

    // You should place tests for these other functions used by
    // scan below.


    /* Below is one of the tests for these components in the project
       solution created by your instructor.  It uses a helper
       function function called "tokenMaker_tester", which you have
       not been given.  You are expected to design your own components
       for "scan" and your own mechanisms for easily testing them.

        void xtest_TokenMaker_leftCurly ( ) {
            tokenMaker_tester ("{ ", "^\\{", leftCurly, "{" ) ;
        }

        Note that this test is here named "xtest_Token..." The leading
        "x" is so that cxxTest doesn't scan the line above and think
        it is an actual test that isn't commented out.  cxxTest is
        very simple and doesn't even process block comments.
    */


    /* You must have at least one separate test case for each terminal
       symbol.  Thus, you need a test that will pass or fail based
       solely on the regular expression (and its corresponding code)
       for each terminal symbol.

       This requires a test case for each element of the enumerated
       type tokenType.  This may look something like the sample test
       shown in the comment above.
    */

    // Tests for "scan"
    // --------------------------------------------------

    /* Below are some helper functions and sample tests for testing the 
       "scan" method on Scanner.
    */
	
    // Test that a list of tokens has no lexicalError tokens.
    bool noLexicalErrors (Token *tks) {
        Token *currentToken = tks ;
        while (currentToken != NULL) {
            if (currentToken->terminal == lexicalError) {
                printf("problem: %s\n",currentToken->lexeme.c_str());
				return false ;
            }
            else {
                currentToken = currentToken->next ;
            }
        }
        return true ;
    }
	
    /* A quick, but inaccurate, test for scanning files.  It only
       checks that no lexical errors occurred, not that the right
       tokens were returned. 
    */
    void scanFileNoLexicalErrors ( const char* filename ) {
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT ( text ) ;
        Token *tks = s->scan ( text ) ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT (noLexicalErrors(tks));
    }


    /* This function checks that the terminal fields in the list of
       tokens matches a list of terminals.
    */
    bool sameTerminals (Token *tks, int numTerms, tokenType *ts) {
        Token *currentToken = tks ;
        int termIndex = 0 ;
        while (currentToken != NULL && termIndex < numTerms ) {
            if (currentToken->terminal != ts[termIndex]) {
            printf("%i: %i should be %i\n",termIndex,currentToken->terminal , ts[termIndex]);
            printf("%s\n", (currentToken->lexeme).c_str());
			fflush(stdout);
                return false ;
            }
            else {
                ++ termIndex ;
                currentToken = currentToken->next ;
            }
        }
        return true ;
    }

    /* Below are the provided test files that your code should also
       pass.

       You may initially want to rename these tests to "xtest_..." so
       that the CxxTest framework does not see it as a test and won't
       run it as one.  This way you can focus on the tests that you'll
       write above for the individual terminal types first. Then focus
       on these tests.

    */

    // The "endOfFile" token is always the last one in the list of tokens.
    void test_scan_empty ( ) {
        Token *tks = s->scan ("  ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    void test_scan_empty_comment ( ) {
        Token *tks = s->scan (" /* a comment */ ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    // When a lexical error occurs, the scanner creates a token with a 
    // single-character lexeme and lexicalError as the terminal.
   void test_scan_lexicalErrors ( ) {
        Token *tks = s->scan ("$&1  ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "$");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "&");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, intConst) ;
        TS_ASSERT_EQUALS (tks->lexeme, "1");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    // A test for scanning numbers and a variable.
    void test_scan_nums_vars ( ) {
        Token *tks = s->scan (" 123 x 12.34 ") ;
        TS_ASSERT (tks != NULL) ;
        tokenType ts[] = { intConst, variableName, floatConst, endOfFile } ;
        TS_ASSERT ( sameTerminals ( tks, 4, ts ) ) ;
    }

    /* This test checks that the scanner returns a list of tokens with
       the correct terminal fields.  It doesn't check that the lexemes
       are correct.
     */
    
    void test_scan_bad_syntax_good_tokens ( ) {
        const char *filename = "../samples/bad_syntax_good_tokens.dsl" ;
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT ( text ) ;
        Token *tks = s->scan ( text ) ;
        TS_ASSERT (tks != NULL) ;
        tokenType ts[] = { 
            intConst, intConst, intConst, intConst, 

            stringConst, stringConst, stringConst,

            floatConst, floatConst, floatConst,

                   matrixKwd,

            semiColon, colon,
            leftCurly, leftParen, rightCurly, rightParen,

            plusSign, star, dash, forwardSlash, 

            equalsEquals, lessThanEqual, 
            greaterThanEqual, notEquals, 
            assign,

            variableName, variableName, variableName, variableName, 
            variableName, variableName, variableName,


            intKwd, floatKwd,  stringKwd, 

            endOfFile
       } ;
        int count = 38; 
        TS_ASSERT ( sameTerminals ( tks, count, ts ) ) ;
    }

    void test_scan_sample_forestLoss ( ) {
        scanFileNoLexicalErrors ("../samples/forest_loss_v2.dsl") ;
    }
    
    //test our sample
    void test_scan_sample_mysample ( ) {
        scanFileNoLexicalErrors ("../samples/mysample.dsl") ;
    }

    // Test additional scan function
    void test_additional_scan_function ( ) {
        const char *filename = "../samples/mysample.dsl" ;
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT ( text ) ;
	regex_t** array = s->makeRegexArray() ;
        Token *tks = s->scan (array, text) ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT (noLexicalErrors(tks)) ; 

    }
    
    /* 
     * Helper function for testing terminals 
     */
    void testTerminal(const char *text, tokenType token) {
	Token *tks = s->scan (text) ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, token) ;
	}
        
    //keyword terminal tests
    void test_terminal_intKwd(){
        testTerminal("int", intKwd);
	} 
	
	void test_terminal_floatKwd(){
        testTerminal("float", floatKwd);
	}
	
	void test_terminal_stringKwd(){
        testTerminal("string", stringKwd);
	} 
	
	void test_terminal_matrixKwd(){
        testTerminal("matrix", matrixKwd);
	}
	
	void test_terminal_letKwd(){
        testTerminal("let", letKwd);
	} 
	
	void test_terminal_inKwd(){
        testTerminal("in", inKwd);
	}
	
	void test_terminal_endKwd(){
        testTerminal("end", endKwd);
	} 
	
	void test_terminal_ifKwd(){
        testTerminal("if", ifKwd);
	}
	
	void test_terminal_thenKwd(){
        testTerminal("then", thenKwd);
	} 
	
	void test_terminal_elseKwd(){
        testTerminal("else", elseKwd);
	}
	
	void test_terminal_repeatKwd(){
        testTerminal("repeat", repeatKwd);
	} 
	
	void test_terminal_printKwd(){
        testTerminal("print", printKwd);
	}
	
	void test_terminal_toKwd(){
        testTerminal("to", toKwd);
	} 
	
	//constant terminal tests
	void test_terminal_intConst(){
        testTerminal("53", intConst);
	} 
	
	void test_terminal_floatConst(){
        testTerminal("16.52", floatConst);
	}
	
	void test_terminal_stringConst(){
        testTerminal("\"bits\"", stringConst);
	} 
	
	//name terminal test
	void test_terminal_variableName(){
        testTerminal("bar1", variableName);
	}
	
	//punctuation terminal tests
	void test_terminal_leftParen(){
        testTerminal("(", leftParen);
	} 
	
	void test_terminal_rightParen(){
        testTerminal(")", rightParen);
	}
	
	void test_terminal_leftCurly(){
        testTerminal("{", leftCurly);
	} 
	
	void test_terminal_rightCurly(){
        testTerminal("}", rightCurly);
	} 
	
	void test_terminal_leftSquare(){
        testTerminal("[", leftSquare);
	}
	
	void test_terminal_rightSquare(){
        testTerminal("]", rightSquare);
	} 
	
	void test_terminal_semiColon(){
        testTerminal(";", semiColon);
	} 
	
	void test_terminal_colon(){
        testTerminal(":", colon);
	}
	
	//operator terminal tests
	void test_terminal_assign(){
        testTerminal("=", assign);
	} 
	
	void test_terminal_plusSign(){
        testTerminal("+", plusSign);
	}
	
	void test_terminal_star(){
        testTerminal("*", star);
	} 
	
	void test_terminal_dash(){
        testTerminal("-", dash);
	} 
	
	void test_terminal_forwardSlash(){
        testTerminal("/", forwardSlash);
	}
	
	void test_terminal_lessThan(){
        testTerminal("<", lessThan);
	} 
	
	void test_terminal_lessThanEqual(){
        testTerminal("<=", lessThanEqual);
	} 
	
	void test_terminal_greaterThan(){
        testTerminal(">", greaterThan);
	}
	
	void test_terminal_greaterThanEqual(){
        testTerminal(">=", greaterThanEqual);
	} 
	
	void test_terminal_equalsEquals(){
        testTerminal("==", equalsEquals);
	} 
	
	void test_terminal_notEquals(){
        testTerminal("!=", notEquals);
	}
	
	void test_terminal_andOp(){
        testTerminal("&&", andOp);
	} 
	
	void test_terminal_orOp(){
        testTerminal("||", orOp);
	} 
	
	void test_terminal_notOp(){
        testTerminal("!", notOp);
	}
	
	//special terminal tests
	void test_terminal_endOfFile(){
        testTerminal(" ", endOfFile);
	} 
	
	void test_terminal_lexicalError(){
        testTerminal("@12", lexicalError);
	} 

    // Iteration 2 tests

    void test_terminal_boolKwd(){
        testTerminal("boolean", boolKwd);
    } 

    void test_terminal_trueKwd(){
        testTerminal("true", trueKwd);
    } 

    void test_terminal_falseKwd(){
        testTerminal("false", falseKwd);
    } 

    void test_terminal_whileKwd(){
        testTerminal("while", whileKwd);
    } 
      
} ;
