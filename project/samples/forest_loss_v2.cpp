#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.h"
using namespace std;

int main() {
 matrix data = matrix::matrixRead("../samples/myData.dat");
 ; int rows;
 rows = matrix::numRows(data);
 int cols;
 cols = matrix::numCols(data);
 int season_length;
 season_length = 7;
 int years;
 years = ceil(cols * 1.0 / season_length);
  matrix avgScore = matrix(rows,1);
({int row,irrelevant;
for(row = 0; row < rows; row++){
for(irrelevant = 0; irrelevant < 1; irrelevant++){
*avgScore.access(row,irrelevant) =({ matrix pt = matrix(years,season_length);
({int i,j;
for(i = 0; i < years; i++){
for(j = 0; j < season_length; j++){
*pt.access(i,j) =({int k;
 k = i * season_length + j;
 (k >= cols)? (0.0 - 25): ( data.access(row,k)[0] );});
}}})
 ;  matrix comparisonMatrix = matrix(years,years);
({int i,j;
for(i = 0; i < years; i++){
for(j = 0; j < years; j++){
*comparisonMatrix.access(i,j) =(j <= i)? (0.0): ( ({float diff;
 diff = 0;
 int k;
 for(k=0; k <= season_length - 1; k++){
diff = diff + pt.access(i,k)[0] - pt.access(j,k)[0];
 }
 diff / season_length;}) );
}}})
 ;  matrix modelAvgScore = matrix(years,1);
({int yr,dontcare;
for(yr = 0; yr < years; yr++){
for(dontcare = 0; dontcare < 1; dontcare++){
*modelAvgScore.access(yr,dontcare) =({int x;
 int y;
 float score1;
 score1 = 0.0;
 for(x=0; x <= yr; x++){
for(y=yr + 1; y <= years - 1; y++){
score1 = score1 + comparisonMatrix.access(x,y)[0];
 }
 }
 score1 = score1 * 2 / (yr * (years - yr));
 float score2;
 score2 = 0.0;
 for(x=0; x <= yr; x++){
for(y=0; y <= yr; y++){
score2 = score2 + comparisonMatrix.access(x,y)[0];
 }
 }
 score2 = score2 / ((yr - 1) * yr / 2);
 float score3;
 score3 = 0.0;
 for(x=yr + 1; x <= years - 1; x++){
for(y=yr + 1; y <= years - 1; y++){
score3 = score3 + comparisonMatrix.access(x,y)[0];
 }
 }
 score3 = score3 / ((years - yr) * (years - yr - 1) / 2);
 score1 - score2 - score3;});
}}})
 ; float maximum;
 maximum = 0.0 - 25;
 int k;
 k = 0;
 for(k=0; k <= years - 1; k++){
if (modelAvgScore.access(k,0)[0] > maximum){
{
maximum = modelAvgScore.access(k,0)[0];
 }
} }
 maximum;});
}}})
 ; int j;
 for(j=0; j <= rows - 1; j++){
cout << avgScore.access(j,0)[0];
 cout << "\n";
 }
 
return 0;
}
