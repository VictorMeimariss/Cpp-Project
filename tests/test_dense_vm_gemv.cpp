#include<iostream>
#include <../inc/dense.hpp>
using namespace dense;

int main()
{
    std::cout << "\n===========================================================" << std::endl;
    std::cout << " Testing the vector - dense matrix multiplication function" << std::endl;
    std::cout << "===========================================================" << std::endl;

    using cf = std::complex<float>;

    // --- Float Vector - Dense Matrix Multiplication ---

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "      Float Vector - Dense Matrix Multiplication" << std::endl;
    std::cout << "===========================================================" << std::endl;

    std::vector<float> Vf = {2,2}; // float vector

    matrix<float> Mf(2,2);
    Mf.set_value_at(0, 2);
    Mf.set_value_at(1, 3);
    Mf.set_value_at(2, 4);
    Mf.set_value_at(3, 5);
    std::cout << "\nM float matrix:" << std::endl;
    Mf.print2D();

    std::vector<float> res_f = Vf*Mf;

    std::cout << "Expected res: [12, 16]" << std::endl;
    std::cout << "Result vector res_f: [ ";
    for (size_t i = 0; i < res_f.size(); ++i) {
        std::cout << res_f[i];
        if (i < res_f.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;

    // --- Complex Float Vector - Dense Matrix Multiplication ---

    std::cout << "\n===========================================================" << std::endl;
    std::cout << "      Complex Float Vector - Dense Matrix Multiplication" << std::endl;
    std::cout << "===========================================================" << std::endl;

    std::vector<cf> Vcf = {3,4}; // complex float vector

    matrix<cf> Mcf(2,2);
    Mcf.set_value_at(0, 2);
    Mcf.set_value_at(1, 3);
    Mcf.set_value_at(2, 4);
    Mcf.set_value_at(3, 5);
    std::cout << "\nM complex float matrix:" << std::endl;
    Mcf.print2D();

    std::vector<cf> res_cf = Vcf*Mcf;

    std::cout << "Expected res: [22, 29]" << std::endl;
    std::cout << "Result vector res_f: [ ";
    for (size_t i = 0; i < res_cf.size(); ++i) {
        std::cout << res_cf[i];
        if (i < res_cf.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;
}