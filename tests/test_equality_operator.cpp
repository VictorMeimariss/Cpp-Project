#include<iostream>
#include <../inc/dense.hpp>

using namespace dense;

int main()
{
    matrix<float> M(2,2);
    
    M.set_value_at(0, 1);
    M.set_value_at(1, 2);
    M.set_value_at(2, 3);
    M.set_value_at(3, 4);
    
    matrix<float> K(2,2);
    K.set_value_at(0, 5);
    K.set_value_at(1, 6);
    K.set_value_at(2, 7);
    K.set_value_at(3, 8);

    matrix<float> T(1,4);  
    M.set_value_at(0, 1);
    M.set_value_at(1, 2);
    M.set_value_at(2, 3);
    M.set_value_at(3, 4);
    std::cout<<"Expected output: False False False"<<std::endl<<(M==K)<<' '<<(M==T)<<' '<<(T==K)<<std::endl;  
    system("pause");
}