#include<iostream>
#include <../inc/dense.hpp>

using namespace dense;
int main()
{
    matrix<float> M(1, 4, 3);

    std::cout << "Expected output: 1 4 3" << std::endl; 
    std::cout <<M.get_dim_size(0)<<' '<<M.get_dim_size(1)<<' '<<M.get_dim_size(2)<<std::endl;
    system("pause");
}