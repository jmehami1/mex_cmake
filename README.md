# MATLAB MEX using CMake

A small introduction tutorial to MATLAB's MEX applications, which are used for interfacing and running C/C++ programs inside of MATLAB.

Assuming you are on Ubuntu, you need to have the following installed:

- MATLAB (this project compiled with **R2020b**)
- CMake
- gcc and g++ (install build-essentials)
- openCV (for handling imaging in C++)

## File Extensions

Summary of important file extensions from MATLAB and C++

| File Extension | Description                          |
| -------------- | ------------------------------------ |
| `.m`           | MATLAB script or function            |
| `.mlx`         | MATLAB live script or live function  |
| `.cpp`         | C++ Implementation file              |
| `.h`           | C++ header file                      |
| `.mexa64`      | MEX function built in 64-bit Linux   |
| `.mexmaci64`   | MEX function built in 64-bit Mac     |
| `.mexw64`      | MEX function built in 64-bit Windows |

Built MEX functions **cannot** be shared between different OS, and in many cases, **cannot** be shared between PCs with the same OS.



## MEX Applications

There are two ways to write MEX applications:

1. C Matrix API 

   ```c++
   #include "mex.h"
   
   void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
       
   };
   ```

   **NOTE:** 

   - `mexFunction` function is the entry point into the MEX application from MATLAB. It **must** be present with that exact name.

   - Link to the C/C++ API can be found [here](https://www.mathworks.com/help/matlab/cc-mx-matrix-library.html?s_tid=CRUX_lftnav).


   - Inputs and outputs from the function are stored as `mxArray` data structure. The data structure holds information such type, size (dimensions), is complex flag, and etc.

   

You would call the MEX function in MATLAB as follows:

   ```matlab
   [output1, output2, ...] = SomeFunction(input1, input2, ...);
   ```

   

   | Variable | Description                                                  |
   | -------- | ------------------------------------------------------------ |
   | nlhs     | Number of elements on the left-hand side (number of outputs expected by MATLAB) |
   | *plhs[]  | Array of pointers to the left-hand side outputs              |
   | nrhs     | Number of elements on the right-hand side (number of inputs passed in by MATLAB) |
   | *prhs[]  | Array of pointers to the right-hand side outputs             |

   

   

2. C++ MEX API (newer) 

   (**Had issues working with this. I would suggest to stick with C MATRIX API**)
   
   ```c++
   #include "mex.hpp"
   #include "mexAdapter.hpp"
   
   using matlab::mex::ArgumentList;
   using namespace matlab::data;
   
   class MexFunction : public matlab::mex::Function {
       std::shared_ptr<matlab::engine::MATLABEngine> matlabPtr = getEngine();
   public:
       void operator()(ArgumentList outputs, ArgumentList inputs) {
           
       }
   };
   ```
   
   **Note:** `MexFunction` class is the entry point into the MEX application from MATLAB. It **must** be present with that exact name.



## Building MEX with CMake

Inspect the `CMakeLists.txt` files inside of the example projects to see further details and CMake syntax. To build a MEX function, follow these instructions:

1. Create a `build` directory inside the project directory.
2. In a terminal pointing to build run the following:


```bash
cmake ..
make
```

The built MEX function can be found in the  `bin`  directory.

*Note: You may get a warning about gcc or g++ version being incompatible with the MEX compiler. The MEX function should still have been built.*



## Project 1: Sum of array elements

Create a MEX function which returns the sum of all elements of a passed in array.

In MATLAB we should call the function like this:

```matlab
arrSum = SumOfArrElements(arr);
```



## Project 2: Edit images using openCV

Obviously MATLAB can read in images and edit, but lets create a MEX file which edits an image using openCV and returns the edited image to MATLAB.

In MATLAB we should call the function like this:

```matlab
imgEdit = OpenCV_Edit(img);
```

