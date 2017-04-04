#ifndef Node_H
#define Node_H

#include <string>
#include <iostream> 
#include "scanner.h"

using namespace std;

/*****************
Class Declarations
*****************/

class Node;
class AProgram;
class Stmts;
class Stmt;
class Decl;
class Expr;

class Program;

class EmptyStmts;
class StmtStmts;

class DeclStmt;

class IfStmt;
class IfElseStmt;
class VarExprShortStmt;
class VarExprLongStmt;
class PrintStmt;
class RepeatStmt;
class WhileStmt;
class SemiColonStmt;

/*
A small amount of skeleton code given; the rest was written by Zachary Vollen.

*/

class IntDecl;
class FloatDecl;
class StringDecl;
class BooleanDecl;
class MatrixBrackDecl;
class MatrixDecl;

class ConstExpr;

class MulExpr;
class DivExpr;
class AddExpr;
class SubExpr;

class GreatExpr;
class GreatEqExpr;
class LessExpr;
class LessEqExpr;
class EqEqExpr;
class NotEqExpr;

class AndExpr;
class OrExpr;
class NotExpr;

class MatrixRefExpr;
class VarParenExpr;
class ParenExpr;
class LetExpr;
class IfExpr;

/***************
Abstract Classes
***************/

/*! 
 Abstract Virtual Class that all of the abstract classes inherit from
*/
class Node {
	public:
		virtual string unparse() = 0;
		virtual string cppCode() = 0;
		virtual ~Node() { }	
} ;

/*! 
 Abstract Class for the nonterminal Program
*/
class AProgram: public Node {};

/*! 
 Abstract Class for the nonterminal Stmts
*/
class Stmts: public Node {};

/*! 
 Abstract Class for the nonterminal Stmt
*/
class Stmt: public Node {};

/*! 
 Abstract Class for the nonterminal Decl
*/
class Decl: public Node {};

/*! 
 Abstract Class for the nonterminal Expr
*/
class Expr: public Node {};


/*****************
Program production
*****************/

/*! 
 Class for the production Program ::= varName '(' ')' '{' Stmts '}'
*/  
class Program: public AProgram {
	public:
		string varName;
		Stmts* stmts;

		Program(string varName, Stmts* stmts);
		string unparse();
		string cppCode();
};

/****************
Stmts productions
****************/

/*!
Class for the production Stmts ::= <<empty>>
*/
class EmptyStmts: public Stmts {
	public:
				
		EmptyStmts();
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmts ::= Stmt Stmts
*/
class StmtStmts: public Stmts {
	public:
		Stmt* stmt;
		Stmts* stmts;

		StmtStmts(Stmt* stmt, Stmts* stmts);
		string unparse();
		string cppCode();
};

/***************
Stmt productions
***************/

/*!
Class for the production Stmt ::= Decl
*/
class DeclStmt: public Stmt {
	public:
		Decl* decl;

		DeclStmt(Decl* decl);
		string unparse();
		string cppCode();
};


/*!
Class for the production Stmt ::= '{' Stmts '}'
*/
class StmtsStmt: public Stmt {
	public:
		Stmts* stmts;

		StmtsStmt(Stmts* stmts);
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmt ::= 'if' '(' Expr ')' Stmt
*/ 
class IfStmt: public Stmt {
	public:
		Expr* expr;
		Stmt* stmt;

		IfStmt(Expr* expr, Stmt* stmt);
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmt ::= 'if' '(' Expr ')' Stmt 'else' Stmt
*/
class IfElseStmt: public Stmt {
	public:
		Expr* expr;
		Stmt* stmt1;
		Stmt* stmt2;

		IfElseStmt(Expr* expr, Stmt* stmt1, Stmt* stmt2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmt ::= varName '=' Expr ';'
*/  
class VarExprShortStmt: public Stmt {
	public:
		string varName;
		Expr* expr;
	
		VarExprShortStmt(string varName, Expr* expr);
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmt ::= varName '[' Expr ':' Expr ']' '=' Expr ';'
*/	
class VarExprLongStmt: public Stmt {
	public:
		string varName;
		Expr* expr1;
		Expr* expr2;
		Expr* expr3;
	
		VarExprLongStmt(string varName, Expr* expr1, Expr* expr2, Expr* expr3);
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmt ::= 'print' '(' Expr ')' ';'
*/
class PrintStmt: public Stmt {
	public:
		Expr* expr;

		PrintStmt(Expr* expr);
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmt ::= 'repeat' '(' varName '=' Expr 'to' Expr ')' Stmt
*/
class RepeatStmt: public Stmt {
	public:
		string varName;
		Expr* expr1;
		Expr* expr2;
		Stmt* stmt;

		RepeatStmt(string varName, Expr* expr1, Expr* expr2, Stmt* stmt);
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmt ::= 'while' '(' Expr ')' Stmt
*/
class WhileStmt: public Stmt {
	public:
		Expr* expr;
		Stmt* stmt;

		WhileStmt(Expr* expr, Stmt* stmt);
		string unparse();
		string cppCode();
};

/*!
Class for the production Stmt ::= ';'
*/
class SemiColonStmt: public Stmt {
	public:
		SemiColonStmt();
		string unparse();
		string cppCode();
};

/***************
Decl productions
***************/

/*!
Class for the production Decl ::= 'int' varName ';'
*/
class IntDecl: public Decl {
	public:
		string varName;

		IntDecl(string varName);
		string unparse();
		string cppCode();
};

/*!
Class for the production Decl ::= 'float' varName ';'
*/
class FloatDecl: public Decl {
	public:
		string varName;

		FloatDecl(string varName);
		string unparse();
		string cppCode();
};

/*!
Class for the production Decl ::= 'string' varName ';'
*/
class StringDecl: public Decl {
	public:
		string varName;

		StringDecl(string varName);
		string unparse();
		string cppCode();
};

/*!
Class for the production Decl ::= 'boolean' varName ';'
*/
class BooleanDecl: public Decl {
	public:
		string varName;

		BooleanDecl(string varName);
		string unparse();
		string cppCode();
};

/*!
Class for the production Decl ::= 'matrix' varName '[' Expr ':' Expr ']' varName ':' varName  '=' Expr ';'
*/
class MatrixBrackDecl: public Decl {
	public:
		string varName1;
		Expr* expr1;
		Expr* expr2;
		Expr* varName2;
		Expr* varName3;
		Expr* expr3;

		MatrixBrackDecl(string varName1, Expr* expr1, Expr* expr2, Expr* varName2, Expr* varName3, Expr* expr3);
		string unparse();
		string cppCode();
};

/*!
Class for the production Decl ::= 'matrix' varName '=' Expr ';'
*/
class MatrixDecl: public Decl {
	public:
		string varName;
		Expr* expr;
	
		MatrixDecl(string varName, Expr* expr);
		string unparse();
		string cppCode();
};

/************************
Expr terminal production
************************/

/*!
Class for the production Expr ::= varName | integerConst | floatConst |  stringConst | 'true' | 'false'
*/
class ConstExpr: public Expr {
	public:
		string constVal;

		ConstExpr(string constVal);
		string unparse();
		string cppCode();
};

/**************************
Expr arithmetic productions
**************************/

/*!
Class for the production Expr ::= Expr '*' Expr
*/ 
class MulExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		MulExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '/' Expr
*/
class DivExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		DivExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '+' Expr
*/
class AddExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		AddExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '-' Expr
*/
class SubExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		SubExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/**************************
Expr comparator productions
**************************/

/*!
Class for the production Expr ::= Expr '>' Expr
*/
class GreatExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		GreatExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '>=' Expr
*/
class GreatEqExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		GreatEqExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '<' Expr
*/
class LessExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		LessExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '<=' Expr
*/ 
class LessEqExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		LessEqExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '==' Expr
*/ 
class EqEqExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		EqEqExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '!=' Expr
*/ 
class NotEqExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		NotEqExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*********************
Expr logic productions
*********************/

/*!
Class for the production Expr ::= Expr '&&' Expr
*/ 
class AndExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		AndExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= Expr '||' Expr
*/ 
class OrExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;

		OrExpr(Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= '!' Expr
*/  
class NotExpr: public Expr {
	public:
		Expr* expr;

		NotExpr(Expr* expr);
		string unparse();
		string cppCode();
};

/*********************
Expr other productions
*********************/

/*!
Class for the production Expr ::= varName '[' Expr ':' Expr ']'
*/
class MatrixRefExpr: public Expr {
	public:
		string varName;
		Expr* expr1;
		Expr* expr2;

		MatrixRefExpr(string varName, Expr* expr1, Expr* expr2);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= varName '(' Expr ')'
*/ 
class VarParenExpr: public Expr {
	public:
		string varName;
		Expr* expr;

		VarParenExpr(string varName, Expr* expr);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= '(' Expr ')'
*/  
class ParenExpr: public Expr {
	public:
		Expr* expr;

		ParenExpr(Expr* expr);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= 'let' Stmts 'in' Expr 'end'
*/
class LetExpr: public Expr {
	public:
		Stmts* stmts;
		Expr* expr;

		LetExpr(Stmts* stmts, Expr* expr);
		string unparse();
		string cppCode();
};

/*!
Class for the production Expr ::= 'if' Expr 'then' Expr 'else' Expr
*/
class IfExpr: public Expr {
	public:
		Expr* expr1;
		Expr* expr2;
		Expr* expr3;

		IfExpr(Expr* expr1, Expr* expr2, Expr* expr3);
		string unparse();
		string cppCode();
};

#endif
