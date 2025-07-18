/**
 * @file dense.hpp
 * @brief Master header file for the matrix class and its associated functions.
 */
#pragma once

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
         */
        std::vector<long double> values;

        /**
         * @brief Vector storing the size of each dimension.
         */
        std::vector<size_t> dim_size;
    public:
        /**
         * @brief Default constructor.
         * Initializes an empty matrix with zero dimensions and size.
         */
        matrix (){}

        /**
         * @brief Constructor with variadic template input for dimensions.
         * @tparam Dims A variadic pack representing dimension sizes.
         * @param dims The sizes of each dimension.
         */
        template<typename... Dims>
        matrix(Dims... dims){

            // Add dimension sizes to the dim_size vector
            (dim_size.push_back(dims), ...);

            // Resizing to the size of the matrix using a fold expression and initialising to 0.0.
            values.resize((static_cast<size_t>(1) * ... * static_cast<size_t>(dims)));
        }

        /**
         * @brief Operator +, adds the values of two matrices of same size and dimensions
         * @param A A constant matrix reference used after the operator
         */
        matrix operator+(matrix const& A){};

        /**
         * @brief Operator *, multiplies two 2D matrices
         * @param A A constant matrix reference used after the operator
         */
        matrix operator*(matrix const& A){};

        /**
         * @brief Operator -, subtracts the values of second matrix from the first, both must have same size and dimensions
         * @param A A constant matrix reference used after the operator
         */
        matrix operator-(matrix const& A){};

        /**
         * @brief Operator /, will see what will do with it.
         * @param A A constant matrix reference used after the operator
         */
        matrix operator/(matrix const& A){};

        /**
         * @brief Gets size of matrix.
         */
        size_t get_size() const{}

        /**
         * @brief Gets number of dimensions.
         */
        size_t get_nod() const{}

        /**
         * @brief Gets specified dimension's size using an index.
         * @param index The linear 0-based index in the dim_size vector.
         */
        size_t get_dim_size(size_t index) const{}

        /**
         * @brief Gets value at a given index.
         * @param index The linear 0-based index in the flat values vector.
         */
        double get_value_at(size_t index) const{}

        /**
         * @brief Sets value at a given index.
         * @param index The linear 0-based index in the flat values vector.
         * @param value The long double value to set.
         */
        void set_value_at(size_t index, long double value){}

        /**
         * @brief Sets all matrix values, clearing any previously stored values and then filling with zeros for the rest.
         * @tparam Types Variadic template arguments for the values to set.
         * @param valuess The values to set into the matrix
         */
        template<typename... Types>
        void set_values(Types... valuess){}
    };