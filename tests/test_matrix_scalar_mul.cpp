#include <dense.hpp>

int main() {
    using cd = std::complex<double>;

    matrix<std::complex<double>> A(2,1);
    A.set_value_at(0,cd(1, 1));
    A.set_value_at(1, cd(3.5, 1));

    matrix<std::complex<double>> C = A * cd(2, 0);
    
    std::cout << "Test Expected Answer:\n" << "[(2,2); (7,2)]\n\n" << "Test Result:" << std::endl;
    C.print2D();
    std::cout << "A(expected [(1,1); (3.5,1)]):"<<std::endl;
    A.print2D();
    return 0;
}