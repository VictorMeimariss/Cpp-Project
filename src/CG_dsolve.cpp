#include "../inc/sparse.hpp"
#include <cstring>
using namespace sparse;

std::vector<double> CG_dsolve(matrix<double> & A, std::vector<double> & b, std::vector<double> & x0)
{
    double tol = 1e-12;
    std::vector<double> x = x0;
    size_t row = A.shape().first;
    size_t col = A.shape().second;

    if (row!=col){
        throw std::invalid_argument("Can only solve square matrices");
    }

    // Initialize CG parameters
    MKL_INT n = (MKL_INT) row;
    MKL_INT RCI_request;
    MKL_INT ipar[128];
    double dpar[128];
    std::vector<double> tmp(n*4);   // Double array of size (n*4) for SRHS
                                    // We must store tmp on the heap to avoid stack overflow

    /**
     * Initialize the solver
     * Advanced users can skip this step and set the values in the ipar and dpar arrays directly.
     */
    dcg_init(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp.data());

    /**
     * Check the consistency and correctness of the parameters to be passed to the solver routine.
     * Only reduces the chance of making a mistake.
     * Skip this operation only if you are sure that the correct data is specified in the solver parameters.
     */
    dcg_check(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp.data());

    int iter;
    dpar[0] = tol;

    // Pre-allocate the vec for RCI_request == 1 for efficiency (to avoid re-allocation in loop)
    std::vector<double> vec(n);
    while (1)
    {
        dcg(&n, x.data(), b.data(), &RCI_request, ipar, dpar, tmp.data());

        if (RCI_request == -1)
        {
            std::cout << "Maximum number of iterations was reached, but the relative stopping criterion was not met." << std::endl;
            break;
        }
        else if (RCI_request == -2)
        {
            std::cout << "Attempted to divide by zero!" << std::endl;
            break;
        }
        else if (RCI_request == 1)
        {
            memcpy(vec.data(), tmp.data(), n*sizeof(double));           // copy temp to vec
            memcpy(tmp.data() + n, (A*vec).data(), n*sizeof(double));   // put the result in the tmp[n:2*n - 1]
            continue;
        }
        else if (RCI_request == 0)
        {
            std::cout << "Converged succesfully!" << std::endl;
            break;
        }
    }
    dcg_get(&n , x.data(), b.data(), &RCI_request, ipar, dpar, tmp.data(), &iter);
    return x;
}