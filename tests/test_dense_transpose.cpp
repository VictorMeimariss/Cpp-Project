#include <dense.hpp>
using namespace dense;


int main() {
    matrix<float> A(3,1);
    A.set_value_at(0, 2);
    A.set_value_at(1, 4);
    A.set_value_at(2, 3.5);

    matrix<float> C = A.transpose();
    std::cout << "Test Expected Answer:\n" << "[2, 4, 3.5]\n\n" << "Test Result:" << std::endl;
    C.print2D();
    return 0;
}