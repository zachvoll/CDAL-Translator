#include "AST.h"
#include "scanner.h"

#define DEBUG

#ifdef DEBUG
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
#endif

using namespace std;

/*****************
Program production
*****************/

Program::Program(string varName, Stmts* stmts){
    this->varName = varName;
    this->stmts = stmts;
}

string Program::unparse(){
    #ifdef DEBUG
    if (stmts == NULL) { fprintf(stderr, "broke at Program\n"); return "Error"; }
    #endif

    return varName + " (){ " + stmts->unparse() +  " } ";
}

/****************
Stmts productions
****************/

EmptyStmts::EmptyStmts(){}
string EmptyStmts::unparse(){
    return "";
}

StmtStmts::StmtStmts(Stmt* stmt, Stmts* stmts){
    this->stmt = stmt;
    this->stmts = stmts;
}

//fix later
string StmtStmts::unparse(){
    #ifdef DEBUG
    if ((stmt == NULL) || (stmts == NULL)) { fprintf(stderr, "broke at StmtStmts\n"); return "Error"; }
    #endif

    return stmt->unparse() + " " + stmts->unparse();
}

/***************
Stmt productions
***************/

DeclStmt::DeclStmt(Decl* decl){
    this->decl = decl;
}

string DeclStmt::unparse(){
    #ifdef DEBUG
    if (decl == NULL) { fprintf(stderr, "broke at DeclStmt\n"); return "Error"; }
    #endif

    return decl->unparse();
}

StmtsStmt::StmtsStmt(Stmts* stmts){
    this->stmts = stmts;
}

string StmtsStmt::unparse(){
    #ifdef DEBUG
    if (stmts == NULL) { fprintf(stderr, "broke at StmtsStmt\n"); return "Error"; }
    #endif

    return " { " + stmts->unparse() + " } ";
}

IfStmt::IfStmt(Expr* expr, Stmt* stmt){
    this->expr = expr;
    this->stmt = stmt;
}

string IfStmt::unparse(){
    #ifdef DEBUG
    if ((expr == NULL)||(stmt == NULL)) { fprintf(stderr, "broke at IfStmt\n"); return "Error"; }
    #endif

    return " if( " + expr->unparse() + " ) " + stmt->unparse();
}

IfElseStmt::IfElseStmt(Expr* expr, Stmt* stmt1, Stmt* stmt2){
    this->expr = expr;
    this->stmt1 = stmt1;
    this->stmt2 = stmt2;
}
string IfElseStmt::unparse(){
    #ifdef DEBUG
    if ((expr == NULL)||(stmt1 == NULL)||(stmt2 == NULL)) { fprintf(stderr, "broke at IfElseStmt\n"); return "Error"; }
    #endif

    return " if( " + expr->unparse() + " ) " + stmt1->unparse() + " else " + stmt2->unparse();
}

VarExprShortStmt::VarExprShortStmt(string varName, Expr* expr){
    this->varName = varName;
    this->expr = expr;
}
string VarExprShortStmt::unparse(){
    #ifdef DEBUG
    if (expr == NULL) { fprintf(stderr, "broke at VarExprShortStmt\n"); return "Error"; }
    #endif

    return varName + " = " + expr->unparse() + " ; ";
}

VarExprLongStmt::VarExprLongStmt(string varName, Expr* expr1, Expr* expr2, Expr* expr3){
    this->varName = varName;
    this->expr1 = expr1;
    this->expr2 = expr2;
    this->expr3 = expr3;
}
string VarExprLongStmt::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)||(expr3 == NULL)) { fprintf(stderr, "broke at VarExprLongStmt\n"); return "Error"; }
    #endif

    return varName + " [ " + expr1->unparse() + " : " + expr2->unparse() + " ] = " + expr3->unparse() + " ; ";
}

PrintStmt::PrintStmt(Expr* expr){
    this->expr = expr;
}
string PrintStmt::unparse(){
    #ifdef DEBUG
    if (expr == NULL) { fprintf(stderr, "broke at PrintStmt\n"); return "Error"; }
    #endif

    return " print( " + expr->unparse() + " ); ";
}

RepeatStmt::RepeatStmt(string varName, Expr* expr1, Expr* expr2, Stmt* stmt){
    this->varName = varName;
    this->expr1 = expr1;
    this->expr2 = expr2;
    this->stmt = stmt;
}
string RepeatStmt::unparse(){
    #ifdef DEBUG
    if ((stmt == NULL)||(expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at RepeatStmt\n"); return "Error"; }
    #endif

    return " repeat( " + varName + " = " + expr1->unparse() + " to " + expr2->unparse() + " ) " + stmt->unparse();
}

WhileStmt::WhileStmt(Expr* expr, Stmt* stmt){
    this->expr = expr;
    this->stmt = stmt;
}
string WhileStmt::unparse(){
    #ifdef DEBUG
    if ((expr == NULL)||(stmt == NULL)) { fprintf(stderr, "broke at WhileStmt\n"); return "Error"; }
    #endif

    return " while( " + expr->unparse() + " ) " + stmt->unparse();
}

SemiColonStmt::SemiColonStmt(){}
string SemiColonStmt::unparse(){
    return " ; ";
}

/***************
Decl productions
***************/

IntDecl::IntDecl(string varName){
    this->varName = varName;
}

string IntDecl::unparse(){
    return " int " +  varName + " ; ";
}

FloatDecl::FloatDecl(string varName){
    this->varName = varName;
}
string FloatDecl::unparse(){
    return " float " + varName + " ; ";
}

StringDecl::StringDecl(string varName){
    this->varName = varName;
}
string StringDecl::unparse(){
    return " string " + varName + " ; ";
}

BooleanDecl::BooleanDecl(string varName){
    this->varName = varName;
}
string BooleanDecl::unparse(){
    return " boolean " + varName + ";";
}

MatrixBrackDecl::MatrixBrackDecl(string varName1, Expr* expr1, Expr* expr2, Expr* varName2, Expr* varName3, Expr* expr3){
    this->varName1 = varName1;
    this->expr1 = expr1;
    this->expr2 = expr2;
    this->varName2 = varName2;
    this->varName3 = varName3;
    this->expr3 = expr3;
}
string MatrixBrackDecl::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)||(varName2 == NULL)||(varName3 == NULL)||(expr3 == NULL)) { fprintf(stderr, "broke at MatrixBrackDecl\n"); return "Error"; }
    #endif

    return "matrix " + varName1 + " [ " + expr1->unparse() + " : " + expr2->unparse() + " ] " + varName2->unparse() + " : " + varName3->unparse() + " = " + expr3->unparse();
}

MatrixDecl::MatrixDecl(string varName, Expr* expr){
    this->varName = varName;
    this->expr = expr;
}

string MatrixDecl::unparse(){
    #ifdef DEBUG
    if (expr == NULL) { fprintf(stderr, "broke at MatrixDecl\n"); return "Error"; }
    #endif

    return " matrix " + varName + " = " + expr->unparse();
}

/************************
Expr terminal production
************************/

ConstExpr::ConstExpr(string constVal){
    this->constVal = constVal;
}
string ConstExpr::unparse(){
    #ifdef DEBUG
    if (constVal == "") { fprintf(stderr, "broke at ConstExpr\n"); return "Error"; }
    #endif

    return constVal;
}

/**************************
Expr arithmetic productions
**************************/

MulExpr::MulExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string MulExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at MulExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " * " + expr2->unparse();
}

DivExpr::DivExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string DivExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at DivExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " / " + expr2->unparse();
}

AddExpr::AddExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string AddExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at AddExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " + " + expr2->unparse();
}

SubExpr::SubExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string SubExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at SubExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " - " + expr2->unparse();
}

/**************************
Expr comparator productions
**************************/

GreatExpr::GreatExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string GreatExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at GreatExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " > " + expr2->unparse();
}

GreatEqExpr::GreatEqExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string GreatEqExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at GreatEqExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " >= " + expr2->unparse();
}

LessExpr::LessExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string LessExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at LessExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " < " + expr2->unparse();
}

LessEqExpr::LessEqExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string LessEqExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at LessEqExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " <= " + expr2->unparse();
}

EqEqExpr::EqEqExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string EqEqExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at EqEqExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " == " + expr2->unparse();
}

NotEqExpr::NotEqExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string NotEqExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at NotEqExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " != " + expr2->unparse();
}

/*********************
Expr logic productions
*********************/

AndExpr::AndExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string AndExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at AndExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " && " + expr2->unparse();
}

OrExpr::OrExpr(Expr* expr1, Expr* expr2){
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string OrExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at OrExpr\n"); return "Error"; }
    #endif

    return expr1->unparse() + " || " + expr2->unparse();
}

NotExpr::NotExpr(Expr* expr){
    this->expr = expr;
}
string NotExpr::unparse(){
    #ifdef DEBUG
    if (expr == NULL) { fprintf(stderr, "broke at NotExpr\n"); return "Error"; }
    #endif

    return " ! " + expr->unparse();
}

/*********************
Expr other productions
*********************/

MatrixRefExpr::MatrixRefExpr(string varName, Expr* expr1, Expr* expr2){
    this->varName = varName;
    this->expr1 = expr1;
    this->expr2 = expr2;
}
string MatrixRefExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)) { fprintf(stderr, "broke at MatrixRefExpr\n"); return "Error"; }
    #endif

    return varName + " [ " + expr1->unparse() + " : " + expr2->unparse() +" ] ";
}

VarParenExpr::VarParenExpr(string varName, Expr* expr){
    this->varName = varName;
    this->expr = expr;
}
string VarParenExpr::unparse(){
    #ifdef DEBUG
    if (expr == NULL) { fprintf(stderr, "broke at VarParenExpr\n"); return "Error"; }
    #endif

    return varName + " ( " + expr->unparse() + " ) ";
}

ParenExpr::ParenExpr(Expr* expr){
    this->expr = expr;
}
string ParenExpr::unparse(){
    #ifdef DEBUG
    if (expr == NULL) { fprintf(stderr, "broke at ParenExpr\n"); return "Error"; }
    #endif

    return " ( " + expr->unparse() + " ) ";
}

LetExpr::LetExpr(Stmts* stmts, Expr* expr){
    this->stmts = stmts;
    this->expr = expr;
}
string LetExpr::unparse(){
    #ifdef DEBUG
    if ((stmts == NULL)||(expr == NULL)) { fprintf(stderr, "broke at LetExpr\n"); return "Error"; }
    #endif

    return " let " + stmts->unparse() + " in " + expr->unparse() + " end ";
}

IfExpr::IfExpr(Expr* expr1, Expr* expr2, Expr* expr3){
    this->expr1 = expr1;
    this->expr2 = expr2;
    this->expr3 = expr3;
}
string IfExpr::unparse(){
    #ifdef DEBUG
    if ((expr1 == NULL)||(expr2 == NULL)||(expr3 == NULL)) { fprintf(stderr, "broke at IfExpr\n"); return "Error"; }
    #endif

    return " if " + expr1->unparse() + " then " + expr2->unparse() + " else " + expr3->unparse();
}

/**************
cppCode methods
**************/

//program needs headers
string headers(){
    return string("#include <stdio.h>\n") + "#include <stdlib.h>\n" + "#include <iostream>\n" + "#include <math.h>\n" + "#include \"Matrix.h\"\n" + "using namespace std;\n";
}


string Program::cppCode(){ return headers() + "\n" + "int " + varName + "(" + ") " + "{" + "\n" + stmts->cppCode() + "\n" + "return 0;\n" + "}"; }

string EmptyStmts::cppCode(){ return ""; }
string StmtStmts::cppCode(){ return stmt->cppCode() + " " + stmts->cppCode(); }

string DeclStmt::cppCode(){ return decl->cppCode(); }

string StmtsStmt::cppCode(){ return "{\n" + stmts->cppCode() + "}\n"; }
string IfStmt::cppCode(){ return "if (" + expr->cppCode() + "){" + "\n" + stmt->cppCode() + "}"; }
string IfElseStmt::cppCode(){ return "if (" + expr->cppCode() + "){" + "\n" + stmt1->cppCode() + "} " + "else {" + "\n" + stmt2->cppCode() + "}"; }
string VarExprShortStmt::cppCode(){ return varName + " = " + expr->cppCode() + ";\n"; }


string VarExprLongStmt::cppCode(){ return "*" + varName + ".access(" + expr1->cppCode() + "," + expr2->cppCode() + ") =" + expr3->cppCode() + ";"; }
string PrintStmt::cppCode(){ return "cout << " + expr->cppCode() + ";\n"; }
string RepeatStmt::cppCode(){ return "for(" + varName + "=" + expr1->cppCode() + "; " + varName + " <= " + expr2->cppCode() + "; " + varName + "++)" + stmt->cppCode(); }
string WhileStmt::cppCode(){ return "while (" + expr->cppCode() + ")" + stmt->cppCode(); }
string SemiColonStmt::cppCode(){ return ";"; }

string IntDecl::cppCode(){ return "int " + varName + ";\n"; }
string FloatDecl::cppCode(){ return "float " + varName + ";\n"; }
string StringDecl::cppCode(){ return "string " + varName + ";\n"; }
string BooleanDecl::cppCode(){ return "bool " + varName + ";\n"; }

string MatrixBrackDecl::cppCode(){ return " matrix " + varName1 + " = " + "matrix(" + expr1->cppCode() + "," + expr2->cppCode() + ");\n" +
      "({int " + varName2->cppCode() + "," + varName3->cppCode() + ";\n" +
      "for(" + varName2->cppCode() +  " = 0; " + varName2->cppCode() + " < " + expr1->cppCode() + "; " + varName2->cppCode() + "++){\n" +
      "for(" + varName3->cppCode() +  " = 0; " + varName3->cppCode() + " < " + expr2->cppCode() + "; " + varName3->cppCode() + "++){\n" +
      "*" + varName1 + ".access("+ varName2->cppCode() + "," + varName3->cppCode() + ") =" + expr3->cppCode() + ";\n}}})\n"; }

string MatrixDecl::cppCode(){ return " matrix " + varName + " = " + expr->cppCode() + ";\n"; }

string ConstExpr::cppCode(){ return constVal; }

string MulExpr::cppCode(){ return expr1->cppCode() + " * " + expr2->cppCode(); }
string DivExpr::cppCode(){ return expr1->cppCode() + " / " + expr2->cppCode(); }
string AddExpr::cppCode(){ return expr1->cppCode() + " + " + expr2->cppCode(); }
string SubExpr::cppCode(){ return expr1->cppCode() + " - " + expr2->cppCode(); }

string GreatExpr::cppCode(){ return expr1->cppCode() + " > " + expr2->cppCode(); }
string GreatEqExpr::cppCode(){ return expr1->cppCode() + " >= " + expr2->cppCode(); }
string LessExpr::cppCode(){ return expr1->cppCode() + " < " + expr2->cppCode(); }
string LessEqExpr::cppCode(){ return expr1->cppCode() + " <= " + expr2->cppCode(); }
string EqEqExpr::cppCode(){ return expr1->cppCode() + " == " + expr2->cppCode(); }
string NotEqExpr::cppCode(){ return expr1->cppCode() + " != " + expr2->cppCode(); }

string AndExpr::cppCode(){ return expr1->cppCode() + " && " + expr2->cppCode(); }
string OrExpr::cppCode(){ return expr1->cppCode() + " || " + expr2->cppCode(); }
string NotExpr::cppCode(){ return "!(" + expr->cppCode() + ")"; }

//TODO
string MatrixRefExpr::cppCode(){ return varName + ".access(" + expr1->cppCode() + "," + expr2->cppCode() + ")[0]"; }
string VarParenExpr::cppCode(){
	if ((varName == "matrixRead" )|| (varName =="numRows")||(varName =="numCols")) {
		return "matrix::" + varName + "(" + expr->cppCode() + ")"; }
	return varName + "(" + expr->cppCode() + ")"; }
	
string ParenExpr::cppCode(){ return "(" + expr->cppCode() + ")"; }

string LetExpr::cppCode(){ return "({" + stmts->cppCode() + expr->cppCode() + ";})"; }
string IfExpr::cppCode(){ return "(" + expr1->cppCode() + ")? (" + expr2->cppCode() + "): ( " + expr3->cppCode() + " )"; }
