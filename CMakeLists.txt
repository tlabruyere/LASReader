cmake_minimum_required (VERSION 2.8)
project (LASReader)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(include)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x")

set( LASReader_PUBLIC_HEADER
    include/LAS1_2VarLenHeader.h
    include/LAS1_2PubHeader.h
    include/LAS1_2.h
    include/ImageIO.h
    include/GenericHeader.h
)

add_library( LASReader 
    src/main/cpp/LAS1_2 
    src/main/cpp/LAS1_2PubHeader
    src/main/cpp/LAS1_2VarLenHeader
)

add_executable( TestLASReader
    src/test/cpp/TestMain
    src/test/cpp/LAS1_2PubHeaderTest 
    src/test/cpp/LAS1_2VarLenHeaderTest 
)

target_link_libraries( TestLASReader 
    LASReader    
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
    pthread
)

add_test(TestLASReader TestLASReader)

#install( TARGETS ${LASReader_PUBLIC_HEADER} DESTINATION include)
file( COPY ${LASReader_PUBLIC_HEADER} DESTINATION include)
install( TARGETS ${LASReader} DESTINATION lib)
install( TARGETS ${TestLASReader} DESTINATION testbin)

