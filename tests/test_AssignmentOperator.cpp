#include<iostream>
#include <../inc/dense.hpp>
using namespace dense;

int main()
{
    matrix<float> M1(2, 2);
    matrix<float> M2(2, 2);

    M1.set_value_at(0, 1);
    M1.set_value_at(1, 2);
    M1.set_value_at(2, 3.5);
    M1.set_value_at(3, 4.5);

    std::cout << "M1 values:" << std::endl;
    M1.print2D();

    std::cout << "M2 initial values (before the use of M2 = M1):" << std::endl;
    M2.print2D();

    M2 = M1;
    std::cout << "M2 final values (after the use of M2 = M1):" << std::endl;
    M2.print2D();
}