#include "dense.hpp"

int main(){
    dense::matrix<float> A, B, C, D, E;
    A.reshape(2, 1);
    A.set_value_at(0, 1);
    A.set_value_at(1, 1);

    std::cout << "A is supposed to be:\n" << "[1; 1]\n" << "Test Result:" << std::endl;
    A.print2D();

    B.reshape(1, 2);
    B.set_value_at(0, 2);
    B.set_value_at(1, 2);

    std::cout << "B is supposed to be:\n" << "[2, 2]\n" << "Test Result:" << std::endl;
    B.print2D();

    C = A * B;

    std::cout << "C is supposed to be A * B:\n" << "[2, 2; 2, 2]\n" << "Test Result:" << std::endl;
    C.print2D();

    C.reshape(2, 1);
    C.set_value_at(0, 1);
    C.set_value_at(1, 1);

    std::cout << "C has been reshaped and supposed to be:\n" << "[1; 1]\n" << "Test Result:" << std::endl;
    C.print2D();

    D = A + C;

    std::cout << "D is supposed to be A + C:\n" << "[2; 2]\n" << "Test Result:" << std::endl;
    D.print2D();

    E = 2 * D;

    std::cout << "E is supposed to be 2 * D:\n" << "[4; 4]\n" << "Test Result:" << std::endl;
    E.print2D();

    std::cout << "Test using static library end."<< std::endl;
    return 0;
}