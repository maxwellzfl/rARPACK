#include <Rcpp.h>
#include "matops.h"

MatProd* get_mat_prod_op(SEXP mat, int n, SEXP extra_arg, int mat_type)
{
    MatProd *op;
    
    Rcpp::List args(extra_arg);
    
    switch(mat_type)
    {
    case MATRIX:
        op = new MatProd_matrix(mat, n, n);
        break;
    case SYMMATRIX:
        {
        bool use_lower = Rcpp::as<bool>(args["use_lower"]);
        op = new MatProd_symmatrix(mat, n, use_lower ? 'L' : 'U');
        }
        break;
    case DGEMATRIX:
        op = new MatProd_dgeMatrix(mat, n, n);
        break;
    case DSYMATRIX:
        {
        bool use_lower = Rcpp::as<bool>(args["use_lower"]);
        op = new MatProd_dsyMatrix(mat, n, use_lower ? 'L' : 'U');
        }
        break;
    case DGCMATRIX:
        op = new MatProd_dgCMatrix(mat, n, n);
        break;
    case DGRMATRIX:
        op = new MatProd_dgRMatrix(mat, n, n);
        break;
    case FUNCTION:
        {
        SEXP fun_args = args["fun_args"];
        op = new MatProd_function(mat, n, fun_args);
        }
        break;
    default:
        Rcpp::stop("unsupported matrix type");
        // Eliminate compiler warning, but should not reach here
        op = new MatProd_matrix(mat, n, n);
    }
    
    return op;
}

RealShift* eigs_sym_get_real_shift_op(SEXP mat, int n, SEXP extra_arg, int mat_type)
{
    RealShift *op;
    
    Rcpp::List args(extra_arg);
    
    switch(mat_type)
    {
    case MATRIX:
        op = new RealShift_matrix(mat, n);
        break;
    case SYMMATRIX:
        {
        bool use_lower = Rcpp::as<bool>(args["use_lower"]);
        op = new RealShift_symmatrix(mat, n, use_lower ? 'L' : 'U');
        }
        break;
    case DGEMATRIX:
        op = new RealShift_dgeMatrix(mat, n);
        break;
    case DSYMATRIX:
        {
        bool use_lower = Rcpp::as<bool>(args["use_lower"]);
        op = new RealShift_dsyMatrix(mat, n, use_lower ? 'L' : 'U');
        }
        break;
    case DGCMATRIX:
        op = new RealShift_dgCMatrix(mat, n);
        break;
    case DGRMATRIX:
        op = new RealShift_dgRMatrix(mat, n);
        break;
    default:
        Rcpp::stop("unsupported matrix type");
        // Eliminate compiler warning, but should not reach here
        op = new RealShift_matrix(mat, n);
    }
    
    return op;
}

RealShift* eigs_gen_get_real_shift_op(SEXP mat, int n, SEXP extra_arg, int mat_type)
{
    RealShift *op;
    
    Rcpp::List args(extra_arg);
    
    switch(mat_type)
    {
    case MATRIX:
        op = new RealShift_matrix(mat, n);
        break;
    case DGEMATRIX:
        op = new RealShift_dgeMatrix(mat, n);
        break;
    case DGCMATRIX:
        op = new RealShift_dgCMatrix(mat, n);
        break;
    case DGRMATRIX:
        op = new RealShift_dgRMatrix(mat, n);
        break;
    default:
        Rcpp::stop("unsupported matrix type");
        // Eliminate compiler warning, but should not reach here
        op = new RealShift_matrix(mat, n);
    }
    
    return op;
}

ComplexShift* get_complex_shift_op(SEXP mat, int n, SEXP extra_arg, int mat_type)
{
    ComplexShift *op;
    
    Rcpp::List args(extra_arg);
    
    switch(mat_type)
    {
    case MATRIX:
        op = new ComplexShift_matrix(mat, n);
        break;
    case DGEMATRIX:
        op = new ComplexShift_dgeMatrix(mat, n);
        break;
    case DGCMATRIX:
        op = new ComplexShift_dgCMatrix(mat, n);
        break;
    case DGRMATRIX:
        op = new ComplexShift_dgRMatrix(mat, n);
        break;
    default:
        Rcpp::stop("unsupported matrix type");
        // Eliminate compiler warning, but should not reach here
        op = new ComplexShift_matrix(mat, n);
    }
    
    return op;
}