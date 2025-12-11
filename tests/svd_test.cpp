#include "dense.hpp"
using namespace dense;
int main(){
    matrix<double> A(4,3);

    A.set_value_at(0, 1);
    A.set_value_at(1, 2);
    A.set_value_at(2, 3);
    A.set_value_at(3, 3);
    A.set_value_at(4, 5);
    A.set_value_at(5, 10);
    A.set_value_at(6, -3);
    A.set_value_at(7, 2);
    A.set_value_at(8, 8);
    A.set_value_at(9, 9);
    A.set_value_at(10, 2);
    A.set_value_at(11, 13);
    
    matrix<double> u(4,4);
    matrix<double>  s(4,3);
    matrix<double>  v(3,3);
    A.svd(u,s,v);
    A.print2D();
    u.print2D();
    s.print2D();
    v.print2D();
    (u*s*v).print2D();
}
