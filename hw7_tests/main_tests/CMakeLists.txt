include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runMainHW7Tests ../main_tests/main_check.cpp)
target_link_libraries(runMainHW7Tests hw7_library gtest gtest_main)
