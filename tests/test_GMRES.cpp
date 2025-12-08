
#include<matrix.hpp>
#include<cstring>
using namespace sparse;

int main() {
    std::vector<double> b = {1,1,1,1,1};
    std::vector<double> x = {1,1,1,1,1};
    std::vector<double> d = {-2,  1,  1, -2,  1,  1, -2,  1,  1, -2,  1, 1,  1, -2};
    std::vector<MKL_INT> i = {0, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 1, 3, 4};
    std::vector<MKL_INT> p = {0,  2,  5,  8, 11, 14};
    matrix<double> A(d, i, p, 5, 5);
    std::vector<double> s = FGMRES_dsolve(A, b, x);
    for(int i = 0; i<5; i++){
        std::cout<<s[i]<<' ';
    }
    std::cout<<std::endl;
}

