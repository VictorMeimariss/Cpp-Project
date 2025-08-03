#include<iostream>
#include<mkl.h>
#include <../inc/dense.hpp>

int main()
{
    matrix<int> M(4, 2, 2);

    std::cout << "Expected Matrix dimensions = 3" << std::endl; 
    std::cout << "Matrix dimensions = " << M.get_nod() << std::endl;
}