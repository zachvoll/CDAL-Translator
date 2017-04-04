#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class matrix {
public:
    matrix(int i, int j) ;
    matrix (const matrix& m) ;

    int numRows ( ) ;
    int numCols ( ) ;

    matrix operator * (const matrix& m2);
/*	matrix operator = (const matrix& m1, const matrix& m2);
*/
    float *access(const int i, const int j) const ;
    friend ostream& operator<<(ostream &os, matrix &m) ;

    static matrix matrixRead ( string filename );
	static int numRows (matrix m);
	static int numCols (matrix m); 
private:
    matrix() { }
    int rows ;
    int cols ;

    /* Your implementation of "data" may vary.  There are ways in
       which data can be an array of arrays and thus simplify the
       access method, at the cost of complicating the process of
       allocating space for data.  The choice is entirely up to
       you. */
    float *data ;
} ;

#endif // MATRIX_H
