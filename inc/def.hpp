#pragma once
// Victor 
/**
 * @file def.hpp
 * @brief Wrapper header file for the blass functions.
 */
#include <mkl.h>
#include <mkl_spblas.h>

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

#define sgemv cblas_sgemv
#define dgemv cblas_dgemv
#define cgemv cblas_cgemv
#define zgemv cblas_zgemv

#define somatcopy mkl_somatcopy
#define domatcopy mkl_domatcopy
#define comatcopy mkl_comatcopy
#define zomatcopy mkl_zomatcopy

// Sparse functions

#define sparse_s_create_csr mkl_sparse_s_create_csr
#define sparse_d_create_csr mkl_sparse_d_create_csr
#define sparse_c_create_csr mkl_sparse_c_create_csr
#define sparse_z_create_csr mkl_sparse_z_create_csr

#define sparse_destroy mkl_sparse_destroy

#define sparse_convert_csr mkl_sparse_convert_csr

#define sparse_spmm mkl_sparse_spmm

#define sparse_s_export_csr mkl_sparse_s_export_csr
#define sparse_d_export_csr mkl_sparse_d_export_csr
#define sparse_c_export_csr mkl_sparse_c_export_csr
#define sparse_z_export_csr mkl_sparse_z_export_csr

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

#define sparse_s_mv mkl_sparse_s_mv
#define sparse_d_mv mkl_sparse_d_mv
#define sparse_c_mv mkl_sparse_c_mv
#define sparse_z_mv mkl_sparse_z_mv