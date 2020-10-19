/*
        MEX file which edits passed in images using openCV
*/

//Helper function for used in mx_Array_Image2_Mat
mwIndex subs(const mxArray *inputMatrix, const std::vector<mwIndex>& si)
{
    std::vector<mwIndex> v(si);
    return mxCalcSingleSubscript(inputMatrix, si.size(), (!v.empty() ? &v[0] : NULL));
}


cv::Mat mx_Array_Image2_Mat(const mxArray *inputMatrix)
{

    uint8_T *inImgArr = mxGetUint8s(inputMatrix);
    const mwSize *dims = mxGetDimensions(inputMatrix);
    mwSize ndims = mxGetNumberOfDimensions(inputMatrix);
    const mxClassID classID = mxGetClassID(inputMatrix);

    // Create cv::Mat object (of the specified depth), equivalent to mxArray.
    // At this point we create either a 2-dim with 1-channel mat, or a 2-dim
    // with multi-channels mat. Multi-dims case is handled above.
    std::vector<int> d(dims, dims+ndims);
    ndims = (d.size()>2) ? d.size()-1 : d.size();
    const mwSize nchannels = (d.size()>2) ? d.back() : 1;
    int depth = CV_8U;
    std::swap(d[0], d[1]);
    cv::Mat mat(ndims, &d[0], CV_MAKETYPE(depth, nchannels));
    // Copy each channel from mxArray to Mat (converting to specified depth),
    // as in: channels[i] <- cast_to_mat_depth(p_(:,:,i))
    std::vector<cv::Mat> channels(nchannels);
    std::vector<mwSize> si(d.size(), 0);                 // subscript index
    const int type = CV_MAKETYPE(depth, 1); // Source type

    for (mwIndex i = 0; i<nchannels; ++i) {
        si[si.size() - 1] = i;                   // last dim is a channel idx
        void *pd = reinterpret_cast<void*>(
                    reinterpret_cast<size_t>(mxGetData(inputMatrix)) +
                    mxGetElementSize(inputMatrix)*subs(inputMatrix ,si));      // ptr to i-th channel data
        const cv::Mat m(ndims, &d[0], type, pd); // only creates Mat headers
        // Read from mxArray through m, writing into channels[i]
        // (Note that saturate_cast<> is applied, so values are clipped
        // rather than wrap-around in a two's complement sense. In
        // floating-point to integer conversion, numbers are first rounded
        // to nearest integer then clamped).
        m.convertTo(channels[i], CV_MAKETYPE(depth, 1));
        // transpose cv::Mat if needed. We do this inside the loop on each 2d
        // 1-cn slice to avoid cv::transpose limitation on number of channels
        //if (transpose)
        cv::transpose(channels[i], channels[i]);  // in-place transpose
    }

    // Merge channels back into one cv::Mat array
    cv::merge(channels, mat);
    cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);

    return mat;
}
