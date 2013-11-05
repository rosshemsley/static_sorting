CMAKE_MINIMUM_REQUIRED ( VERSION 2.6 )
PROJECT ( Static_soter )
SET( CMAKE_CXX_FLAGS "-Wall -O3 -std=c++11 -stdlib=libc++" )
ADD_EXECUTABLE ( sorter main.cpp static_sorter.hpp )