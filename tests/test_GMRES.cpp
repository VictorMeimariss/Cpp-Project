#include<matrix.hpp>
#include<cstring>
using namespace sparse;
int main() {
    std::vector<double> b = {1,1,1,1,1};
    std::vector<double> x = {-3, -6, -7, -9, -8 };
    std::vector<double> d = {-2,  1,  1, -2,  1,  1, -2,  1,  1, -2,  1, 1,  1, -2};
    std::vector<MKL_INT> i = {0, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 1, 3, 4};
    std::vector<MKL_INT> p = {0,  2,  5,  8, 11, 14};
    matrix<double> A(d, i, p, 5, 5);

    const std::vector<double> diagonal = A.diag();
    matrix<double> J = A.I(5);
    for(int i = 0; i<5; i++){
        J.set_value_at(i+i*5, 1/diagonal[i]);
    }
    J.print_matrix();
    A.print_matrix();
    std::vector<double> s = FGMRES_dsolve(A, b, x, true,J);
    for(int i = 0; i<5; i++){
        std::cout<<s[i]<<' ';
    }
        std::cout<<std::endl;
    for(int i = 0; i<5; i++){
        std::cout<<x[i]<<' ';
    }
        std::cout<<std::endl;
    for(int i = 0; i<5; i++){
        std::cout<<b[i]<<' ';
    }
    std::cout<<std::endl;
}
