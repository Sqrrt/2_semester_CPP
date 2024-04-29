#include <gtest/gtest.h>
#include <iostream>
#include "listsequence.h"
TEST (ListSequence, input){
    int arr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    LinkedListSequence<int> l1(arr, 10);
    LinkedListSequence<int> l2;
    LinkedListSequence<int> l4(3);
    l4.Set(1,1);
    l4.Set(2,2);
    l4.Set(3,3);
    l2.Append(1);
    l2.Append(2);
    l2.Append(3);
    for(int i = 0; i < 10; i++) {
        EXPECT_EQ(l1.Get(i+1), i - 5);
    }
    for(int i = 0; i < 3; i++) {
        EXPECT_EQ(l2.Get(i+1), i + 1);
        EXPECT_EQ(l4.Get(i+1), i + 1);
    }
    l1.Set(1,5);
    l1.Set(2,4);
    l1.Set(3,3);
    l1.Set(4,2);
    l1.Set(5,1);
    LinkedListSequence<int> l3(l1);
    EXPECT_EQ(l3.Get(1),5);
    EXPECT_EQ(l3.Get(2),4);
    EXPECT_EQ(l3.Get(3),3);
    EXPECT_EQ(l3.Get(4),2);
    EXPECT_EQ(l3.Get(5),1);
    for(int i = 5; i < 9; i++) {
        EXPECT_EQ(l3.Get(i + 1), i - 5);
    }
}
TEST (ListSequence, append_prepend_insert){
    int arrr[] = {2,3,4,6,7,8,9};
    LinkedListSequence<int> l(arrr, 7);
    l.Append(10);
    l.Prepend(1);
    l.InsertAt(5,5);
    for(int i = 0; i < 10; i++){
        EXPECT_EQ(l.Get(i+1),i+1);
    }
}
TEST (ListSequence, getsub_concat) {
    int arrr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedListSequence<int> l(arrr, 10);
    LinkedListSequence<int>* l2;
    l2 = (LinkedListSequence<int>*)l.GetSubSequence(3, 5);
    EXPECT_EQ(l2->Get(1), 3);
    EXPECT_EQ(l2->Get(2), 4);
    EXPECT_EQ(l2->Get(3), 5);
    LinkedListSequence<int>* l3;
    l3 = (LinkedListSequence<int>*)l.Concat(l2);
    for(int i = 0; i < 10; i++){
        EXPECT_EQ(l3->Get(i+1),i+1);
    }
    EXPECT_EQ(l3->Get(11),3);
    EXPECT_EQ(l3->Get(12),4);
    EXPECT_EQ(l3->Get(13),5);
}
TEST (ListSequence, get){
    int arr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    LinkedListSequence<int> l(arr, 10);
    EXPECT_EQ(l.GetFirst(), -5);
    EXPECT_EQ(l.GetLast(), 4);
    EXPECT_EQ(l.Get(5), -1);
    EXPECT_EQ(l.GetLength(), 10);
}
