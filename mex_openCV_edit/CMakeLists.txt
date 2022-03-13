cmake_minimum_required(VERSION 3.10)

project(mex_openCV_edit)

find_package( Matlab COMPONENTS MX_LIBRARY )
find_package( OpenCV 4.0 REQUIRED
    PATHS / )

if (Matlab_FOUND)
    message(STATUS "MATLAB root directory found: ${Matlab_ROOT_DIR}.")
    matlab_add_mex(
        NAME OpenCV_Edit
        SRC mex_openCV_edit.cpp
        LINK_TO ${OpenCV_LIBS}
        )

    #build MEX application and put it into bin directory
    set_target_properties( OpenCV_Edit
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
