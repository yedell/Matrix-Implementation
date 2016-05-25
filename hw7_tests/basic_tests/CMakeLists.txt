include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicHW7Tests ../basic_tests/basic_check.cpp)

target_link_libraries(runBasicHW7Tests gtest gtest_main)
target_link_libraries(runBasicHW7Tests hw7_library)