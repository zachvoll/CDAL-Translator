/* This program is just a copy of sample_1.dsl. You should write your CDAL program to multiply two
2-dimensional matrices and save it
in a file with this name. */

main () {

    matrix a = matrixRead ( "../samples/my_code_data1.data" ) ;

    matrix m = matrixRead ( "../samples/my_code_data2.data" ) ;

    matrix result = a * m ; 

    print ( result ) ; 

}
