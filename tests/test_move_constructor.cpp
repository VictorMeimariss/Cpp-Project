#include<iostream>
#include <../inc/dense.hpp>

int main()
{
    matrix<float> M(2, 2);
    
    M.set_value_at(0, 1);
    M.set_value_at(1, 2);
    M.set_value_at(2, 3);
    M.set_value_at(3, 4);
    
    matrix<float> K(2,2);
    K.set_value_at(0, 5);
    K.set_value_at(1, 6);
    K.set_value_at(2, 7);
    K.set_value_at(3, 8);

    matrix<float> T(2,2);

    T = std::move(M);
    M = std::move(K);
    K = std::move(T);
    std::cout<<"Expected output M: 5 6\n7 8"<<std::endl;
    std::cout<<"M: ";
    M.print2D();
    std::cout<<std::endl<<"Expected output K: 1 2\n3 4"<<std::endl;
    K.print2D();
    system("pause");
}