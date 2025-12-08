#include<iostream>
#include <../inc/dense.hpp>
using namespace dense;


int main()
{
    matrix<float> M(2,2);
    M.set_value_at(0,2);
    M.set_value_at(1,1);
    M.set_value_at(2,1);
    M.set_value_at(3,2);

    matrix<float> A1 = M^0;
    matrix<float> A2 = M^1;
    matrix<float> A3 = M^7;
    matrix<float> A4 = M^-1;
    matrix<float> A5 = M^-2;

    A1.print2D();
    A2.print2D();
    A3.print2D();
    A4.print2D();
    A5.print2D();
    return 0;
}