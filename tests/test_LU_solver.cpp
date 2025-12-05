#include <../inc/matrix.hpp>
using namespace dense;


int main() {
    matrix<float> A(2,2);
    A.set_value_at(0,1.0);
    A.set_value_at(1,2.0);
    A.set_value_at(2,3.0);
    A.set_value_at(3,-5.0);
    std::vector<float> b = {1.0, 1.0};
    std::vector<float> res = LU_solver(A, b);
    for (auto i: res){
        std::cout<<i<<' '<<std::endl;
    }
}