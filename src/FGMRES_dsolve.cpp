#include "../inc/sparse.hpp"
#include <cstring>
using namespace sparse;
std::vector<double> FGMRES_dsolve(matrix<double> & A, std::vector<double> & b, std::vector<double> & x0, bool preconditioned, matrix<double> &M){
    double epsilon = 1e-12;
    std::vector<double> x = x0;
    size_t r = A.shape().first;
    size_t c = A.shape().second;
    
    if (r!=c){
        throw std::invalid_argument("Can only solve square matrices");
    }

    int n = (int) r;
    int RCI_request;
    int ipar[128];
    double dpar[128];
    int tmp_size = ((2*std::min(n,150) + 1)*n + std::min(n,150) *(std::min(n,150)  + 9)/2 + 1);
    double * tmp = (double*)mkl_malloc(tmp_size*sizeof(double),64);
    
    dfgmres_init(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp);
    
    ipar[11] = 1;
    ipar[9] = 0;
    ipar[10] = (int) preconditioned;
    dpar[0] = epsilon;
    
    dfgmres_check(&n, x.data(), b.data(),&RCI_request, ipar, dpar, tmp);
    
    int itercount;
    std::vector<double> vec(n);

    while (1){
        dfgmres(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp);
        if (RCI_request == 1){
            memcpy(vec.data(), tmp + ipar[21]-1, n*sizeof(double));           
            memcpy(tmp + ipar[22]-1, (A*vec).data(), n*sizeof(double));
            
            continue;
        }
        else if (RCI_request == 3){
           memcpy(vec.data(), tmp + ipar[21]-1, n*sizeof(double));
           memcpy(tmp + ipar[22]-1, (M*vec).data(), n*sizeof(double));

            continue;
        }
        if (RCI_request == 0){
           break;
        }
    }
    dfgmres_get(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp, &itercount);
    return x;
}
