# CXX means C++.
project(radixsort CXX)


# Require make version 2.8 minimum
cmake_minimum_required(VERSION 2.8)


set(CMAKE_CXX_FLAGS "-Wall -std=c++11 ")


# Declares the executable to be built from source files
add_executable(test  main.cpp)


# This creates a new target for the make program. After
# including this, you can write:
#
#   make printout
#
# The PDF will be created in the build directory and is named "printout.pdf"

# DO NOT MODIFY THIS COMMAND
add_custom_target(printout
	  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	    COMMAND a2ps -Afill -o- ${files} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
