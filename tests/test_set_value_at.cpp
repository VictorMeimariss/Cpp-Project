#include<iostream>
#include<mkl.h>
#include <../inc/dense.hpp>

int main()
{
    matrix M(4, 2);

    M.set_value_at(1, 2.5);
    M.set_value_at(2, 3.5);
    M.set_value_at(3, 4.5);

    std::cout << "Set value test runned" << std::endl;
}