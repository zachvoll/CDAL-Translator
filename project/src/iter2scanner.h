/* A small meaningless comment */
#ifndef SCANNER_H
#define SCANNER_H

#include <regex.h>
#include <string>

class Token ;
class Scanner ;

/* This enumerated type is used to keep track of what kind of
   construct was matched. 
 */
enum tokenEnumType { 

    intKwd, floatKwd, boolKwd,
    trueKwd, falseKwd, stringKwd,  matrixKwd,
    letKwd, inKwd, endKwd, ifKwd, thenKwd, elseKwd,
    repeatKwd, whileKwd, printKwd, toKwd,

    // Constants
    intConst, floatConst, stringConst, 

    // Names
    variableName ,

    // Punctuation
    leftParen, rightParen, 
    leftCurly, rightCurly, 
    leftSquare, rightSquare,
    semiColon, colon,

    //Operators
    assign, 
    plusSign, star, dash, forwardSlash,
    lessThan, lessThanEqual, greaterThan, greaterThanEqual,
    equalsEquals, notEquals,
    andOp, orOp, notOp,

    // Special terminal types
    endOfFile,
    lexicalError
} ;

typedef enum tokenEnumType tokenType ;

// Below you need to write your class definitions for Token and Scanner.

// Class definiton Token
class Token {
	public:
		//field names
		tokenType terminal;
		string lexeme;
		Token *next;

		// Constructor and Destructor
		Token();
		Token(tokenType, string);
		Token(tokenType, string, Token *);
		Token(string, tokenType, Token *);
		~Token();		
}; 
	
// Class definition Scanner
class Scanner {
	public:
		Token *scan (const char *);
		regex_t** makeRegexArray(void);
}; 	

int consumeWhiteSpaceAndComments (regex_t *whiteSpace, 
                                  regex_t *blockComment, regex_t *lineComment,
                                  const char *text);

#endif /* SCANNER_H */
