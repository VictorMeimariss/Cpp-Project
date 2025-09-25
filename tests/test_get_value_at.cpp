#include<iostream>
#include <../inc/dense.hpp>
using namespace dense;

int main()
{
    matrix<double> M(3,3);
    M.set_value_at(0,1);
    M.set_value_at(4,2);
    M.set_value_at(8,3);
    std::cout << "Expected output: 1 3 2" << std::endl; 
    std::cout <<M.get_value_at(0)<<' '<<M.get_value_at(8)<<' '<<M.get_value_at(4)<<std::endl;
    system("pause");
}