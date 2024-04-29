cmake_minimum_required(VERSION 3.21)
project(lab2nd)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(google_test/google-test)
include_directories(google_test/google-test/googletest/include google_test/google-test/googlemock/include)
add_executable(lab2nd main.cpp array.h sequence.h arraysequence.h linkedlist.h listsequence.h myexception.h classes.h arrayt.cpp listt.cpp classes.h listseqt.cpp arrayseqt.cpp vector.h vectort.cpp linefunc.h linefunct.cpp)
target_link_libraries(lab2nd gtest)
target_link_libraries(lab2nd gmock)