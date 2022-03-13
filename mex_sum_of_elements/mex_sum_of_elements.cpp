/*
    MEX implementation of the imread function from openCV.
*/

#include <iostream>
#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){

    //checking inputs/outputs
    if ((nlhs != 1) || (nrhs != 1))
        mexErrMsgTxt("incorrect input/output arguments");

    //convert first input to double vector
    double* inDoubleArr = mxGetDoubles(prhs[0]);
    const mwSize *inDim = mxGetDimensions(prhs[0]);

    //Size of array from Matlab
    const int rows = inDim[0];
    const int cols = inDim[1];

    //std::cout << rows << " " << cols << std::endl;


    //Your implementation: summing the elements of the array
    double sum = 0;

    for (int i = 0; i < cols; i++)
        sum += inDoubleArr[i];



    //Create first output
    plhs[0] = mxCreateDoubleScalar(sum);

}

