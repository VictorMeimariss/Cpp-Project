/**
 * @file dense.hpp
 * @brief Master header file for the matrix class and its associated functions.
 */

#include <iostream>
#include <vector>

/**
 * @class matrix
 * @brief A class to create a dense matrix object of any number of dimensions.
 */
class matrix{
    private:
        /**
         * @brief Flat vector storing all matrix values.
         * Αll set to 0.0 by default.
         */
        std::vector<double> values;
    }