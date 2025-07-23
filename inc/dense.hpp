/**
 * @file dense.hpp
 * @brief Master header file for the matrix class and its associated functions.
 */
#pragma once

#include <iostream>
#include <vector>
#include <mkl.h>

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

        /**
         * @brief Vector storing the number of elements separating adjacent values in each dimension of the tensor
         */
        std::vector<int> precomputed_strides;

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
        matrix(Dims... dims){ // Vic

            // Add dimension sizes to the dim_size vector
            (dim_size.push_back(dims), ...);

            // Resizing to the size of the matrix using a fold expression and initialising to 0.0.
            values.resize((static_cast<size_t>(1) * ... * static_cast<size_t>(dims)));
        }

        /**
         * @brief Move constructor, transfers the ownership of matrix A
         * @param  A A matrix reference to be moved
         */
        matrix (matrix&& A){} // Thanasis

        /**
         * @brief Copy constructor, copies matrix A
         * @param  A A constant matrix reference to be copied
         */
        matrix (matrix const& A){} // Ioannis

        /**
         * @brief Destructor, deletes data associated with the matrix
         */
         ~matrix(){} // Vic

        /**
         * @brief Constructs an N by N identity matrix
         * @param N the number of rows/columns in the square identity matrix
         */
        static matrix I(int N){} // Thanasis 

        /**
         * @brief Operator =, creates a deep copy of the matrix and assigns it
         * @param A A constant matrix reference used after the operator
         */
        matrix& operator=(matrix const& A){}; // Ioannis

        /**
         * @brief Operator +, adds the values of two matrices of same size and dimensions
         * @param A A constant matrix reference used after the operator
         */
        matrix operator+(matrix const& A){}; // Vic

        /**
         * @brief Operator *, multiplies two 2D matrices
         * @param A A constant matrix reference used after the operator
         */
        matrix operator*(matrix const& A){}; // Vic

        /**
         * @brief Operator *, multiplies a matrix by a real number
         * @param x A numerical primitive used after the operator
         * @tparam numerical_primative encompasses all primitive numerical data types
         */
        template <typename numerical_primitive>
        matrix operator*(numerical_primitive x){}; 

        /**
         * @brief Operator *, multiplies a real number by a matrix
         * @param x A numerical primitive used before the operator
         * @tparam numerical_primative encompasses all primitive numerical data types
         */
        template <typename numerical_primitive>
        friend matrix operator * (numerical_primitive x, const matrix& A){}

        /**
         * @brief Operator -, subtracts the values of second matrix from the first, both must have same size and dimensions
         * @param A A constant matrix reference used after the operator
         */
        matrix operator-(matrix const& A){}; //Ioannis

        /**
         * @brief Operator /, Performs column-wise augmentation
         * @param A A constant matrix reference to be combined.
         */
        matrix operator/(matrix const& A){};

        /**
         * @brief Operator |, Performs row-wise augmentation
         * @param A A constant matrix reference to be combined.
         */
        matrix operator|(matrix const& A){};

        /**
         * @brief Operator (), returns a writable reference to the value at the coordinates. Variadic index.
         * @tparam index variadic argument for the coordinates of the value to be accesed
         */
        double& operator() (size_t index){} //Vic

        /**
         * @brief Operator (), returns a constant (non-writable) reference to the value at the coordinates. Variadic index.
         * @tparam index variadic argument for the coordinates of the value to be accesed.
         */
        template<typename... Indices>
        const double& operator() (Indices... indices){}


        /**
         * @brief Gets size of matrix.
         */
        size_t get_size() const{} //Thanasis

        /**
         * @brief Gets number of dimensions.
         */
        size_t get_nod() const{} // Ioanis

        /**
         * @brief Gets specified dimension's size using an index.
         * @param index The linear 0-based index in the dim_size vector.
         */
        size_t get_dim_size(size_t index) const{} // Vic

        /**
         * @brief Gets value at a given index.
         * @param index The linear 0-based index in the flat values vector.
         */
        double get_value_at(size_t index) const{} // Thanasis

        /**
         * @brief Sets value at a given index.
         * @param index The linear 0-based index in the flat values vector.
         * @param value The long double value to set.
         */
        void set_value_at(size_t index, long double value){} // Ioannis

        /**
         * @brief Sets all matrix values, clearing any previously stored values and then filling with zeros for the rest.
         * @tparam Types Variadic template arguments for the values to set.
         * @param values The values to set into the matrix
         */
        // Thanasis
         void matrix_multiplication(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE transa, const CBLAS_TRANSPOSE transb, const MKL_INT m, const MKL_INT n, const MKL_INT k, const double alpha, const double *a, const MKL_INT lda, const double *b, const MKL_INT ldb, const double beta, double *c, const MKL_INT ldc){}
        /**
         * @brief Low level implementation of matrix multiplication using BLAS. documentation at https://www.intel.com/content/www/us/en/docs/onemkl/developer-reference-c/2024-1/cblas-gemm-001.html#GUID-97718E5C-6E0A-44F0-B2B1-A551F0F164B2
         */

        template<typename... Types>
        void set_values(Types... valuess){} // Thanasis 
    };