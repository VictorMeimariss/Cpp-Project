#include<iostream>
#include<mkl.h>
#include <../inc/dense.hpp>

int main()
{
    matrix M(4, 2);

    std::cout << "Matrix dimensions = " << M.get_nod() << std::endl;
}