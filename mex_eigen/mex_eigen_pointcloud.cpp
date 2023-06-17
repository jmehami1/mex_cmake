/*==========================================================
 * mexcpp.cpp - example in MATLAB External Interfaces
 *
 * Illustrates how to use some C++ language features in a MEX-file.
 *
 * The routine simply defines a class, constructs a simple object,
 * and displays the initial values of the internal variables. It
 * then sets the data members of the object based on the input given
 * to the MEX-file and displays the changed values.
 *
 * This file uses the extension .cpp. Other common C++ extensions such
 * as .C, .cc, and .cxx are also supported.
 *
 * The calling syntax is:
 *
 *              mexcpp( num1, num2 )
 *
 * This is a MEX-file for MATLAB.
 * Copyright 1984-2016 The MathWorks, Inc.
 *
 *========================================================*/


#include <iostream>
#include "mex.h"
#include "matrix.h"
#include <Eigen/Dense>

/* The gateway function. */ 
void mexFunction(int numOutputs, mxArray *outputs[],
                 int numInputs, const mxArray *inputs[]) {

    int V_cols, V_rows;
    int number_of_correspondences, dim;
    
    std::cout << "numOutputs: " << numOutputs << std::endl;
    std::cout << "numInputs: " << numInputs << std::endl;
    
    /* Check for proper number of arguments */
    if(numInputs != 3 && numInputs != 4) {
        mexErrMsgIdAndTxt("MATLAB:mexcpp:nargin",
                          "MEXCPP requires three or four input arguments.\nExample:\n\ttest(point_cloud, source_correspondences, target_correspondences)\n\ttest(point_cloud, faces, source_correspondences, target_correspondences)");
    }
    if(numOutputs != 1) {
        mexErrMsgIdAndTxt("MATLAB:mexcpp:nargout",
                          "MEXCPP requires one output argument.");
    }
    
    /* Get the the matrix input that store the vertices. */
    V_rows = (int)mxGetM(inputs[0]);
    V_cols = (int)mxGetN(inputs[0]);
    Eigen::Map<Eigen::MatrixXd> V(mxGetPr(inputs[0]), V_rows, V_cols);
    
    number_of_correspondences = (int)mxGetM(inputs[1]);
    dim = (int)mxGetN(inputs[1]);
    Eigen::Map<Eigen::MatrixXd> correspondences_source(mxGetPr(inputs[1]), number_of_correspondences, dim);
    
    
    number_of_correspondences = (int)mxGetM(inputs[2]);
    dim = (int)mxGetN(inputs[2]);
    Eigen::Map<Eigen::MatrixXd> correspondences_target(mxGetPr(inputs[2]), number_of_correspondences, dim);
    
    std::cout << "V_rows: " << V_rows << std::endl;
    std::cout << "V_cols: " << V_cols << std::endl;
    std::cout << "V: \n" << V << std::endl;
    
    
    /* create the output matrix */
    outputs[0] = mxCreateDoubleMatrix((mwSize) V.rows(), (mwSize) V.cols(), mxREAL);
    Eigen::Map<Eigen::MatrixXd>( mxGetPr(outputs[0]), V.rows(), V.cols() ) = V;
}
