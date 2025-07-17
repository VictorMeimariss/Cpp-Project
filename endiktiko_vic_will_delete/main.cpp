#include <iostream>
#include "dense_matrix.hpp"
int main(){
    dense_matrix A(3,1);
    A.set_values(1,3,2);

    dense_matrix B(3,1);
    B.set_values(2,5,5);
    dense_matrix C;
    C = A + B;
    C.print_2D_matrix(0);
    return 0;
}