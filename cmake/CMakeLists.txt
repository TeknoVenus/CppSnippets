cmake_minimum_required(VERSION 3.16.0)

# Project version
set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 0)

project(SampleProject VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")

# Set a global define for the build version
set(BUILD_REFERENCE "unknown" CACHE STRING "Commit hash")
add_definitions(-DPROJECT_VERSION="${CMAKE_PROJECT_VERSION}-${BUILD_REFERENCE}")

# Include GNUInstallDirs module to access CMAKE_INSTALL_* directory variables
include(GNUInstallDirs)

# Add our local cmake directory to search for components
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Enable C++17 support.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable warnings
add_compile_options(-Wall)

# Disables an annoying warning "<blah> will change in GCC X.XX"
add_compile_options(-Wno-psabi)