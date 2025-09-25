#include<iostream>
#include <../inc/dense.hpp>
using namespace dense;


int main()
{
    matrix<float> I = matrix<float>().I(2); //non-static construction
    matrix<float> M(2,2);
    M.set_value_at(0,1);
    M.set_value_at(1,2);
    M.set_value_at(2,3);
    M.set_value_at(3,4);
    matrix<float> A1 = M*I;
    matrix<float> A2 = I*M;
    matrix<float> A3 = I+I;
    matrix<float> A4 = 2*I;

    
    std::cout << "Expected output:True True True" << std::endl; 
    std::cout <<(bool)(M==A1)<<' '<<(bool)(M==A2)<<(bool)(A3==A4)<<std::endl;
    system("pause");
}