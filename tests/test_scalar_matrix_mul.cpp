#include <dense.hpp>
using namespace dense;


int main() {
    using cd = std::complex<double>;

    matrix<std::complex<double>> A(2,1);
    A.set_value_at(0,cd(1, 1));
    A.set_value_at(1, cd(3.5, 1));
    
    matrix<std::complex<double>> C = cd(2, 0) * A;
    
    std::cout << "Test 1 Expected Answer:\n" << "[(2,2); (7,2)]\n\n" << "Test Result:" << std::endl;
    C.print2D();
    std::cout << "A(expected [(1,1); (3.5,1)]):"<<std::endl;
    A.print2D();
    
    matrix<double> B(2,1);
    B.set_value_at(0, 1);
    B.set_value_at(1, 2);

    matrix<double> D = 2 * B;
    
    std::cout << "Test 2 Expected Answer:\n" << "[2; 4]\n\n" << "Test Result:" << std::endl;
    D.print2D();
    std::cout << "B(expected [1; 2]):"<<std::endl;
    B.print2D();
    return 0;
}