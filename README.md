<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

<!-- Find and replace all the following: 

github username: jmehami1
repo name:  mex_cmake

-->

<div align="center">

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![reposize][reposize-shield]][reposize-url]

[![LinkedIn][linkedin-shield]][linkedin-url]
[![portfolio][portfolio-shield]][portfolio-url]

</div>

<h1 align="center">MATLAB MEX tutorial using CMake</h1>

<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/matlab/matlab-original.svg" alt="MATLAB" title="MATLAB" width="20%" href="mathworks.com/help/matlab/ref/mex.html" align="center"/>

---

**Table of Contents**

- [About](#about)
- [Requirements](#requirements)
- [File Extensions](#file-extensions)
- [MEX Applications](#mex-applications)
- [Building MEX with CMake](#building-mex-with-cmake)
- [Project 1: Sum of array elements](#project-1-sum-of-array-elements)
- [Project 2: Edit images using openCV](#project-2-edit-images-using-opencv)
- [Project 3: Edit pointclouds using Eigen library](#project-3-edit-pointclouds-using-eigen-library)
- [TODO](#todo)
- [License](#license)
- [Contact](#contact)
- [Acknowledgments](#acknowledgments)

---

## About

A small introduction tutorial to MATLAB's MEX applications, which are used for interfacing and running C/C++ programs inside of MATLAB.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Requirements

- MATLAB 2018a or higher (Tested with 2021b)
- GCC 7.0 or higher (Tested with 7.5.0)
- OpenCV 4.0 or higher
- CMake
- libeigen3-dev

You will need compatible gcc and g++ compilers to build MEX functions as listed [here](https://au.mathworks.com/support/requirements/supported-compilers.html). 



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
       /*
         Implemented MEX function
       /*
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


## Project 3: Edit pointclouds using Eigen library

Obviously MATLAB can load pointclouds and edit them, but lets create a MEX file which edits a pointcloud using the C++ Eigen library and returns the edited pointcloud to MATLAB.

In MATLAB we should call the function like this:

```matlab
modified_cloud = eigen_pointcloud(point_cloud, source_correspondences, target_correspondences);
```


## TODO

- [ ] Check if MEX C++ API is working now

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contact

[Jasprabhjit Mehami](linkedin-url)

Email: jasprabhjit.mehami@gmail.com

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->

## Acknowledgments

* [Eigen Library](https://eigen.tuxfamily.org/index.php?title=Main_Page)

* [OpenCV](https://opencv.org/)

  

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->



[contributors-shield]: https://img.shields.io/github/contributors/jmehami1/mex_cmake.svg?style=plastic&logo=appveyor
[contributors-url]: https://github.com/jmehami1/mex_cmake/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/jmehami1/mex_cmake.svg?style=plastic&logo=appveyor
[forks-url]: https://github.com/jmehami1/mex_cmake/network/members
[stars-shield]: https://img.shields.io/github/stars/jmehami1/mex_cmake.svg?style=plastic&logo=appveyor
[stars-url]: https://github.com/jmehami1/mex_cmake/stargazers
[issues-shield]: https://img.shields.io/github/issues/jmehami1/mex_cmake.svg?style=plastic&logo=appveyor
[issues-url]: https://github.com/jmehami1/mex_cmake/issues

[license-shield]: https://img.shields.io/github/license/jmehami1/mex_cmake
[license-url]: https://github.com/jmehami1/mex_cmake/blob/master/LICENSE.txt
[reposize-shield]: https://img.shields.io/github/repo-size/jmehami1/mex_cmake.svg?style=plastic&logo=appveyor
[reposize-url]: https://github.com/jmehami1/mex_cmake



[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-blue.svg?style=for-the-badge&logo=linkedin&colorB=0077b5
[linkedin-url]: https://linkedin.com/in/jessemehami
[portfolio-shield]: https://img.shields.io/badge/-Portfolio-blue.svg?style=for-the-badge&logo=Portfolio&colorB=625094
[portfolio-url]: https://jmehami1.github.io/