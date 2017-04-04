#include <cxxtest/TestSuite.h>
#include <iostream>
#include "parser.h"
#include "readInput.h"

#include <stdlib.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std ;

class CodeGenTestSuite : public CxxTest::TestSuite
{
public:

    Parser p ;
    ParseResult pr ;

    char **makeArgs ( const char *a0, const char *a1) {
        char **aa = (char **) malloc (sizeof(char *) * 2) ;
        aa[0] = (char *) malloc ( sizeof(char) * (strlen(a0) + 1) ) ;
        strcpy (aa[0], a0 ) ;
        aa[1] = (char *) malloc ( sizeof(char) * (strlen(a1) + 1) ) ;
        strcpy (aa[1], a1 ) ;
        return aa ;
    }

    void writeFile ( const string text, const string filename ) {
        ofstream out(filename.c_str());
        out << (string) text << endl ;
    }

    char *readFile ( const char *fn ) {
        return readInput (2, makeArgs("translator", fn) ) ;
    }

    void codegen_tests ( string filebase, bool checkExpected ) {
        string file = filebase + ".dsl" ;
        string path = "../samples/" + file ;
        string cppbase =  "../samples/" + filebase ;
        string cppfile =  cppbase + ".cpp" ;
        string cppexec =  cppbase ;
        string cppout = cppbase + ".output" ;
        string expected = cppbase + ".expected" ;
        string diffout = cppbase + ".diff" ;

        int rc = 0 ;

        // 1. Test that the file can be parsed.
        ParseResult pr1 = p.parse (
            readInput (2, makeArgs("translator", path.c_str() ) )
          ) ;
        TSM_ASSERT ( file + " failed to parse.", pr1.ok ) ;

        // 2. Verify that the ast field is not null
        TSM_ASSERT ( file + " failed to generate an AST.", pr1.ast != NULL );

        // 3. Verify that the C++ code is non-empty.
        string cpp1 = pr1.ast->cppCode() ;
        TSM_ASSERT ( file + " failed to generate non-empty C++ code.",
                     cpp1.length() > 0 ) ;

        writeFile ( cpp1, cppfile ) ;

        // 4. Compile generated C++ file
        string compile = "g++ ../samples/Matrix.cpp " + cppfile +
                         " -o " + cppexec ;
        rc = system ( compile.c_str() ) ;
        TSM_ASSERT_EQUALS ( "translation of " + file +
                            " failed to compile.", rc, 0 ) ;

        string cleanup = "rm -f " + cppout ;
        system ( cleanup.c_str() ) ;

        // 5. Run the generated code.
        string run = cppexec + " > " + cppout ;
        rc = system ( run.c_str() ) ;
        TSM_ASSERT_EQUALS ( "translation of " + file +
                            " executed without errors.", rc, 0 ) ;

        // 6. Check for correct output.
        if ( checkExpected ) {
            string diff = "diff " + cppout + " " + expected + " > " + diffout ;
            rc = system ( diff.c_str() ) ;
            TSM_ASSERT_EQUALS ( "translation of " + file +
                                " did not produce expected output.", rc, 0 ) ;
        }
    }

    //TODO run the other tests
    /*! test_sample_1 passed 12/11/15 */
    void test_sample_1 ( void ) { codegen_tests ( "sample_1", true ); }
    /*! test_sample_2 passed 12/11/15 */
    void test_sample_2 ( void ) { codegen_tests ( "sample_2", true ); }
    /*! test_sample_3 passed 12/11/15 */
    void test_sample_3 ( void ) { codegen_tests ( "sample_3", true ); }
    //A matrix test
    /*! test_sample_7 passed 12/11/15 */
    void test_sample_7 ( void ) { codegen_tests ( "sample_7", true ); }
    /*! test_sample_8 passed ?*/
    void test_sample_8 ( void ) { codegen_tests ( "sample_8", true ); }

    /* You should create .expected files in ../samples for these with the expected
     * output of the two CDAL programs you create. You can then change the second argument to true to
     * validate them after you get the translation working . */

    /*! test_your_code_1 passed ? */
    void test_your_code_1 ( void ) { codegen_tests ( "my_code_1", true ) ; }
    /*! test_your_code_2 passed 12/12/15 */
    void test_your_code_2 ( void ) { codegen_tests ( "my_code_2", true ) ; }
    /*! test_forest_loss passed ? */
    void test_forest_loss ( void ) { codegen_tests ( "forest_loss_v2", true ); }
} ;
