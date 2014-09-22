cmake_minimum_required (VERSION 2.8)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable( TestLASReader
    TestMain
    LAS1_2PubHeaderTest 
    LAS1_2VarLenHeaderTest 
)

target_link_libraries( TestLASReader 
    LASReader    
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
    pthread
)
