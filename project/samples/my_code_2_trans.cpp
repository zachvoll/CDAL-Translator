#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.h"
using namespace std;

int main ( ) {
    int x ;
    x = 5 ;
    int result;
    result = 1;
    while (x > 0) {
    	result = result * x;
    	x = x - 1 ;
    }
    cout << result;

    return 0;
}
