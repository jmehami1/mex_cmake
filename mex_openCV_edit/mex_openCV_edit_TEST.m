%Test the implementation for the mex imread function

clc
%Author: Jasprabhjit Mehami, 13446277

[F,M] = inmem("-completenames")


clear all;
clear classes;
clear functions;
clear global;
clear java;
clear mex;
close all;

[F,M] = inmem("-completenames")



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