#ifndef CROSS_HPP
#define CROSS_HPP

/**
 * @file cross.hpp
 * @brief Header file for the cross product functions of dense and sparse matrices.
 */

#include <iostream>
#include <vector>
#include <complex>
#include "dense.hpp"
#include "sparse.hpp"
#include "def.hpp"

/**
* @brief Operator *, multiplies two 2D dense and sparse matrices returning a dense matrix
* @param A A constant matrix reference used after the operator
* @param B A constant matrix reference used after the operator
*/
template<typename T>
dense::matrix<T> operator*(const dense::matrix<T>& A, const sparse::matrix<T>& B);

/**
* @brief Operator *, multiplies two 2D sparse and dense matrices returning a dense matrix
* @param A A constant matrix reference used after the operator
* @param B A constant matrix reference used after the operator
*/
template<typename T>
dense::matrix<T> operator*(const sparse::matrix<T>& A, const dense::matrix<T>& B);

#endif