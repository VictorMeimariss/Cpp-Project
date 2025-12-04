#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "Testing sparse matrix multiplication" << std::endl;
    std::vector<float> Avalues = {1.0, 2.0, 1.0, 3.0, 4.0, 5.0};
    std::vector<MKL_INT> Acol_idx = {0, 2, 3, 0, 2, 3};
    std::vector<MKL_INT> Arow_idx = {0, 1, 3, 5, 6};

    matrix<float> A(Avalues, Acol_idx, Arow_idx, 4, 4);

    std::vector<float> Bvalues = {1.0,1.0,1.0,1.0};
    std::vector<MKL_INT> Bcol_idx = {0, 1, 2, 3};
    std::vector<MKL_INT> Brow_idx = {0, 1, 2, 3,4};

    matrix<float> B(Bvalues, Bcol_idx, Brow_idx, 4, 4);
    A.print_matrix();
    B.print_matrix();
    matrix<float> C = A*B;
    C.print_matrix();
}
