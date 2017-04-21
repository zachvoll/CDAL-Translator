/* A recursive descent parser with operator precedence.

   Note from Zach: They gave mostly skeleton code and had us fill it out.

   Author: Eric Van Wyk
   Modified: Robert Edge
   Modified: Kevin Thomsen
   Modified: Dan Challou
   Modified: Zachary Vollen

   This algorithm is based on the work of Douglas Crockford in "Top
   Down Operator Precedence", a chapter in the book "Beautiful Code".
   Mr. Crockford describes in his chapter how his work is based on an
   algorithm described Vaughan Pratt in "Top Down Operator
   Precedence", presented at the ACM Symposium on Principles of
   Programming Languages.

   Douglas Crockford's chapter is available at
    http://javascript.crockford.com/tdop/tdop.html

   Vaughan Pratt's paper is available at
    http://portal.acm.org/citation.cfm?id=512931

   These are both quite interesting works and worth reading if you
   find the problem of parsing to be an interesting one.

   Last modified: Oct 19, 2015.

*/

#include "AST.h"
#include "parser.h"
#include "scanner.h"
#include "extToken.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

using namespace std ;

/*
//Dynamic Casting Helper Method
void dynamicType(class c, ParseResult pr ){
    c *s = NULL;
    if(pr.ast){
        s = dynamic_cast<c *>(pr.ast);
        if(!s)throw((string)"Bad cast of state in parseProgram.");
    }
}*/

//Parser Deconstructor
Parser::~Parser() {
    if (s) delete s ;

    ExtToken *extTokenToDelete ;
    currToken = tokens ;
    while (currToken) {
        extTokenToDelete = currToken ;
        currToken = currToken->next ;
        delete extTokenToDelete ;
    }

    Token *tokenToDelete ;
    Token *currScannerToken = stokens ;
    while (currScannerToken) {
        tokenToDelete = currScannerToken ;
        currScannerToken = currScannerToken->next ;
        delete tokenToDelete ;
    }

}

/*!
 Basic constructor for Parser
 */
Parser::Parser ( ) {
    currToken = NULL; prevToken = NULL ; tokens = NULL;
    s = NULL; stokens = NULL;
}

/*!
  Parses a FCAL file
  \param text the characters to parse
 */
ParseResult Parser::parse (const char *text) {
    assert (text != NULL) ;

    ParseResult pr ;
    try {
        s = new Scanner() ;
        stokens = s->scan (text) ;
        tokens = extendTokenList ( this, stokens ) ;
        assert (tokens != NULL) ;
        currToken = tokens ;
        pr = parseProgram( ) ;
    }
    catch (string errMsg) {
        pr.ok = false ;
        pr.errors = errMsg ;
        pr.ast = NULL ;
    }
    return pr ;
}

/*
 * parse methods for non-terminal symbols
 * --------------------------------------
 */

/*! Parses the production Program ::= varName '(' ')' '{' Stmts '}' */
ParseResult Parser::parseProgram () {
    ParseResult pr ;
    ParseResult prStmts;
    // root
    // Program ::= varName '(' ')' '{' Stmts '}'
    match(variableName) ;
    string varName1( prevToken->lexeme ) ;
    match(leftParen) ;
    match(rightParen) ;
    match(leftCurly);

    prStmts = parseStmts() ;

    match(rightCurly);
    match(endOfFile) ;
    pr.ast = new Program(varName1, (Stmts*) prStmts.ast);
    return pr ;
}

//TODO fix?
/*! Parses either production
    Decl ::= 'matrix' varName '[' Expr ':' Expr ']' varName ':' varName  '=' Expr ';' or
    Decl ::= 'matrix' varName '=' Expr ';'

    This is identical to parseDecl, but handles special matrix syntax.
 */
ParseResult Parser::parseMatrixDecl () {
	int productionFlag = 0;
    ParseResult pr ;

    ParseResult expr1;
    ParseResult expr2;
    ParseResult expr3;

    ParseResult varName2;
    ParseResult varName3;

    match(matrixKwd);
    match(variableName) ;
    string varName1(prevToken->lexeme);

    // Decl ::= 'matrix' varName '[' Expr ':' Expr ']' varName ':' varName  '=' Expr ';'
    if(attemptMatch(leftSquare)){
        expr1 = parseExpr(0);
        match(colon);
        expr2 = parseExpr(0);
        match(rightSquare);
        varName2 = parseVariableName();
        match(colon);
        varName3 = parseVariableName();
        match(assign);
        expr3 = parseExpr(0);
    }
    // Decl ::= 'matrix' varName '=' Expr ';'
    else if(attemptMatch(assign)){
        //parseExpr(0);
        productionFlag = 1;
        expr1 = parseExpr(0);
    }
    else{
        throw ( (string) "Bad Syntax of Matrix Decl in in parseMatrixDecl" ) ;
    }

    if(productionFlag == 0){
        pr.ast = new MatrixBrackDecl(varName1, (Expr*)expr1.ast, (Expr*)expr2.ast, (Expr*)varName2.ast, (Expr*)varName3.ast, (Expr*)expr3.ast);
    }
    else if(productionFlag == 1){
       pr.ast = new MatrixDecl(varName1, (Expr*)expr1.ast);
    }

    return pr ;
}

/*! Parses the productions
Decl ::= integerKwd varName ';' | floatKwd varName ';' | stringKwd varName ';' | boolean varName ';'
*/
ParseResult Parser::parseStandardDecl(){
    ParseResult pr ;

    if ( attemptMatch(intKwd) ) {
        // Type ::= intKwd
        match(variableName) ;
        string varName(prevToken->lexeme);
        pr.ast = new IntDecl(varName);
    }
    else if ( attemptMatch(floatKwd) ) {
        // Type ::= floatKwd
        match(variableName) ;
        string varName(prevToken->lexeme);
        pr.ast = new FloatDecl(varName);
    }
    else if ( attemptMatch(stringKwd) ) {
        // Type ::= stringKwd
        match(variableName) ;
        string varName(prevToken->lexeme);
        pr.ast = new StringDecl(varName);
    }
    else if ( attemptMatch(boolKwd) ) {
        // Type ::= boolKwd
        match(variableName) ;
        string varName(prevToken->lexeme);
        pr.ast = new BooleanDecl(varName);
    }

    match(semiColon) ;

    return pr ;
}

/*!
 Parses either production
 Decl ::= 'matrix' varName '[' Expr ':' Expr ']' varName ':' varName '=' Expr ';'
 |Decl ::= Type variableName ';'
*/
ParseResult Parser::parseDecl () {
    ParseResult pr ;
    // Decl :: matrix variableName ....
    if(nextIs(matrixKwd)){
        pr = parseMatrixDecl();
    }
    // Decl ::= Type variableName semiColon
    else{
        pr = parseStandardDecl();
    }

    //ast
    return pr ;
}

/*! Stmts
 Parses the production
 Stmts ::= Stmt Stmts
 | Stmts ::= <<empty>>
*/
ParseResult Parser::parseStmts () {
    ParseResult pr ;
    if ( ! nextIs(rightCurly) && !nextIs(inKwd)  ) {
        // Stmts ::= Stmt Stmts
        ParseResult prStmt = parseStmt() ;
        ParseResult prStmts = parseStmts() ;
        pr.ast = new StmtStmts((Stmt*)prStmt.ast, (Stmts*)prStmts.ast);
    }
    else {
        // Stmts ::=
        pr.ast = new EmptyStmts();
    }

    return pr ;
}

/*!
 Parses the productions
 Stmt ::= Decl
 Stmt ::= '{' Stmts '}'
 Stmt ::= 'if' '(' Expr ')' Stmt
 Stmt ::= 'if' '(' Expr ')' Stmt 'else' Stmt
 Stmt ::= varName '=' Expr ';'  | varName '[' Expr ':' Expr ']' '=' Expr ';'
 Stmt ::= 'print' '(' Expr ')' ';'
 Stmt ::= 'repeat' '(' varName '=' Expr 'to' Expr ')' Stmt
 Stmt ::= 'while' '(' Expr ')' Stmt
 Stmt ::= ';'
*/
ParseResult Parser::parseStmt () {
    ParseResult pr ;

    ParseResult stmts;

    ParseResult stmt1;
    ParseResult stmt2;

    ParseResult expr1;
    ParseResult expr2;
    ParseResult expr3;

    //Stmt ::= Decl
    if(nextIs(intKwd)||nextIs(floatKwd)||nextIs(matrixKwd)||nextIs(stringKwd)||nextIs(boolKwd)){
        pr = parseDecl();
    }
    //Stmt ::= '{' Stmts '}'
    else if (attemptMatch(leftCurly)){
        stmts = parseStmts() ;
        match(rightCurly);
        pr.ast = new StmtsStmt((Stmts*) stmts.ast);

    }
    //Stmt ::= 'if' '(' Expr ')' Stmt
    //Stmt ::= 'if' '(' Expr ')' Stmt 'else' Stmt
    else if (attemptMatch(ifKwd)){
        match(leftParen);
        expr1 = parseExpr(0);
        match(rightParen);
        stmt1 = parseStmt();

        if(attemptMatch(elseKwd)){
            stmt2 = parseStmt();
            pr.ast = new IfElseStmt((Expr*) expr1.ast, (Stmt*) stmt1.ast, (Stmt*) stmt2.ast);
        }
        else{
            pr.ast = new IfStmt((Expr*) expr1.ast, (Stmt*) stmt1.ast);
        }

    }
    //Stmt ::= varName '=' Expr ';'  | varName '[' Expr ':' Expr ']' '=' Expr ';'
    else if  ( attemptMatch (variableName) ) {
        string varName1(prevToken->lexeme);

        if (attemptMatch ( leftSquare ) ) {

              expr1 = parseExpr(0);
              match ( colon ) ;
              expr2 = parseExpr (0) ;
              match  ( rightSquare ) ;

              match(assign);
              expr3 = parseExpr(0);
              match(semiColon);
              pr.ast = new VarExprLongStmt(varName1, (Expr*) expr1.ast, (Expr*) expr2.ast, (Expr*) expr3.ast);
        }
        else{
            match(assign);
            expr1 = parseExpr(0);
            match(semiColon);
            pr.ast = new VarExprShortStmt(varName1, (Expr*) expr1.ast);
        }

    }
    //Stmt ::= 'print' '(' Expr ')' ';'
    else if ( attemptMatch (printKwd) ) {
        match (leftParen) ;
        expr1 = parseExpr(0);
        match (rightParen) ;
        match (semiColon) ;
        pr.ast = new PrintStmt((Expr*) expr1.ast);
    }
    //Stmt ::= 'repeat' '(' varName '=' Expr 'to' Expr ')' Stmt
    else if ( attemptMatch (repeatKwd) ) {
        match (leftParen) ;
        match (variableName) ;
        string varName1(prevToken->lexeme);
        match (assign) ;
        expr1 = parseExpr (0) ;
        match (toKwd) ;
        expr2 = parseExpr (0) ;
        match (rightParen) ;
        stmt1 = parseStmt () ;
        pr.ast = new RepeatStmt(varName1, (Expr*) expr1.ast, (Expr*) expr2.ast, (Stmt*) stmt1.ast);
    }
    //Stmt ::= 'while' '(' Expr ')' Stmt
    else if (attemptMatch(whileKwd)) {
        match(leftParen);
        expr1 = parseExpr(0);
        match(rightParen);
        stmt1 = parseStmt();
        pr.ast = new WhileStmt((Expr*) expr1.ast, (Stmt*) stmt1.ast);
    }
    //Stmt ::= ';'
    else if ( attemptMatch (semiColon) ) {
        // parsed a skip
        pr.ast = new SemiColonStmt();
    }
    else{
        throw ( makeErrorMsg ( currToken->terminal ) + " while parsing a statement" ) ;
    }

    return pr ;
}

/*!
 Look at current token, without consuming it,
 and call its associated parse method.
*/
ParseResult Parser::parseExpr (int rbp) {
    /* Examine current token, without consuming it, to call its
       associated parse methods.  The ExtToken objects have 'nud' and
       'led' methods that are dispatchers that call the appropriate
       parse methods.*/
    ParseResult left = currToken->nud() ;

    while (rbp < currToken->lbp() ) {
        left = currToken->led(left) ;
    }

    return left ;
}

/*
 * parse methods for Expr productions
 * ----------------------------------
 */

 /*!
 Parses the production Expr ::= trueKwd
 */
 ParseResult Parser::parseTrueKwd ( ) {
     ParseResult pr ;
     match ( trueKwd ) ;

     string constVal(prevToken->lexeme);
     pr.ast = new ConstExpr(constVal);
     return pr ;
 }

 /*!
 Parses the production Expr ::= falseKwd
 */
 ParseResult Parser::parseFalseKwd ( ) {
     ParseResult pr ;
     match ( falseKwd ) ;

     string constVal(prevToken->lexeme);
     pr.ast = new ConstExpr(constVal);
     return pr ;
 }

/*!
Parses the production Expr ::= intConst
*/
ParseResult Parser::parseIntConst ( ) {
    ParseResult pr ;
    match ( intConst ) ;

    //ast
    string constVal(prevToken->lexeme);
    pr.ast = new ConstExpr(constVal);
    return pr ;
}

/*!
Parses the production Expr ::= floatConst
*/
ParseResult Parser::parseFloatConst ( ) {
    ParseResult pr ;
    match ( floatConst ) ;

    //ast
    string constVal(prevToken->lexeme);
    pr.ast = new ConstExpr(constVal);
    return pr ;
}

/*!
 Parses the production Expr ::= stringConst
*/
ParseResult Parser::parseStringConst ( ) {
    ParseResult pr ;
    match ( stringConst ) ;

    //ast
    string constVal(prevToken->lexeme);
    pr.ast = new ConstExpr(constVal);
    return pr ;
}

/*!
 Parses the productions:
 Expr ::= varName '[' Expr ':' Expr ']'
 Expr ::= varName '(' Expr ')'
 Expr := varName
*/
ParseResult Parser::parseVariableName ( ) {
    ParseResult pr ;

    ParseResult expr1;
    ParseResult expr2;

    match(variableName);
    string varName1(prevToken->lexeme);

    if(attemptMatch(leftSquare)){
        expr1 = parseExpr(0);
        match(colon);
        expr2 = parseExpr(0);
        match(rightSquare);
        pr.ast = new MatrixRefExpr(varName1, (Expr*) expr1.ast, (Expr*) expr2.ast);
    }
    //Expr ::= varableName '(' Expr ')'  //NestedOrFunctionCall
    else if(attemptMatch(leftParen)){
        expr1 = parseExpr(0);
        match(rightParen);
        pr.ast = new VarParenExpr(varName1, (Expr*) expr1.ast);
    }
    //Expr := variableName
    else{
        pr.ast = new ConstExpr(varName1);
    }

    return pr ;
}

/*!
 Parses the production Expr ::= '(' Expr ')'
*/
ParseResult Parser::parseNestedExpr ( ) {
    ParseResult pr ;
    ParseResult expr1;

    match ( leftParen ) ;
    expr1 = parseExpr(0) ;
    match(rightParen) ;

    //ast
    pr.ast = new ParenExpr((Expr*)expr1.ast);
    return pr ;
}

/*!
 Parses the production Expr ::= 'if' Expr 'then' Expr 'else' Expr
*/
ParseResult Parser::parseIfExpr(){
    ParseResult pr ;
    ParseResult expr1;
    ParseResult expr2;
    ParseResult expr3;

    match(ifKwd);
    expr1 = parseExpr(0);
    match(thenKwd);
    expr2 = parseExpr(0);
    match(elseKwd);
    expr3 = parseExpr(0);

	  //ast
    pr.ast = new IfExpr((Expr*)expr1.ast, (Expr*)expr2.ast, (Expr*)expr3.ast);
    return pr;
}

/*!
 Parses the production Expr ::= 'let' Stmts 'in' Expr 'end'
*/
ParseResult Parser::parseLetExpr(){
   ParseResult pr ;
   ParseResult stmts;
   ParseResult expr1;

   match(letKwd);
   stmts = parseStmts();
   match(inKwd);
   expr1 = parseExpr(0);
   match(endKwd);

   //ast
   pr.ast = new LetExpr((Stmts*)stmts.ast, (Expr*)expr1.ast);
   return pr;
}

/*!
 Parses the production Expr ::= '!' Expr
*/
ParseResult Parser::parseNotExpr () {
    ParseResult pr ;
    ParseResult expr1;

    match ( notOp ) ;
    expr1 = parseExpr( 0 );

    //ast
    pr.ast = new NotExpr((Expr*)expr1.ast);
    return pr ;
}

/*!
Parses the production Expr ::= Expr '+' Expr
*/
ParseResult Parser::parseAddition ( ParseResult prLeft ) {
    // parser has already matched left expression
    ParseResult pr ;
    ParseResult expr1;

    match ( plusSign ) ;
    expr1 = parseExpr( currToken->lbp() );

    //ast
    pr.ast = new AddExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    return pr ;
}

/*!
Parses the production Expr ::= Expr '*' Expr
*/
ParseResult Parser::parseMultiplication ( ParseResult prLeft ) {
    // parser has already matched left expression
    ParseResult pr ;
    ParseResult expr1;

    match ( star ) ;
    expr1 = parseExpr( currToken->lbp() );

    //ast
    pr.ast = new MulExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    return pr ;
}

/*!
 Parses the production Expr ::= Expr '-' Expr
*/
ParseResult Parser::parseSubtraction ( ParseResult prLeft ) {
    // parser has already matched left expression
    ParseResult pr ;
    ParseResult expr1;

    match ( dash ) ;
    expr1 = parseExpr( currToken->lbp() );

    //ast
    pr.ast = new SubExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    return pr ;
}

/*!
 Parses the production Expr ::= Expr '/' Expr
*/
ParseResult Parser::parseDivision ( ParseResult prLeft ) {
    // parser has already matched left expression
    ParseResult pr ;
    ParseResult expr1;

    match ( forwardSlash ) ;
    expr1 = parseExpr( currToken->lbp() );

    //ast
    pr.ast = new DivExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    return pr ;
}


/* Notice that for relational operators we use just one parse
   function.  This shows another possible means for implementing
   expressions, as opposed to the method used for arithmetic
   expressions in which each operation has its own parse method.  It
   will depend on what we do in iteration 3 in building an abstract
   syntax tree to decide which method is better.
 */
/*!
  Parses all relational operators:
  Expr ::= Expr 'equalEquals '==' Expr
  Expr ::= Expr lessThanEquals Expr
  Expr ::= Expr greaterThanEquals Expr
  Expr ::= Expr notEquals Expr
  Expr ::= Expr leftAngle Expr
  Expr ::= Expr rightAngle Expr
*/
ParseResult Parser::parseRelationalExpr ( ParseResult prLeft ) {
    // parser has already matched left expression
    ParseResult pr ;
    ParseResult expr1;

    nextToken( ) ;
    // just advance token, since examining it in parseExpr caused
    // this method being called.
    string op = prevToken->lexeme ;
    expr1 = parseExpr( prevToken->lbp() );

    //ast
    if(op == ">"){
        pr.ast = new GreatExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    }
    else if(op == ">="){
         pr.ast = new GreatEqExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    }
    else if(op == "<"){
         pr.ast = new LessExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    }
    else if(op == "<="){
         pr.ast = new LessEqExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    }
    else if(op == "=="){
         pr.ast = new EqEqExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    }
    else if(op == "!="){
         pr.ast = new NotEqExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    }
    else if(op == "&&"){
         pr.ast = new AndExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    }
    else if(op == "||"){
         pr.ast = new OrExpr((Expr*)prLeft.ast, (Expr*)expr1.ast);
    }

    return pr ;
}

// Helper functions used by the parser.

/*!
 Helper function used by the parser.
 \param tt tokenType to match
*/
void Parser::match (tokenType tt) {
    if (! attemptMatch(tt)) {
        throw ( makeErrorMsgExpected ( tt ) ) ;
    }
}

/*!
 Attempts to match a token depending on its tokenType.
 \param tt tokenType to match
*/
bool Parser::attemptMatch (tokenType tt) {
    if (currToken->terminal == tt) {
        nextToken() ;
        return true ;
    }
    return false ;
}

/*!
 Returns true if the current token has the same token type as tt
 \param tt tokenType to check
*/
bool Parser::nextIs (tokenType tt) {
    return currToken->terminal == tt ;
}

/*!
 Gets the next token in the list.
*/
void Parser::nextToken () {
    if ( currToken == NULL )
        throw ( string("Internal Error: should not call nextToken in unitialized state"));
    else
    if (currToken->terminal == endOfFile && currToken->next == NULL) {
        prevToken = currToken ;
    } else if (currToken->terminal != endOfFile && currToken->next == NULL) {
        throw ( makeErrorMsg ( "Error: tokens end with endOfFile" ) ) ;
    } else {
        prevToken = currToken ;
        currToken = currToken->next ;
    }
}

/*!
 Returns the description of the terminal passed in.
 \param terminal token type to get description of
*/
string Parser::terminalDescription ( tokenType terminal ) {
    Token *dummyToken = new Token ("",terminal, NULL) ;
    ExtToken *dummyExtToken = extendToken (this, dummyToken) ;
    string s = dummyExtToken->description() ;
    delete dummyToken ;
    delete dummyExtToken ;
    return s ;
}

/*!
 Returns 'expected' error message for terminal passed in.
 \param terminal token type to create error message for
*/
string Parser::makeErrorMsgExpected ( tokenType terminal ) {
    string s = (string) "Expected " + terminalDescription (terminal) +
        " but found " + currToken->description() ;
    return s ;
}

/*!
 Returns error message for terminal passed in.
 \param terminal token type to create error message for
*/
string Parser::makeErrorMsg ( tokenType terminal ) {
    string s = "Unexpected symbol " + terminalDescription (terminal) ;
    return s ;
}

/*!
 Creates custom error message.
 \param msg message to present as error
*/
string Parser::makeErrorMsg ( const char *msg ) {
    return msg ;
}
