#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.h"
using namespace std;

int main() {
 matrix a = matrix::matrixRead("../samples/my_code_data1.data");
 ;  matrix m = matrix::matrixRead("../samples/my_code_data2.data");
 ;  matrix result = a * m;
 ; cout << result;
 
return 0;
}
