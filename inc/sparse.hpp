#ifndef SPARSE_HPP
#define SPARSE_HPP

#include <iostream>
#include <vector>
#include <complex>
#include <mkl.h>
namespace rixoratory{
/**
 * @class matrix
 * @brief A class to create a sparse matrix object in csr form
 * @tparam T The scalar type used for matrix elements.
 */
template <typename T>
class matrix
{
    private:

        /**
         * @brief Flat vector storing the values of non zero elements.
         */
        std::vector<T> values; 

        /**
         * @brief Flat vector storing the columns of non-zero elements
         */
        std::vector<T> col_idx;

        /**
         * @brief Flat vector marking the begining of each row in the values vector
         */
        std::vector<T> row_idx;

        /**
         * @brief Rows size.
         */
        size_t row_size;

        /**
         * @brief Columns size.
         */
        size_t col_size;

        bool ownership; // True if ours, false if intels
    public:
    /**
         * @brief Sparse matrix constructor
         * @param values sets the values vector
         * @param col_idx sets the col_idx vector
         * @param row_idx sets the row_idx vector
         * @param rows sets row size
         * @param cols sets column size
         */
    matrix(const std::vector<T>& values, const std::vector<T>& col_idx, const std::vector<T>& row_idx, size_t rows, size_t cols)
    : values(values), col_idx(col_idx), row_idx(row_idx), row_size(rows), col_size(cols), ownership(true)
    {

    }
    /**
         * @brief Sparse matrix destructor
         */
    ~matrix;
    /**
         * @brief Move constructor, transfers the ownership of matrix A
         * @param  A A matrix reference to be moved
         */
    matrix (matrix&& A) noexcept        
    : values(std::move(A.values)), col_idx(std::move(A.col_idx)), row_idx(std::move(A.row_idx),row_size(A.rows), col_size(A.cols), ownership(A.ownership)) {
        A.row_size=0;
        A.col_size=0;
        ownership=false;    
    }
    /**
         * @brief Matrix copy constructor
         * @param A A constant sparse matrix reference to be copied 
         */
    matrix (matrix const& A);
    /**
         * @brief Constructs an N by N identity matrix
         * @param N the number of rows/columns in the square identity matrix
         */
    matrix I(int N);
    
    //operators
    
    /**
         * @brief Operator =, creates a deep copy of the matrix and assigns it
         * @param A A constant matrix reference used after the operator
         */
    matrix& operator=(matrix const& A); 
    /**
         * @brief Operator +, adds the values of two matrices of same size and dimensions
         * @param A A constant matrix reference used after the operator
         */
    matrix operator+(matrix const& A);
    /**
         * @brief Operator *, multiplies two 2D matrices
         * @param A A constant matrix reference used after the operator
         */
    matrix operator*(matrix const& A);//Could be excluded (for now)
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
    matrix operator-(matrix const& A);
    /**
         * @brief Operator ==, compares two matricies
         * @param A A constant matrix reference used after the operator
         */
    bool operator==(matrix const& A);
    //getters-setters
    /**
         * @brief Gets value at a given index.
         * @param index The linear 0-based index in the flat values vector.
         */
    T get_value_at(size_t index) const;
    /**
         * @brief Sets value at a given index.
         * @param index The linear 0-based index in the flat values vector.
         * @param value The value to set.
         */ 
    set_value_at(size_t index, T value);
    /**
         * @brief Returns a mutable reference to a non-zero value in the matrix.
         * @param c The column of the value to be returned.
         * @param r The row of the value to be returned.
         */   
    T& operator() (size_t r, size_t c);
    /**
         * @brief Returns a constant value in the matrix.
         * @param c The column of the value to be returned.
         * @param r The row of the value to be returned.
         */  
    const T operator() (size_t r, size_t c) const;
    /**
         * @brief Returns the shape (dimensions) of a matrix
         */  
    vector<size_t> shape() const;
    //sparse specific (for solvers etc)
    /**
         * @brief Returns a mutable vector reference containing the diagonal elements of a matrix. For writting.
         */ 
    std::vector<T>& diag();
    /**
         * @brief Returns a constant vector reference containing the diagonal elements of a matrix. For reading.
         */
    const std::vector<t>& diag const;
    /**
         * @brief Operator *, multiplies a matrix by an stl vector
         * @param v A vector used after the operator
         */
    std::vector<T> operator*(std::vector<T> const& v);
};
}
#endif