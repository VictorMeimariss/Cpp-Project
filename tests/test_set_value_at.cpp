#include<iostream>
#include <../inc/dense.hpp>
using namespace dense;


int main()
{
    matrix<float> M(4, 2);

    M.set_value_at(1, 2);
    M.set_value_at(2, 3);
    M.set_value_at(3, 4);

    std::cout << "Test Expected Answer:\n" << "[0, 2; 3, 4; 0, 0; 0, 0]\n\n" << "Test Result:" << std::endl;
    M.print2D();
}
