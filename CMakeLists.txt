cmake_minimum_required(VERSION 3.21)
project(lab3)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(google_test/google-test)

include_directories (google_test/google-test/googletest/include)
include_directories (google_test/google-test/googlemock/include)
add_executable(lab3 main.cpp tree.h classes.h set.h treetests.cpp settests.cpp)
target_link_libraries(lab3 gtest)
target_link_libraries(lab3 gmock)