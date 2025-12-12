#include"../inc/matrix.hpp"
#include<cstring>
using namespace sparse;

int main() {
    // This set of values produces a divided by zero warning but still a correct result:
        // // RHS b = {1, 1, 1, 1, 1}
        // std::vector<double> b = {1.0, 1.0, 1.0, 1.0, 1.0};
        
        // // Initial guess x0 = {1, 1, 1, 1, 1}
        // std::vector<double> x_guess = {1.0, 1.0, 1.0, 1.0, 1.0};

        // // CSR Representation of the symmetric matrix
        // std::vector<double>  val = {2, -1,  -1, 2, -1,  -1, 2, -1,  -1, 2, -1,  -1, 2};
        // std::vector<MKL_INT> col = {0,  1,   0, 1,  2,   1, 2,  3,   2, 3,  4,   3,  4};
        // std::vector<MKL_INT> row = {0, 2, 5, 8, 11, 13};

    std::vector<double>  val = {2.0, -1.0,  -1.0, 2.0, -1.0,  -1.0, 2.0, -1.0,  -1.0, 2.0, -1.0,  -1.0, 2.0};
    std::vector<MKL_INT> col = {0, 1,      0, 1, 2,      1, 2, 3,      2, 3, 4,      3, 4};
    std::vector<MKL_INT> row = {0, 2, 5, 8, 11, 13};

    // 2. Setup RHS 'b' with messy floats to test real convergence
    std::vector<double> b = {0.1, 0.5, 0.2, 0.8, 0.3};
    
    // 3. Initial Guess (Zero vector is fine)
    std::vector<double> x_guess(5, 0.0);

    // 4. Create Matrix and Solve
    sparse::matrix<double> A(val, col, row, 5, 5);

    std::vector<double> s = CG_dsolve(A, b, x_guess);
    for(int i = 0; i<5; i++){
        std::cout<<s[i]<<' ';
    }
    std::cout<<std::endl;
}