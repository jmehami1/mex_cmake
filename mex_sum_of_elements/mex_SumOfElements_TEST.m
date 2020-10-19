%Test the SumOfElements function

%Author: Jasprabhjit Mehami, 13446277

clear;
close all;

%mex function should be in the bin folder
if exist("bin", "dir")
    addpath("bin");
else
    error("mex file not built");
end

