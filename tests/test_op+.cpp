#include <dense.hpp>
using namespace dense;


int main() {
    matrix<float> A(3,1);
    A.set_value_at(0, 2);
    A.set_value_at(1, 4);
    A.set_value_at(2, 3.5);

    matrix<float> B(3,1);
    B.set_value_at(0, 1);
    B.set_value_at(1, 5.2);
    B.set_value_at(2, 3.1);

    matrix<float> C = A + B;
    std::cout << "Test Expected Answer:\n" << "[3; 9.2; 6.6]\n\n" << "Test Result:" << std::endl;
    C.print2D();
    std::cout << "A(expected [2; 4; 3.5]):"<<std::endl;
    A.print2D();
    std::cout << "B(expected [1; 5.2; 3.1]):"<<std::endl;
    B.print2D();
    return 0;
}