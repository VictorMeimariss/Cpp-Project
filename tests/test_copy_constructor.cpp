#include<iostream>
#include <../inc/dense.hpp>

int main()
{
    matrix<float> M(4, 2);

    M.set_value_at(1, 2);
    M.set_value_at(2, 3);
    M.set_value_at(3, 4);

    std::cout << "M values:" << std::endl;
    M.print2D();

    std::cout<< "Copy Constructor used for M1\n" << std::endl;
    matrix<float> M1 = M;
    std::cout << "M1 values:" << std::endl;
    M1.print2D();
}