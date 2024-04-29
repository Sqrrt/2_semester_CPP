#include <gtest/gtest.h>
#include <iostream>
#include "arraysequence.h"
TEST (DynamicArraySequence, input){
    int arrr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    ArraySequence<int> a(arrr, 10);
    ArraySequence<int> a2( 5);
    a2.Set(1,0);
    a2.Set(2,2);
    a2.Set(3,4);
    a2.Set(4,6);
    a2.Set(5,8);
    ArraySequence<int> a4;
    a4.Append(1);
    a4.Append(2);
    a4.Append(3);
    for(int i = 0; i < 10; i++){
        EXPECT_EQ(a.Get(i+1),i-5);
    };
    int j = 0;
    for(int i = 0; i < 5; i++){
        EXPECT_EQ(a2.Get(i+1),j);
        j = j+2;
    };
    for(int i = 0; i < 3; i++){
        EXPECT_EQ(a4.Get(i+1),i+1);
    };
    a.Set(1,5);
    a.Set(2,4);
    a.Set(3,3);
    a.Set(4,2);
    a.Set(5,1);
    ArraySequence<int> a3(a);
    EXPECT_EQ(a3.Get(1),5);
    EXPECT_EQ(a3.Get(2),4);
    EXPECT_EQ(a3.Get(3),3);
    EXPECT_EQ(a3.Get(4),2);
    EXPECT_EQ(a3.Get(5),1);
    for(int i = 5; i < 10; i++) {
        EXPECT_EQ(a3.Get(i+1), i - 5);
    }
}
TEST (DynamicArraySequence, append_prepend_insert){
    int arrr[] = {2,3,4,6,7,8,9};
    ArraySequence<int> a(arrr, 7);
    a.Append(10);
    a.Prepend(1);
    a.InsertAt(5,5);
    for(int i = 0; i < 10; i++){
        EXPECT_EQ(a.Get(i+1),i+1);
    }
}
TEST (DynamicArraySequence, getsub_concat){
    int arrr[] = {1,2,3,4,5,6,7,8,9,10};
    ArraySequence<int> a(arrr, 10);
    ArraySequence<int>* a2;
    a2 = (ArraySequence<int>*)a.GetSubSequence(3, 5);
    EXPECT_EQ(a2->Get(1), 3);
    EXPECT_EQ(a2->Get(2), 4);
    EXPECT_EQ(a2->Get(3), 5);
    ArraySequence<int>* a3;
    a3 = (ArraySequence<int>*)a.Concat(a2);
    for(int i = 0; i < 10; i++){
        EXPECT_EQ(a3->Get(i+1),i+1);
    }
    EXPECT_EQ(a3->Get(11),3);
    EXPECT_EQ(a3->Get(12),4);
    EXPECT_EQ(a3->Get(13),5);
}
TEST (DynamicArraySequence, get){
    int arrr[] = {1,2,3,4,5,6,7,8,9,10};
    ArraySequence<int> a(arrr, 10);
    EXPECT_EQ(a.Get(4), 4);
    EXPECT_EQ(a.GetLength(), 10);
    EXPECT_EQ(a.GetFirst(), 1);
    EXPECT_EQ(a.GetLast(), 10);
}
