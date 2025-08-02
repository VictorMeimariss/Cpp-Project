#include<iostream>
#include<mkl.h>
#include <../inc/dense.hpp>

int main()
{
    matrix<int> M(4, 2, 2);

    std::cout << "Matrix dimensions = " << M.get_nod() << std::endl;
}