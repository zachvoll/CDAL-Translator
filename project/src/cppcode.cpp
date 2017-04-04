#include "AST.h"
#include "scanner.h"

using namespace std;

string Program::cppCode(){return "";}

string EmptyStmts::cppCode(){return "";}
string StmtStmts::cppCode(){return "";}

string DeclStmt::cppCode(){return "";}

string IfStmt::cppCode(){return "";}
string IfElseStmt::cppCode(){return "";}
string VarExprShortStmt::cppCode(){return "";}
string VarExprLongStmt::cppCode(){return "";}
string PrintStmt::cppCode(){return "";}
string RepeatStmt::cppCode(){return "";}
string WhileStmt::cppCode(){return "";}
string SemiColonStmt::cppCode(){return "";}

string IntDecl::cppCode(){return "";}
string FloatDecl::cppCode(){return "";}
string StringDecl::cppCode(){return "";}
string BooleanDecl::cppCode(){return "";}
string MatrixBrackDecl::cppCode(){return "";}
string MatrixDecl::cppCode(){return "";}

string ConstExpr::cppCode(){return "";}

string MulExpr::cppCode(){return "";}
string DivExpr::cppCode(){return "";}
string AddExpr::cppCode(){return "";}
string SubExpr::cppCode(){return "";}

string GreatExpr::cppCode(){return "";}
string GreatEqExpr::cppCode(){return "";}
string LessExpr::cppCode(){return "";}
string LessEqExpr::cppCode(){return "";}
string EqEqExpr::cppCode(){return "";}
string NotEqExpr::cppCode(){return "";}

string AndExpr::cppCode(){return "";}
string OrExpr::cppCode(){return "";}
string NotExpr::cppCode(){return "";}

string MatrixRefExpr::cppCode(){return "";}
string VarParenExpr::cppCode(){return "";}
string ParenExpr::cppCode(){return "";}
string LetExpr::cppCode(){return "";}
string IfExpr::cppCode(){return "";}
