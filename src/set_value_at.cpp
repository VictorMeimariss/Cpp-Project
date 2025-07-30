#include <../inc/dense.hpp>
using namespace std;

/**
 * @brief Sets value at a given index.
 * @param index The linear 0-based index in the flat values vector.
 * @param value The long double value to set.
 */
void matrix::set_value_at(size_t index, long double value)
{
    values.at(index) = value;
}
