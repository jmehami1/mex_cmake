%Test the implementation for the mex imread function

%Author: Jasprabhjit Mehami, 13446277

clear;
close all;

% mex function should be in the bin folder
if exist("bin", "dir")
    addpath("bin");
else
    error("mex file not built");
end

imgIn = imread("pattern.png");

figure("Name", "Input Image");
imshow(imgIn);

imgOut = OpenCV_Edit(imgIn);

figure("Name", "Output Image");
imshow(imgOut);