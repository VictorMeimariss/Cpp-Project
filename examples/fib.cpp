#include<iostream>
#include <../inc/dense.hpp>
using namespace dense;
int fib(int n){
    matrix<double> M(2,2);
    M.set_value_at(0,0);
    M.set_value_at(1,1);
    M.set_value_at(2,1);
    M.set_value_at(3,1);

    matrix<double> A = M^(n+1);
    return A.get_value_at(0);
}

int main(){
    int n;
    std::cin >> n;
    std::cout<<fib(n)<<std::endl;
}
