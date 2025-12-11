#include "dense.hpp"
using namespace dense;
int main(){
    matrix<std::complex<double>> A(2,3);

    A.set_value_at(0, 1);
    A.set_value_at(1, 2);
    A.set_value_at(2, 3);
    A.set_value_at(3, 4);
    A.set_value_at(4, 5);
    A.set_value_at(5, 6);
    
    matrix<std::complex<double>>  u(2,2);
    matrix<std::complex<double>>  s(2,3);
    matrix<std::complex<double>>  v(3,3);

    A.svd(u,s,v);

    A.print2D();
    u.print2D();
    s.print2D();
    v.print2D();
    (u*s*v).print2D();

}
