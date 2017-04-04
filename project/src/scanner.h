/* A small meaningless comment. */
#ifndef SCANNER_H
#define SCANNER_H

#include <regex.h>
#include <string>

using namespace std;
 
class Token;
class Scanner;

/* This enumerated type is used to keep track of what kind of
   construct was matched. 
 */

enum tokenEnumType { 
	
	// Keywords (17)
	intKwd, floatKwd, boolKwd,
	trueKwd, falseKwd, stringKwd,  matrixKwd,
	letKwd, inKwd, endKwd, ifKwd, thenKwd, elseKwd,
	repeatKwd, whileKwd, printKwd, toKwd,


	// Constants (3)
	intConst, floatConst, stringConst, 

	// Names (1)
	variableName ,

	// Punctuation (8)
	leftParen, rightParen, 
	leftCurly, rightCurly, 
	leftSquare, rightSquare,
	semiColon, colon,

	//Operators (14)
	assign, 
	plusSign, star, dash, forwardSlash,
	lessThan, lessThanEqual, greaterThan, greaterThanEqual,
	equalsEquals, notEquals,
	andOp, orOp, notOp,

	// Special terminal types (2)
	endOfFile ,
	lexicalError
	
};

typedef enum tokenEnumType tokenType ;

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
		Token *scan (regex_t** array, const char *text);
		regex_t** makeRegexArray(void);
		void printTokens(Token* head);
}; 	

int consumeWhiteSpaceAndComments (regex_t *whiteSpace, 
                                  regex_t *blockComment, regex_t *lineComment,
                                  const char *text);	
#endif /* SCANNER_H */
