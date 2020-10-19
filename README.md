# mex_tutorial

A small introduction tutorial to MATLAB's MEX applications, which are used for interfacing and running C/C++ code and programs via MATLAB.

Assuming you are on Ubuntu Linux, you need to have the following installed:

- MATLAB (any version)
- GIT
- CMake
- gcc and g++ (install build-essentials)
- openCV (for handling imaging stuff in C++)
- An IDE would also be good (QT Creator is works)



## File Extensions

| File Extension | Description                         |
| -------------- | ----------------------------------- |
| `.m`           | MATLAB script or function           |
| `.mlx`         | MATLAB live script or live function |
| `.cpp`         | C++ Implementation file             |
| `.h`           | C++ header file                     |
| `.mexa64`      | MEX file built in 64-bit Linux      |
| `.mexmaci64`   | MEX file built in 64-bit Mac        |
| `.mexw64`      | MEX file built in 64-bit Windows    |



## MEX Applications

There are two ways to write MEX applications:

1. C MEX function (older)

   ```c++
   #include "mex.h"
   
   void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]){
       
   };
   ```

   **Note:** `mexFunction` function is the entry point into the MEX application from MATLAB. It **must** be present with that exact name.

   Link to the C/C++ API can be found [here](https://www.mathworks.com/help/matlab/cc-mx-matrix-library.html?s_tid=CRUX_lftnav).

   Inputs and outputs from the function are stored as `mxArray` data structure. The data structure holds information such type, size (dimensions), is complex, and etc.

   | Variable | Description                                                  |
   | -------- | ------------------------------------------------------------ |
   | nlhs     | Number of elements on the left-hand side (number of outputs expected by MATLAB) |
   | *plhs[]  | Array of pointers to the left-hand side outputs              |
   | nrhs     | Number of elements on the right-hand side (number of inputs passed in by MATLAB) |
   | *prhs[]  | Array of pointers to the right-hand side outputs             |

   

   

2. C++ MEX class (newer) (**DOES NOT WORK. You can ignore it.**)

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



## Building Mex File

Create a `build` directory inside current directory.

In a terminal pointing to build run the following:

```bash
cmake ..
make
```

The built Mex file can be found in the  `bin`  directory.

Note: You may get a warning about gcc or g++ version being incompatible with the MEX compiler. The MEX file should still have been built.





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


