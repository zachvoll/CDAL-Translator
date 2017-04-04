#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

matrix::matrix(int i, int j) {
    rows = i;
    cols = j;

    float *m = new float[i*j];

    int r;
    for (r = 0; r < i*j; r++) {
      m[r] = 0;
    }
    data = m;
}

matrix::matrix (const matrix& m) {
    rows = m.rows;
    cols = m.cols;

    float *n = new float[rows*cols];

	  //allocate space for new matrix
    int r;
    for (r = 0; r < rows*cols; r++) {
        n[r] = m.data[r];
      
    }
    //copy matrix
    data = n;
}

float* matrix::access(const int i, const int j) const{
    return &data[i*cols+j];
}

//read in values from a file to create a new matrix
matrix matrix::matrixRead (string filename ) {
 ifstream matrixFile;
  int theRows, theCols;

  matrixFile.open(filename.c_str());
   
  if(!matrixFile.is_open()){
      fprintf(stderr,"Failed to open matrix file.\n");
      exit(1);
  }

  matrixFile >> theRows;
  matrixFile >> theCols;

  //create new matrix
  matrix newMatrix = matrix(theRows, theCols);

  //fill matrix
  int i, j;
  for(i = 0; i < theRows; i++){
    for(j = 0; j < theCols; j++){
      matrixFile >> newMatrix.access(i,j) [0];
    }
  }

  return newMatrix;
}

//overloaded operator used to print out a matrix
ostream& operator<<(ostream &os, matrix &m){
    int theRows = m.rows;
    int theCols = m.cols;

    os << theRows << " " << theCols << "\n";
    int i,j;
    for(i = 0; i < theRows; i++){
        for(j = 0; j < theCols; j++){
            os << (*m.access(i,j)) << "  ";
        }
        os << "\n";
    }
}

int matrix::numRows() {
    return rows;
}
int matrix::numCols() {
    return cols;
}

int matrix::numRows(matrix m){
	return m.rows;
} 
int matrix::numCols(matrix m){
	return m.cols;
} 
//overloaded operator to multipy matrices together
//takes in only right hand side

matrix matrix::operator * (const matrix& m2){
  float prodsum;
	if (this->cols != m2.rows){
		throw invalid_argument("Matrices can't be multiplied.\n");
	}

	else{
		matrix prodmatrix = matrix(this->rows, m2.cols);

		for (int i = 0; i < prodmatrix.rows; i++){
			for(int j = 0; j < prodmatrix.cols; j++){
				prodsum = 0;
				for (int k = 0; k<m2.rows; k++){
					prodsum += (this->access(i,k)[0] * m2.access(k,j)[0]);
				}
				prodmatrix.access(i,j)[0] = prodsum;
			}
		}
		return prodmatrix;
	}
}

/*

matrix matrix::operator = (const matrix& m1, const matrix& m2){
	for (i =0; i<m2.rows; i++){
		for (j = 0; j<m2.columns; j++){
			m1[i][j] = m2[i][j]
		}
	}
}
*/
