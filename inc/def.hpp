#pragma once

/**
 * @file def.hpp
 * @brief Wrapper header file for the blass functions.
 */
#include <mkl.h>

// Dense blass functions
#define saxpy cblas_saxpy
#define daxpy cblas_daxpy
#define caxpy cblas_caxpy
#define zaxpy cblas_zaxpy

#define sscal cblas_sscal
#define dscal cblas_dscal
#define cscal cblas_cscal
#define zscal cblas_zscal

#define sgemm cblas_sgemm
#define dgemm cblas_dgemm
#define cgemm cblas_cgemm
#define zgemm cblas_zgemm

// Sparse blass functions