cmake_minimum_required(VERSION 3.10)

project(charuco_pose_est)

find_package( Matlab COMPONENTS MX_LIBRARY )
find_package( OpenCV REQUIRED )

if (Matlab_FOUND)
    message(STATUS "MATLAB root directory found: ${Matlab_ROOT_DIR}.")
    matlab_add_mex(
        NAME CharucoPosEst
        SRC mex_charuco_pose_est.cpp
        LINK_TO ${OpenCV_LIBS}
        )


    set_target_properties( CharucoPosEst
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
