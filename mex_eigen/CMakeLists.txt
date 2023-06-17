cmake_minimum_required(VERSION 3.10)

project(eigen_entry)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

find_package( Matlab COMPONENTS MX_LIBRARY )

if (Matlab_FOUND)
    message(STATUS "MATLAB root directory found: ${Matlab_ROOT_DIR}.")
    matlab_add_mex(
        NAME eigen_pointcloud
        SRC mex_eigen_pointcloud.cpp
        #R2018a
        )

    set_target_properties( eigen_pointcloud
        PROPERTIES
        COMPILE_FLAGS "-fvisibility=default"
        ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
        )

    message(STATUS "Mex file can be found in ${PROJECT_SOURCE_DIR}/bin")
else ()
    message(WARNING "MATLAB root directory not found. Failed to build MATLAB bindings.")
    set(BUILD_MATLAB_BINDINGS OFF)
endif ()
