#include <dense.hpp>

int main() {
    matrix<float> A(2,1);
    A.set_value_at(0, 1);
    A.set_value_at(1, 3.5);

    matrix<float> B(1,2);
    B.set_value_at(0, 1);
    B.set_value_at(1, 5.2);

    matrix<float> C = A * B;
    
    std::cout << "Test Expected Answer:\n" << "[(1,1), (5.2,5.2); (3.5,1), (18.2,5.2)]\n\n" << "Test Result:" << std::endl;
    C.print2D();
    std::cout << "A(expected [(1,1); (3.5,1)]):"<<std::endl;
    A.print2D();
    std::cout << "B(expected [(1,0), (5.2,0)]):"<<std::endl;
    B.print2D();
    return 0;
}