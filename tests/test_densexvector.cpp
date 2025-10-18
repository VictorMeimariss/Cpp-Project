#include <dense.hpp>
using namespace dense;


int main() {
    using cd = std::complex<double>;

    matrix<std::complex<double>> A(1,2);
    A.set_value_at(0, cd(1, 1));
    A.set_value_at(1, cd(3.5, 1));

    std::vector<cd> vector = {cd(1, 1), cd(2, 2)};
    
    vector = A * vector;
    
    std::cout << "Test Expected Answer for sparse x scalar: (5,11)\n"<< "Test Result: ";
    for (auto i: vector){
        std::cout << i <<" ";
    }
    std::cout << "\n";
    return 0;
}