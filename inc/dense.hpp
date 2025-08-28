#ifndef DENSE_HPP
#define DENSE_HPP

/**
 * @file dense.hpp
 * @brief Master header file for the matrix class and its associated functions.
 */
#pragma once

#include <iostream>
#include <vector>
#include <complex>
#include "def.hpp"

/**
 * @class matrix
 * @brief A class to create a dense matrix object of any number of dimensions.
 * @tparam T The scalar type used for matrix elements.
 */
template<typename T>
class matrix {
    private:
        /**
         * @brief Flat vector storing all matrix values.
         */
        std::vector<T> values; 

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
        matrix (){};

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

            // Resizing to number of dimensions
            precomputed_strides.resize(dim_size.size());
            if (!precomputed_strides.empty()) { 
                precomputed_strides.back() = 1; // Last dimension has stride 1

                for (int i = precomputed_strides.size() - 2; i >= 0; --i) {
                    precomputed_strides[i] = precomputed_strides[i + 1] * dim_size[i + 1];
                }
            }
        }

        /**
         * @brief Move constructor, transfers the ownership of matrix A
         * @param  A A matrix reference to be moved
         */
        matrix (matrix&& A) noexcept
        : values(std::move(A.values)), dim_size(std::move(A.dim_size)), precomputed_strides(std::move(A.precomputed_strides)) {}
        
        /**
         * @brief Copy constructor, copies matrix A
         * @param  A A constant matrix reference to be copied
         */
        matrix (matrix const& A); // Ioannis

        /**
         * @brief Destructor, deletes data associated with the matrix
         */
         ~matrix() = default; // Vic

        /**
         * @brief Constructs an N by N identity matrix
         * @param N the number of rows/columns in the square identity matrix
         */
        matrix I(int N); // Thanasis 

        /**
         * @brief Operator =, creates a deep copy of the matrix and assigns it
         * @param A A constant matrix reference used after the operator
         */
        matrix& operator=(matrix const& A); // Ioannis

        /**
         * @brief Operator +, adds the values of two matrices of same size and dimensions
         * @param A A constant matrix reference used after the operator
         */
        matrix operator+(matrix const& A); // Vic

        /**
         * @brief Operator *, multiplies two 2D matrices
         * @param A A constant matrix reference used after the operator
         */
        matrix operator*(matrix const& A); // Vic
        /**
         * @brief Operator ==, compares two matricies
         * @param A A constant matrix reference used after the operator
         */
        bool operator==(matrix const& A){
            if (dim_size.size() != A.dim_size.size())
                return false;
            else{
                for (int i = 0; i<dim_size.size(); i++){
                    if (dim_size[i]!=A.dim_size[i]){
                        return false;
                    }
                }
                for (int i=0; i<values.size(); i++){
                    if (values[i]!=A.values[i])
                        return false;
                }
            }
            return true;
        }
        /**
         * @brief Operator *, multiplies a matrix by a number
         * @param x A numerical primitive used after the operator
         * @tparam T encompasses all primitive numerical data types
         */
        matrix operator*(T x);

        /**
         * @brief Operator -, subtracts the values of second matrix from the first, both must have same size and dimensions
         * @param A A constant matrix reference used after the operator
         */
        matrix operator-(matrix const& A); //Ioannis

        /**
         * @brief Operator /, Performs column-wise augmentation
         * @param A A constant matrix reference to be combined.
         */
        matrix operator/(matrix const& A);

        /**
         * @brief Operator |, Performs row-wise augmentation
         * @param A A constant matrix reference to be combined.
         */
        matrix operator|(matrix const& A);

        /**
         * @brief Operator (), returns a writable reference to the value at the coordinates. Variadic index.
         * @tparam index variadic argument for the coordinates of the value to be accesed
         */
        T& operator() (size_t index); //Vic

        /**
         * @brief Operator (), returns a constant (non-writable) reference to the value at the coordinates. Variadic index.
         * @tparam index variadic argument for the coordinates of the value to be accesed.
         */
        template<typename... Indices>
        const T& operator() (Indices... indices);


        /**
         * @brief Gets size of matrix.
         */
        size_t get_size() const; //Victor

        /**
         * @brief Gets number of dimensions.
         */
        size_t get_nod() const; // Ioanis

        /**
         * @brief Gets specified dimension's size using an index.
         * @param index The linear 0-based index in the dim_size vector.
         */
        size_t get_dim_size(size_t index) const; // Thanasis

        /**
         * @brief Gets value at a given index.
         * @param index The linear 0-based index in the flat values vector.
         */
        T get_value_at(size_t index) const; // Thanasis

        /**
         * @brief Gets all values data.
         */
        T* get_values_data(); // Victor

        /**
         * @brief Sets value at a given index.
         * @param index The linear 0-based index in the flat values vector.
         * @param value The templated value to set.
         */
        void set_value_at(size_t index, T value); // Ioannis

        /**
         * @brief Sets all matrix values, clearing any previously stored values and then filling with zeros for the rest.
         * @tparam Types Variadic template arguments for the values to set.
         * @param valuess The values to set into the matrix
         */
        template<typename... Types>
        void set_values(Types&&... valuess){
            std::vector<T> v;
            (v.push_back(valuess), ...);
            values = std::move(v);
        }

        /**
         * @brief returns a constant pointer to the underlying vector array values
         */
        const T* get_const_values_data();
        
        /**
         * @brief Prints the values of 2D array
         */
        void print2D();

        /**
         * @brief Reshapes matrix after default constuctor initialisation
         * @tparam Dims A variadic pack representing dimension sizes.
         * @param dims The sizes of each dimension.
        */
       template<typename... Dims>
       void reshape(Dims... dims){
        //Clear previous dimensions size
        dim_size.clear();
        // Add dimension sizes to the dim_size vector
        (dim_size.push_back(dims), ...);

        // Resizing to the size of the matrix using a fold expression and initialising to 0.0.
        values.resize((static_cast<size_t>(1) * ... * static_cast<size_t>(dims)));

        // Resizing to number of dimensions
        precomputed_strides.resize(dim_size.size());
        if (!precomputed_strides.empty()) { 
            precomputed_strides.back() = 1; // Last dimension has stride 1

            for (int i = precomputed_strides.size() - 2; i >= 0; --i) {
                precomputed_strides[i] = precomputed_strides[i + 1] * dim_size[i + 1];
            }
        }
        };
    /**
     * @brief Low level implementation of matrix multiplication using BLAS. documentation at https://www.intel.com/content/www/us/en/docs/onemkl/developer-reference-c/2024-1/cblas-gemm-001.html#GUID-97718E5C-6E0A-44F0-B2B1-A551F0F164B2
     * @tparam T encompasses matrix type
     */
    void low_level_matrix_multiplication(const CBLAS_TRANSPOSE transa, const CBLAS_TRANSPOSE transb, const T beta, matrix<T> const &A, matrix<T> const &B, matrix<T> &C, const T alpha);    
    };
    /**
     * @brief Operator *, multiplies a number by a type float matrix
     * @param x A numerical primitive used before the operator
     * @tparam U encompasses all primitive numerical data types and T, the matrix type
     */
    template<typename T, typename U>
    matrix<T> operator*(U x, const matrix<T>& A);
#endif
