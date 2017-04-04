#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.h"
using namespace std;

int main() {
 matrix m = matrix(10,10);
({int i,j;
for(i = 0; i < 10; i++){
for(j = 0; j < 10; j++){
*m.access(i,j) =i * j;
}}})
 ; int i;
 int j;
 for(i=0; i <= 9; i++){
for(j=0; j <= 9; j++){
cout << m.access(i,j)[0];
 cout << "  ";
 }
 cout << "\n";
 }
 for(i=0; i <= 9; i++){
for(j=0; j <= 9; j++){
*m.access(i,j) =m.access(i,j)[0] + 100; }
 }
 for(i=0; i <= 9; i++){
for(j=0; j <= 9; j++){
cout << m.access(i,j)[0];
 cout << "  ";
 }
 cout << "\n";
 }
 
return 0;
}
