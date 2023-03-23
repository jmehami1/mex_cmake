%Test the SumOfElements function

%Author: Jasprabhjit Mehami, 13446277

clear function;
close all;

%mex function should be in the bin folder
if exist("bin", "dir")
    addpath("bin");
else
    error("mex file not built");
end

numNums = 99999999;

arrIN = randi(10,1,numNums);

tic();
arrOut = SumOfElements(arrIN);
toc();

tic();
arrOut1 = sum(arrIN,'all'); 
toc();
