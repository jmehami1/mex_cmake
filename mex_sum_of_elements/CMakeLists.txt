cmake_minimum_required(VERSION 3.10)

project(sum_of_elements)

find_package( Matlab COMPONENTS MX_LIBRARY )
#find_package( OpenCV REQUIRED )

if (Matlab_FOUND)
    message(STATUS "MATLAB root directory found: ${Matlab_ROOT_DIR}.")
    matlab_add_mex(
        NAME SumOfElements
        SRC mex_sum_of_elements.cpp
        #LINK_TO ${OpenCV_LIBS}
        )


    #build to bin
    set_target_properties( SumOfElements
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
