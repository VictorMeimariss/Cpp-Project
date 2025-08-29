#include<iostream>
#include <../inc/dense.hpp>

int main()
{
    matrix<float> I = matrix<float>().I(2);
    matrix<float> M(2,2);
    M.set_value_at(0,1);
    M.set_value_at(1,2);
    M.set_value_at(2,3);
    M.set_value_at(3,4);
    matrix<float> A1(2,2);
    matrix<float> A2(2,2);
    I.low_level_matrix_multiplication(CblasNoTrans,CblasNoTrans,0.0,I,M,A1,1.0);
    I.low_level_matrix_multiplication(CblasNoTrans,CblasNoTrans,0.0,M,I,A2,1.0);
    A1.print2D();
    A2.print2D();
    std::cout << "Expected output:True True" << std::endl; 
    std::cout <<(M==A1)<<' '<<(M==A2)<<std::endl;
    std::cout << "Complex" << std::endl;
    matrix<std::complex<float>> C(2,2);
    C.set_value_at(0,std::complex<float>(1.0,1.0));
    C.set_value_at(0,std::complex<float>(2.0,1.0));
    C.set_value_at(0,std::complex<float>(3.0,1.0));
    C.set_value_at(0,std::complex<float>(4.0,1.0));
    matrix<std::complex<float>> A3(2,2);
    matrix<std::complex<float>> Ic = matrix<std::complex<float>>().I(2);
    Ic.low_level_matrix_multiplication(CblasNoTrans,CblasNoTrans,std::complex<float>(0.0f),C,Ic,A3,std::complex<float>(1.0f));
    A3.print2D();
    system("pause");

}
