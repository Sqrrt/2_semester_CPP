#include <gtest/gtest.h>
#include <iostream>
#include "vector.h"
TEST (vector, input){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    myvector<int> vec1(arr, 9);
    myvector<int> vec3;
    myvector<int> vec5(3);
    vec3.Append(1);
    vec3.Append(2);
    vec3.Append(3);
    vec5.Set(1,1);
    vec5.Set(2,2);
    vec5.Set(3,3);
    for(int i = 0; i < 3; i++) {
        EXPECT_EQ(vec3.Get(i+1), i+1);
        EXPECT_EQ(vec5.Get(i+1), i+1);
    }
    for(int i = 0; i < 9; i++){
        EXPECT_EQ(vec1.Get(i+1), i+1);
    }
}
TEST(vector, get){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int arr2[] = {-4,-3,-2,-1,0,1,2,3,4};
    myvector<int> vec1(arr, 9);
    EXPECT_EQ(vec1.GetLength(), 9);
    EXPECT_EQ(vec1.GetFirst(), 1);
    EXPECT_EQ(vec1.GetLast(), 9);
    EXPECT_EQ(vec1.Get(5), 5);
}
TEST(vector, append_prepend_insertat){
    int arr[] = {1,2,3,4,6,7,8,9};
    int arr2[] = {-4,-3,-2,-1,1,2,3,4};
    myvector<int> vec1(arr, 8);
    myvector<int> vec2(arr2, 8);
    vec2.Append(5);
    vec2.Prepend(-5);
    vec1.Append(10);
    vec1.Prepend(0);
    vec1.InsertAt(5,6);
    vec2.InsertAt(0,6);
    for(int i = 0; i < 11; i++){
        EXPECT_EQ(vec1.Get(i+1), i);
        EXPECT_EQ(vec2.Get(i+1), i-5);
    }
}
TEST(vector, plus_mult){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int arr2[] = {-4,-3,-2,-1,0,1,2,3,4};
    myvector<int> vec1(arr, 9);
    myvector<int> vec2(arr2, 9);
    myvector<int>* v1 = vec1.mult(2);
    myvector<int>* v2 = vec2.plus(&vec1);
    for(int i = 0; i < 9; i++){
        EXPECT_EQ(v1->Get(i+1), 2*(i + 1));
        EXPECT_EQ(v2->Get(i+1), 2*i - 3);
    }
}
TEST (vector, length_multscalar){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int arr2[] = {-4,-3,-2,-1,0,1,2,3,4};
    myvector<int> vec1(arr, 9);
    myvector<int> vec2(arr2, 9);
    double l1 = vec1.length();
    int a = vec1.multscalar(&vec2);
    EXPECT_EQ(l1,16.88);
    EXPECT_EQ(a,60);
}
TEST(vector, concat_getsub){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int arr2[] = {-4,-3,-2,-1,0};
    myvector<int> vec1(arr, 9);
    myvector<int> vec2(arr2, 5);
    myvector<int>* vec5 = vec2.Concat(&vec1);
    myvector<int>* vec7 = vec5->GetSubVector(5, 8);
    for(int i = 0; i < 14; i++){
        EXPECT_EQ(vec5->Get(i+1), i-4);
    }
    for(int i = 0; i < 4; i++){
        EXPECT_EQ(vec7->Get(i+1), i);
    }
}