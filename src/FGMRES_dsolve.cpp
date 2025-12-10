#include "../inc/sparse.hpp"
#include <cstring>
using namespace sparse;
std::vector<double> FGMRES_dsolve(matrix<double> & A, std::vector<double> & b, std::vector<double> & x0){
    double epsilon = 1e-12;
    std::vector<double> x = x0;
    size_t r = A.shape().first;
    size_t c = A.shape().second;
    
    if (r!=c){
        throw std::invalid_argument("Can only solve square matrices");
    }

    size_t mem2 = b.size()*sizeof(double);
    double* b_save = (double*) mkl_malloc(mem2, 64);
    memcpy(b_save, b.data(), mem2);

    int n = (int) r;
    int RCI_request;
    int ipar[128];
    double dpar[128];
    int tmp_size = ((2*std::min(n,150) + 1)*n + std::min(n,150) *(std::min(n,150)  + 9)/2 + 1);
    double tmp[tmp_size]; // Array of size ((2*ipar(15) + 1)*n + ipar(15)*(ipar(15) + 9)/2 + 1). Default for ipar[15] is min(n, 150), so I am assuming that value.
    dfgmres_init(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp);
    dfgmres_check(&n, x.data(), b.data(),&RCI_request, ipar, dpar, tmp);// checks parameters, if pre-set could probably be ommited, maybe expose certain ipar/dpar values to users?
    int itercount;
    int k = 0;
    while (1){
        dfgmres(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp);
        if (RCI_request == 1){     
            std::vector<double> vec (tmp + ipar[21]-1, tmp + ipar[21]-1 + n);
            memcpy(tmp + ipar[22]-1, (vec*A).data(), n*sizeof(double));
            continue;
        }
        if (RCI_request == 2){
            ipar[12]=1;
            // retrieve solution to b_save
            dfgmres_get(&n, x.data(), b_save, &RCI_request, ipar, dpar, tmp, &itercount);
            //perform simple residual test
            std::vector<double> sol(b_save, b_save + n);
            cblas_daxpy((MKL_INT) n, -1.0, b.data(), 0, (sol*A).data(), 0);
            double res = cblas_dnrm2((MKL_INT) n, (sol*A).data(), 0);
            if (res > epsilon){
                continue;
            }
            else{
                break;
            }
        }
        if (RCI_request == 4){
            if (dpar[6] > epsilon){
                continue;
            }
            else{

                break;
            }
        }
        else{
            break;
        }
    }
    ipar[12]=0;
    dfgmres_get(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp, &itercount); // need original b, not b_save which is different
    mkl_free(b_save);
    return x;
}
