#include <iostream>
#include "../inc/matrix.hpp"
using namespace sparse;

int main()
{
    try {
        std::cout << "--- Starting Matrix Market Test ---\n" << std::endl;

        matrix<double> A = matrix<double>::sparse_readMM("/home/johnzik/Dev/MM_testing/matrices/pores_1.mtx");

        // Verify if it worked by checking the shape
        std::pair<size_t, size_t> dims = A.shape();
        std::cout << "\nMatrix A loaded successfully into CSR format!" << std::endl;
        std::cout << "Dimensions: " << dims.first << " x " << dims.second << std::endl;

        std::vector<double> b(dims.first, 1.0);
        std::vector<double> x0(dims.first, 0.0);
        std::vector<double> x = CG_dsolve(A, b, x0);
        for(int i = 0; i<dims.first; i++)
        {
            std::cout << x[i] <<' ' << std::endl;
        }

        std::cout << "Solved!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}