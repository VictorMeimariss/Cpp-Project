#include "dense.hpp"

int main() {
    matrix<float> A(3,1);
    matrix<float> B(3,1);
    matrix<float> C = A + B;
    std::cout << "Done\n";
    return 0;
}