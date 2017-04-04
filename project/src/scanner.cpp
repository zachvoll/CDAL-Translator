#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <regex.h>
#include "regex.h"
#include "scanner.h"
#include <string>

using namespace std;

//Constructors
Token::Token (tokenType x, string y){
	terminal = x;
	lexeme = y;
	next = NULL;
}

Token::Token (tokenType x, string y, Token *token){
	terminal = x;
	lexeme = y;
	next = token;
}

Token::Token (string y, tokenType x, Token *token){
	terminal = x;
	lexeme = y;
	next = token;
}

//Destructor
Token::~Token(){}
	
/* Scan characters and create a list of Tokens
 * parameter: text : characters to tokenize 
 * returns: linked-list of tokens
 */
Token* Scanner::scan (const char *text){
	
	//initializing token list
	Token* head = NULL;
	Token* tail = NULL;
	
	//regular expressions for consumeWhiteSpaceAndComments
	regex_t whiteSpace = *makeRegex ("^[\n\t\r ]+");
    regex_t blockComment = *makeRegex ("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
    regex_t lineComment = *makeRegex ("^//[^\n\r]*");
	
	int numMatchedChars = 0;
	int maxNumMatchedChars = 0;
		
	numMatchedChars = consumeWhiteSpaceAndComments (&whiteSpace, &blockComment, &lineComment, text);
	text = text+numMatchedChars;
	
	regex_t** array = Scanner::makeRegexArray();
	//goes through the characters in text array
	while (text[0] != '\0'){ 
		 
		 maxNumMatchedChars = 0;
		 tokenType terminal = lexicalError; 
		 //this for loop matches the string with the terminal types in the array of types
		 int i;
		 for(i = 0; i < 45; i++){
			 
			numMatchedChars = matchRegex(array[i], text);
			
			if(numMatchedChars > maxNumMatchedChars){
					maxNumMatchedChars = numMatchedChars;
					terminal = tokenType(i);
			}
		 }
		 
		//get substring
		string lex = "";
		lex += text[0];
		for (int j = 1; j < maxNumMatchedChars; j++){
			lex += text[j];			
		}
		
		//adding token
		if (head == NULL){ 
			head= new Token(terminal, lex);
			tail = head;
		} 
		else{
			tail->next = new Token(terminal, lex);
			tail = tail->next;     
		}
				
		//update text offset
		if(maxNumMatchedChars == 0){
			text = text + 1;
		}
		else{
		text = text + maxNumMatchedChars;
		}
		numMatchedChars = consumeWhiteSpaceAndComments(&whiteSpace, &blockComment, &lineComment, text);
		text = text + numMatchedChars;		 				
	}
	 
	//adding EOF token
	if (head == NULL){ 
		head= new Token(endOfFile, "");
		tail = head;
	} 
	else{
		tail->next = new Token(endOfFile, "");
		tail = tail->next;     
	}

	return head;
}

//extra Scanner to take in the regexArray so we don't need to call makeRegexArray every single time we call scan
Token* Scanner::scan (regex_t** array, const char *text){
	
	//initializing token list
	Token* head = NULL;
	Token* tail = NULL;
	
	//regular expressions for consumeWhiteSpaceAndComments
	regex_t whiteSpace = *makeRegex ("^[\n\t\r ]+");
    regex_t blockComment = *makeRegex ("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
    regex_t lineComment = *makeRegex ("^//[^\n\r]*"); //don't need to escape first two characters
	
	int numMatchedChars = 0;
	int maxNumMatchedChars = 0;
		
	numMatchedChars = consumeWhiteSpaceAndComments (&whiteSpace, &blockComment, &lineComment, text);
	text = text+numMatchedChars;
	
	//goes through the characters in text array
	while (text[0] != '\0'){ 
		 
		 maxNumMatchedChars = 0;
		 tokenType terminal = lexicalError; 
		 //this for loop matches the string with the terminal types in the array of types
		 int i;
		 for(i = 0; i < 45; i++){
			 
			numMatchedChars = matchRegex(array[i], text);
			
			if(numMatchedChars > maxNumMatchedChars){
					maxNumMatchedChars = numMatchedChars;
					terminal = tokenType(i);
			}
		 }
		 
		//get substring
		string lex = "";
		lex += text[0];
		for (int j = 1; j < maxNumMatchedChars; j++){
			lex += text[j];
			
		}
		
		//adding token
		if (head == NULL){ 
			head= new Token(terminal, lex);
			tail = head;
		} 
		else{
			tail->next = new Token(terminal, lex);
			tail = tail->next;     
		}
				
		//update text offset
		if(maxNumMatchedChars == 0){
			text = text + 1;
		}
		else{
		text = text + maxNumMatchedChars;
		}
		numMatchedChars = consumeWhiteSpaceAndComments(&whiteSpace, &blockComment, &lineComment, text);
		text = text + numMatchedChars;		 				
	}
	 
	//adding EOF token
	if (head == NULL){ 
		head= new Token(endOfFile, "");
		tail = head;
	} 
	else{
		tail->next = new Token(endOfFile, "");
		tail = tail->next;     
	}

	return head;
}

//returns an array of regular expressions to be used by the scanner 
regex_t**  Scanner::makeRegexArray(void){

	regex_t** array = new regex_t* [44];

	//keywords	
	array[intKwd] = makeRegex("^int"); 
	array[floatKwd] = makeRegex("^float");
	array[boolKwd] = makeRegex("^boolean");
	array[trueKwd] = makeRegex("^true");
	array[falseKwd] = makeRegex("^false");
	array[stringKwd] = makeRegex("^string");
	array[matrixKwd] = makeRegex("^matrix");
	array[letKwd] = makeRegex("^let");
	array[inKwd] = makeRegex("^in");
	array[endKwd] = makeRegex("^end");
	array[ifKwd] = makeRegex("^if");
	array[thenKwd] = makeRegex("^then");
	array[elseKwd] = makeRegex("^else");
	array[repeatKwd] = makeRegex("^repeat");
	array[whileKwd] = makeRegex ("^while");
	array[printKwd] = makeRegex("^print");
	array[toKwd] = makeRegex("^to");

	//constants
    array[intConst] = makeRegex("^[0-9]+");
	array[floatConst] = makeRegex("^(\\-?)[0-9]+\\.[0-9]+");
	array[stringConst] = makeRegex("^\"[^\"\r\n]*\""); 

	//names
	array[variableName] = makeRegex("^[a-zA-Z]+[a-zA-Z0-9_]*"); 
	/*
	 * This is causing trouble in the test case with sample_4. it is matching 'mj]' 
	 * as a var name if we remove '\\-' from this regex, then it won't have this issue, 
	 * however, the TA verified that it shouldn't have this issue with the current way it's written. No idea why it's fucked.
	 */

	//punctuation
	array[leftParen] = makeRegex("^\\(");
	array[rightParen] = makeRegex("^\\)");
	array[leftCurly] = makeRegex("^\\{");
	array[rightCurly] = makeRegex("^\\}");
	array[leftSquare] = makeRegex("^\\[");
	array[rightSquare] = makeRegex("^\\]");
	array[semiColon] = makeRegex("^;");
	array[colon] = makeRegex("^:");

	//operators
	array[assign] = makeRegex("^=");
	array[plusSign] = makeRegex("^\\+");
	array[star] = makeRegex("^\\*");
	array[dash] = makeRegex("^\\-");
	array[forwardSlash] = makeRegex("^/");
	array[lessThan] = makeRegex("^<");
	array[lessThanEqual] = makeRegex("^<=");
	array[greaterThan] = makeRegex("^>");
	array[greaterThanEqual] = makeRegex("^>=");
	array[equalsEquals] = makeRegex("^==");
	array[notEquals] = makeRegex("^!=");
	array[andOp] = makeRegex("^&&");
	array[orOp] = makeRegex("^\\|\\|");
	array[notOp] = makeRegex("^!");
	
	/* Special terminal types (create dummy regexes in case the special 
	 * terminal types are moved to different spot in the tokenType enumeration)
	 */
	array[endOfFile] = makeRegex(""); 
	array[lexicalError] = makeRegex(""); 
	

	return array;    
}

//prints all tokens to a file, primarily used for debugging
void Scanner::printTokens(Token* head){
	while(head != NULL){
		//string tokentype = string(itoa(head->terminal));
		string lexeme = head->lexeme;
		cout << lexeme << endl;
		head = head->next;
	}
}

//returns int offset to ignore whiteSpace and Comments
int consumeWhiteSpaceAndComments (regex_t *whiteSpace, 
                                  regex_t *blockComment, regex_t *lineComment,
                                  const char *text) {
    int numMatchedChars = 0 ;
    int totalNumMatchedChars = 0 ;
    int stillConsumingWhiteSpace ;

    do {
        stillConsumingWhiteSpace = 0 ;  // exit loop if not reset by a match

        // Try to match white space
        numMatchedChars = matchRegex (whiteSpace, text) ;
        totalNumMatchedChars += numMatchedChars ;
        if (numMatchedChars > 0) {
            text = text + numMatchedChars ;
            stillConsumingWhiteSpace = 1 ;
        }

        // Try to match block comments
        numMatchedChars = matchRegex (blockComment, text) ;
        totalNumMatchedChars += numMatchedChars ;
        if (numMatchedChars > 0) {
            text = text + numMatchedChars ;
            stillConsumingWhiteSpace = 1 ;
        }

        // Try to match line comments
        numMatchedChars = matchRegex (lineComment, text) ;
        totalNumMatchedChars += numMatchedChars ;
        if (numMatchedChars > 0) {
            text = text + numMatchedChars ;
            stillConsumingWhiteSpace = 1 ;
        }

    }
    while ( stillConsumingWhiteSpace ) ;    

    return totalNumMatchedChars ;
}
