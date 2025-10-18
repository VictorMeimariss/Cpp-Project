#include<iostream>
#include <../inc/dense.hpp>
using namespace dense;


int main()
{
    matrix<float> M1(2, 2);
    matrix<float> M2(2, 2);

    M1.set_value_at(0, 4);
    M2.set_value_at(0, 2);
    M1.set_value_at(1, 3);
    M2.set_value_at(1, 6);
    M1.set_value_at(2, 4.5);
    M2.set_value_at(2, 2);

    matrix<float> res(2, 2);
    res = M1 - M2;
    std::cout << "Test Expected Answer:\n" << "[2, -3; 2.5, 0]\n\n" << "Test Result:" << std::endl;
    res.print2D();
    std::cout << "M1(expected 4, 3; 4.5, 0):"<<std::endl;
    M1.print2D();
    std::cout << "M2(expected 2, 6; 2, 0):"<<std::endl;
    M2.print2D();
}