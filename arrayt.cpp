#include <gtest/gtest.h>
#include <iostream>
#include "array.h"
TEST (DynamicArray, input){
    int arrr[] = {11,21,543,42,5,6,7,8,9};
    DynamicArray<int>  arr(arrr, 9);
    DynamicArray<int>  arr2(3);
    arr2.Set(3,1);
    arr2.Set(2,1-87);
    arr2.Set(1, 0);
    DynamicArray<int>  arr3(arr);
    EXPECT_EQ(arr.Get(1),11);
    EXPECT_EQ(arr.Get(2),21);
    EXPECT_EQ(arr.Get(3),543);
    EXPECT_EQ(arr.Get(4),42);
    EXPECT_EQ(arr.Get(5),5);
    EXPECT_EQ(arr.Get(6),6);
    EXPECT_EQ(arr.Get(7),7);
    EXPECT_EQ(arr.Get(8),8);
    EXPECT_EQ(arr.Get(9),9);
    //EXPECT_EQ(arr2.GetSize(), 3);
    for(int i = 1; i < arr.GetSize() + 1; i++) {
        EXPECT_EQ(arr.Get(i), arr3.Get(i));
    }
    EXPECT_EQ(arr2.Get(1),0);
    EXPECT_EQ(arr2.Get(2),-86);
    EXPECT_EQ(arr2.Get(3),1);
}

TEST(DynamicArray, get_getsize){
    int arrr[] = {11,21,543,42,5,6,7,8,9};
    DynamicArray<int>  arr(arrr, 9);
    int arrr2[] = {11,21,543};
    DynamicArray<int>  arr2(arrr2, 3);
    int K = arr2.Get(3);
    EXPECT_EQ(K, 543);
    EXPECT_EQ(arr2.GetSize(), 3);
    EXPECT_EQ(arr.GetSize(), 9);
//    EXPECT_EQ(L, "error2, Index out of range");
//    EXPECT_EQ(M, "error2, Index out of range");
}
TEST(DynamicArray, Resize_setter_GetSize){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    DynamicArray<int>  arr2(arr, 9);
    EXPECT_EQ(arr2.GetSize(), 9);
    arr2.Resize(7);
    EXPECT_EQ(arr2.GetSize(), 7);
    EXPECT_ANY_THROW(arr2.Get(8));
    arr2.Resize(11);
    EXPECT_EQ(arr2.GetSize(), 11);
    arr2.setter(3, 4);
    arr2.setter(7, 19);
    arr2.setter(10,8);
    arr2.setter(11,9);
    int arr3[] = {1,2,4,3,4,5,19,6,7,8,9};
    for(int i = 1; i < 12; i++){
            EXPECT_EQ(arr2.Get(i),arr3[i - 1]);
    }
}
TEST(DynamicArray,set){
    int arr[] = {11,21,543,42,5,6,7,8,9};
    DynamicArray<int>  arr2(arr, 9);
    arr2.Set(2,2);
    arr2.Set(1,1);
    arr2.Set(3,3);
    arr2.Set(4,5);
    arr2.Set(4, 4);
    for(int i = 1; i < arr2.GetSize() + 1; i++) {
        EXPECT_EQ(arr2.Get(i), i);
    }
}