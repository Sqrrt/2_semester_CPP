
#include <gtest/gtest.h>
#include <iostream>
#include "linkedlist.h"
TEST(listtests, get){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    LinkedList<int> list2(arr, 9);
    int k = list2.Get(3);
    int g = list2.GetFirst();
    int l = list2.GetLast();
    EXPECT_EQ(k, 3);
    EXPECT_EQ(g, 1);
    EXPECT_EQ(l, 9);
}
TEST(listtests, Append_Prepend){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    LinkedList<int> list2(arr, 9);
    list2.Append(10);
    for (int i = 0; i < 9; i++){
        EXPECT_EQ(list2.Get(i+1),i+1);
    }
    list2.Prepend(0);
    list2.Prepend(12);
    EXPECT_EQ(list2.Get(1),12);
    for (int i = 1; i < 11; i++){
        EXPECT_EQ(list2.Get(i+1),i-1);
    }
}
TEST (listtests, input){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    LinkedList<int> list2(arr, 9);
    for(int i = 0; i < 9; i++) {
        EXPECT_EQ(list2.Get(i + 1), i + 1);
    }
    list2.Set(4,8);
    list2.Set(5, 18);
    LinkedList<int> list3(list2);
    EXPECT_EQ(list3.Get(1), 1);
    EXPECT_EQ(list3.Get(2), 2);
    EXPECT_EQ(list3.Get(3), 3);
    EXPECT_EQ(list3.Get(4), 8);
    EXPECT_EQ(list3.Get(5), 18);
    EXPECT_EQ(list3.Get(6), 6);
    EXPECT_EQ(list3.Get(7), 7);
    EXPECT_EQ(list3.Get(8), 8);
    EXPECT_EQ(list3.Get(9), 9);
}
TEST (listtests, InsertAt){
    int arr[] = {1,2,3,4,6,7,8,9};
    LinkedList<int> list2(arr, 8);
    list2.InsertAt(5, 5);
    for(int i = 0; i < 9; i++) {
        EXPECT_EQ(list2.Get(i + 1), i + 1);
    }
    list2.InsertAt(0,1);
    for(int i = 0; i < 10; i++) {
        EXPECT_EQ(list2.Get(i + 1), i);
    }
}
TEST (listtests, Concat_GetSubList){
    int arr[] = {1,2,3,4};
    LinkedList<int> list(arr, 4);
    int arr2[] = {5,6,7,8,9};
    int arr3[] = {1,2,3,4,5,6,7,8,9};
    LinkedList<int> list3(arr3, 9);
    LinkedList<int> list2(arr2, 5);
    LinkedList<int>* list4 = list3.GetSubList(1,8);
    LinkedList<int>* list5 = list.Concat(&list2);
    for(int i = 2; i < 8; i++){
        EXPECT_EQ(list4->Get(i), i);
    }
    for(int i = 0; i < 9; i++){
        EXPECT_EQ(list5->Get(i+1), i + 1);
    }
}
