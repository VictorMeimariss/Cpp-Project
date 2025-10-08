#include <iostream>
#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "Testing Sparse Identity Matrix function" << std::endl;

    int N = 5;
    std::cout << "Sparse Identity Matrix size: " << N << std::endl;

    matrix<float> A = matrix<float>::I(N);

    A.print2D();
}