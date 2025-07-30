#include <../inc/dense.hpp>
using namespace std;

/**
 * @brief Gets number of dimensions.
 */
size_t matrix::get_nod() const
{
    return dim_size.size();
}