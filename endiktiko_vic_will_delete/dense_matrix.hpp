/**
 * @file dense_matrix.hpp
 * @brief Header file for the dense_matrix class and its associated functions.
 *
 * This file defines a generic dense_matrix class capable of representing
 * matrices of any number of dimensions (up to 4.93 billion elements total).
 * It provides constructors, getters, setters, and utility functions for
 * matrix manipulation, including 2D matrix multiplication.
 */

#pragma once // Ensures this header file is included only once during compilation.

#include <iostream>      // Required for std::cout, std::endl, std::to_string, std::invalid_argument, std::out_of_range, printf
#include <vector>        // Required for std::vector
#include <type_traits>   // Required for std::is_integral_v
#include <stdexcept>     // Required for std::runtime_error

/**
 * @class dense_matrix
 * @brief A class to create a dense matrix object of any number of dimensions.
 *
 * This class stores matrix elements in a single flat std::vector<double> in
 * row-major order. It supports construction with a variadic number of
 * dimensions, copying, and basic element access.
 */
class dense_matrix{
    private:
        /**
         * @brief Total number of elements in the matrix.
         * Calculated as the product of all dimension sizes.
         */
        size_t size = 0;

        /**
         * @brief Flat vector storing all matrix values in row-major order.
         * Initialized to size elements, all set to 0.0 by default.
         */
        std::vector<double> values;

        /**
         * @brief Number of dimensions of the matrix.
         */
        unsigned short int nod = 0;

        /**
         * @brief Vector storing the size of each dimension.
         */
        std::vector<size_t> dim_size;

    public:
        /**
         * @brief Default constructor.
         * Initializes an empty matrix with zero dimensions and size.
         */
        dense_matrix (){
            //std::cout<<"Default";
        };

        /**
         * @brief Constructor with variadic template input for dimensions.
         * @tparam Dims A variadic pack of integral types representing dimension sizes.
         * @param dims The sizes of each dimension.
         * @throws std::invalid_argument If any dimension argument is not an integral type or is not positive.
         */
        template<typename... Dims>
        dense_matrix(Dims... dims){

            // Checking if all inputs are positive integrals
            static_assert((std::is_integral_v<Dims> && ...), "All dimension arguments to dense_matrix constructor must be integrals.");
            if (!((dims > 0) && ...)) {
                throw std::invalid_argument("All dimensions must be greater than 0.");
            }
            //std::cout<<"Variad";
            //Fold expression
            size = (static_cast<size_t>(1) * ... * static_cast<size_t>(dims)); 

            // Add dimension sizes to the dim_size vector
            (dim_size.push_back(dims), ...);
            
            // Number of dimensions is the argument count of Dims
            nod = sizeof...(Dims);

            // Resizing to the size of the matrix and initialising to 0.0.
            values.resize(size);
        }

        // Operator overloading
        /**
         * @brief Operator +, adds the values of two matrices of same size and dimensions
         * @param A A constant dense_matrix reference used after the operator
         * @throws std::invalid argument if there is a dimensions or size mismatch
         */
        dense_matrix operator+(dense_matrix const& A){
            if((nod != A.nod) || (size != A.size)){
                throw std::invalid_argument("Matrices added must be of same size and dimensions");
            };
            // Initialising matrix B as A since every aspect is the same except for their values
            dense_matrix B = A;

            // Adding vector values 
            for(size_t i = 0; i < values.size(); i++){
                B.values[i] = values[i] + A.values[i];
            };
            return B;
        };

        /**
         * @brief Gets size of matrix.
         */
        size_t get_size() const{
            return size;
        }

        /**
         * @brief Gets number of dimensions.
         */
        unsigned short int get_nod() const{
            return nod;
        }

        /**
         * @brief Gets specified dimension's size using an index.
         * @tparam An integral type for the index.
         * @param index The linear 0-based index in the dim_size vector.
         * @throws std::out_of_range If the index provided is out of bounds.
         */
        template<typename T>
        size_t get_dim_size(T index) const{
            // Must be integral
            static_assert(std::is_integral_v<T>, "Index must be an integral type (e.g., int, size_t, long).");

            // Checking if index is out of bounds.If index is negative it becomes huge, far exceeding size
            if((index >= dim_size.size()) || (index < 0)){
                throw std::out_of_range("The index is out of bounds. Should be >=0 and less than its size: "+ std::to_string(dim_size.size()));
            };
            return dim_size[index];
        }
        /**
         * @brief Gets value at a given index.
         * @tparam An integral type for the index.
         * @param index The linear 0-based index in the flat values vector.
         * @throws std::out_of_range If the index provided is out of bounds.
         */
        template<typename T>
        double get_value_at(T index) const{
            // Must be integral
            static_assert(std::is_integral_v<T>, "Index must be an integral type (e.g., int, size_t, long).");

            // Checking if index is out of bounds
            if((index >= size) || (index < 0)){
                throw std::out_of_range("The index is out of bounds.Should be >=0 and less than its size: "+ std::to_string(size));
            };
            double value;
            value = values[index];
            return value;
        }

        /**
         * @brief Sets value at a given index.
         * @tparam An integral type for the index.
         * @param index The linear 0-based index in the flat values vector.
         * @param value The long double value to set.
         * @throws std::out_of_range If the index provided is out of bounds.
         */
        template<typename T>
        void set_value_at(T index, long double value){
            // Must be integral
            static_assert(std::is_integral_v<T>, "Index must be an integral type (e.g., int, size_t, long).");

            // Checking if index is out of bounds.If index is negative it becomes huge, far exceeding size
            if((index >= size) || (index < 0)){
                throw std::out_of_range("The index is out of bounds.Should be >=0 and less than its size: "+ std::to_string(size));
            };
            values[index] = value;
        }

        /**
         * @brief Sets all matrix values, clearing any previously stored values and then filling with zeros for the rest.
         * @tparam Types Variadic template arguments for the values to set.
         * @param valuess The values to set into the matrix
         * @throws std::out_of_range If the number of provided values exceeds the matrix's total size.
         */
        template<typename... Types>
        void set_values(Types... valuess){
            // Throw exception if out of bounds
            if((sizeof... (valuess)) > size){
                throw std::out_of_range("The number of values should be less or equal to the size of the matrix: "+ std::to_string(size));
            };
            values.clear();
            (values.push_back(valuess), ...);
            while(values.size() < size) {
                values.push_back(0); // Fill the rest of the slots with zero
            }
        }

        /**
         * @brief Prints the matrix to the console numbering starts from the left and up going to down and right.
         * Currently supports only 2D matrices.
         * @param precision The number of decimal places to print for each value.
         * @throws std::runtime_error If the matrix is not 2-dimensional.
         */
        void print_2D_matrix(short int precision) {
            // Error handling for incorrect number of dimensions
            if(nod != 2){
                throw std::runtime_error("Matrix must have 2 dimensions...");
            };

            size_t rows = dim_size[0];
            size_t colls = dim_size[1];
            short int c_w = 7; // collumn witdth
            for(size_t i = 0; i < rows; i++){
                for(size_t k = 0; k < colls; k++){
                    printf("%*.*f", c_w, precision, values[k + i * colls]);
                };
                std::cout<<std::endl;
            };
        }
        friend dense_matrix multiply_2D(const dense_matrix &A, const dense_matrix &B);
};

// Functions using dense_matrix objects.

/**
 * @brief Multiplies two 2D dense matrices (A * B).
 * @param A The first dense_matrix (left operand).
 * @param B The second dense_matrix (right operand).
 * @return A new dense_matrix representing the product C = A * B.
 * @throws std::runtime_error If matrices are not 2D or their dimensions are incompatible for multiplication.
 */
dense_matrix multiply_2D(const dense_matrix &A, const dense_matrix &B){
    
    // Error handling for incorrect number of dimensions
    if((A.nod != 2) || (B.nod != 2)){ 
        throw std::runtime_error("Matrices must have 2 dimensions...");
    };
    size_t A_coll = A.dim_size[1];
    // Error handling for incorrect size of dimensions
    if(A_coll != B.dim_size[0]){
        throw std::runtime_error("Matrix A's second dimension must have the same size as matrix B's first...");
    };

    //Initialising product matrix
    size_t C_rows, C_coll;
    C_rows = A.dim_size[0];
    C_coll = B.dim_size[1]; // Also B_coll
    dense_matrix C(C_rows, C_coll);

    // for loops doing the multiplication
    for(size_t k = 0; k < C_rows; k++){ // Iterate over C's rows as well as A's
        for(size_t j = 0; j < C_coll; j++){ // Iterate over C's collumns as well as B's
            double sum = 0;
            for(size_t i = 0; i < A_coll; i++){
                sum += A.values[i + A_coll * k] * B.values[i * C_coll + j];
            };
            C.values[j + k * C_coll] = sum;
        };
    };
    return C;
};