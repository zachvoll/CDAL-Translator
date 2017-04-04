/* This program is just a copy of sample_1.dsl.
You should write your second interesting CDAL
program and save it in a file with this name.

This program calculates the factorial 5!. */

main () {
  int x;
  x = 5 ;
  int result;
  result = 1;
  while (x > 0) {
  	result = result * x;
  	x = x - 1 ;
  }

  print(result) ;
}
