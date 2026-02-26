#include <iostream>
#include "../inc/matrix.hpp"
using namespace sparse;

int main()
{
    try {
        std::cout << "--- Starting Matrix Market Test ---\n" << std::endl;

        // matrix<double> A = matrix<double>::sparse_readMM("/home/johnzik/Dev/MM_testing/matrices/pores_2.mtx");
        matrix<double> A = matrix<double>::sparse_readMM("/home/johnzik/Dev/MM_testing/matrices/sherman2/sherman2.mtx");

        // Verify if it worked by checking the shape
        std::pair<size_t, size_t> dims = A.shape();
        std::cout << "\nMatrix A loaded successfully into CSR format!" << std::endl;
        std::cout << "Dimensions: " << dims.first << " x " << dims.second << std::endl;

        dense::matrix<double> b_MM = dense::matrix<double>::dense_readMM("/home/johnzik/Dev/MM_testing/matrices/sherman2/sherman2_b.mtx");

        const double* b_ptr = b_MM.get_const_values_data();
        size_t b_size = b_MM.get_size();
        std::vector<double> b(b_ptr, b_ptr + b_size);

        std::vector<double> x0(dims.first, 0.0);
        std::vector<double> x = CG_dsolve(A, b, x0);
        // for(int i = 0; i<dims.first; i++)
        // {
        //     std::cout << x[i] <<' ' << std::endl;
        // }

        std::cout << "Solved!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}