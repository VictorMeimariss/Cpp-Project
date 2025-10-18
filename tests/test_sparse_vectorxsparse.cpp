#include "matrix.hpp"
int main(){

    std::vector<std::complex<double>> vector = {{2.0, 1.0}, {2.0, 1.0}}; // Vector values

    // Sparse matrix
    std::vector<std::complex<double>> values = {{1.0, 0.0}};
    std::vector<MKL_INT> col_idx = {0};
    std::vector<MKL_INT> row_idx = {0, 0, 1};
    sparse::matrix<std::complex<double>> A(values, col_idx, row_idx, 2, 2);

    vector =  vector * A;
    std::cout << "Test Expected Answer for sparse x scalar: (2,1) (0,0)\n"<< "Test Result: ";
    for (auto i: vector){
        std::cout << i <<" ";
    }
    std::cout << "\n";
    return 0;

    // std::cout << "\nTest Expected Answer for scalar x sparse:\n" << "Values: 4\nCol_idx: 0\nRow_idx: 0 0 1 \n\n" << "Test Result:" << std::endl;
    // sparse::matrix<float> C = 4.0f * A;
    // C.print2D();
    // return 0;
}