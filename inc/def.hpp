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

// Sparse functions

#define MKL_Complex8 std::complex<float>
#define MKL_Complex16 std::complex<double>

#define sparse_s_create_csr mkl_sparse_s_create_csr
#define sparse_d_create_csr mkl_sparse_d_create_csr
#define sparse_c_create_csr mkl_sparse_c_create_csr
#define sparse_z_create_csr mkl_sparse_z_create_csr

#define sparse_destroy mkl_sparse_destroy

#define sparse_spmm mkl_sparse_spmm

#define sparse_s_export_csr mkl_sparse_s_export_csr
#define sparse_d_export_csr mkl_sparse_d_export_csr
#define sparse_c_export_csr mkl_sparse_c_export_csr
#define sparse_z_export_csr mkl_sparse_z_export_csr

#define sparse_s_add mkl_sparse_s_add
#define sparse_d_add mkl_sparse_d_add
#define sparse_c_add mkl_sparse_c_add
#define sparse_z_add mkl_sparse_z_add

#define scsrmv mkl_scsrmv
#define dcsrmv mkl_dcsrmv
#define ccsrmv mkl_ccsrmv
#define zcsrmv mkl_zcsrmv

#define sparse_s_mm mkl_sparse_s_mm
#define sparse_d_mm mkl_sparse_d_mm
#define sparse_c_mm mkl_sparse_c_mm
#define sparse_z_mm mkl_sparse_z_mm