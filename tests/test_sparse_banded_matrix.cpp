#include <iostream>
#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "Testing Sparse Banded Matrix function" << std::endl;

    int N = 5;
    int kl = 1;
    int ku = 1;
    float val = 3.0;

    matrix<float> A = matrix<float>::banded(N, kl, ku, val);

    A.print2D();
}