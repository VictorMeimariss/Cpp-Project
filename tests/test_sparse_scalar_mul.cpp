#include "matrix.hpp"
int main(){

    std::vector<float> values = {1.0};
    std::vector<MKL_INT> col_idx = {0};
    std::vector<MKL_INT> row_idx = {0, 0, 1};
    sparse::matrix<float> A(values, col_idx, row_idx, 2, 2);

    sparse::matrix<float> B =  A * 2.0f;
    std::cout << "Test Expected Answer for sparse x scalar:\n" << "Values: 2\nCol_idx: 0\nRow_idx: 0 0 1 \n\n" << "Test Result:" << std::endl;
    B.print2D();

    std::cout << "\nTest Expected Answer for scalar x sparse:\n" << "Values: 4\nCol_idx: 0\nRow_idx: 0 0 1 \n\n" << "Test Result:" << std::endl;
    sparse::matrix<float> C = 4.0f * A;
    C.print2D();
    return 0;
}