cmake_minimum_required (VERSION 2.8)
project (LASReader)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x")


include_directories( include ) 
add_subdirectory( include )
add_subdirectory( src/main/cpp )
add_subdirectory( src/test/cpp )



