#include <gtest/gtest.h>
#include <iostream>
#include "linefunc.h"
TEST(linefunc, input) {
    int a1[] = {1, 2, 2, 1, 2, 2, 1, 1, 1};
    int a2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    linefunc<int> p1(a2, a1, 9,2);
    EXPECT_EQ(p1.Get(1), 29);
    EXPECT_EQ(p1.Get(2), 16);
    linefunc<int> p3(3);
    p3.Set(1,1);
    p3.Set(2,2);
    p3.Set(3,3);
    for(int i = 0; i < 3; i++){
        EXPECT_EQ(p3.Get(i+1), i+1);
    }
    p3.Set(2,3);
    p3.Set(3,5);
    linefunc<int> p5(p3);
    for(int i = 0; i < 3; i++){
        EXPECT_EQ(p5.Get(i+1), 2*i+1);
    }

}
TEST(linefunc, get){
    int a1[] = {1, 1, 2, 2, 3, 3, 4, 4, 5,5};
    int a2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    linefunc<int> p1(a2, a1, 10,5);
    EXPECT_EQ(p1.GetLength(),5);
    EXPECT_EQ(p1.GetFirst(),3);
    EXPECT_EQ(p1.GetLast(),19);
    EXPECT_EQ(p1.Get(3),11);
}
TEST(linefunc, append_prepend_insert){
    int a1[] = {1, 1, 2, 2, 3, 3, 4, 4};
    int a2[] = {1, 2, 3, 4,  7, 8, 9,10};
    linefunc<int> p1(a2, a1, 8,4);
    p1.Append(23);
    p1.Prepend(-1);
    p1.InsertAt(11,4);
    for(int i = 0; i < 7; i++){
        EXPECT_EQ(p1.Get(i+1), 4*i - 1);
    }
}
TEST(linefunc, sub_concat){
    int a1[] = {1, 2,3,4,5,6,7,8,9};
    int a2[] = {1, 2, 3, 4, 5,6,7,8,9};
    linefunc<int> p1(a2, a1, 9,9);
    linefunc<int>* ll = p1.GetSubLinefunc(3,7);
    for(int i = 0; i < 4; i++){
        EXPECT_EQ(ll->Get(i+1), i+3);
    }
    int a3[] = {10,11,12,13,14};
    linefunc<int> p3(a3, a1, 5,5);
    linefunc<int>* l = p1.Concat(&p3);
    for(int i = 0; i < 14; i++){
        EXPECT_EQ(l->Get(i+1), i+1);
    }
}
TEST(linefunc, plus_mult){
    int a1[] = {1, 2,3,4,5,6,7,8,9};
    int a2[] = {1, 2, 3, 4,5,6,  7, 8, 9};
    linefunc<int> p1(a2, a1, 9,9);
    linefunc<int>* l1 = p1.mult(4);
    for(int i = 0; i < 9; i++){
        EXPECT_EQ(l1->Get(i+1), 4*(i+1));
    }
    int a3[] = {10,11,12,13,14};
    linefunc<int> p3(a3, a1, 5,5);
    linefunc<int>* l2 = p1.plus(&p3);
    for(int i = 0; i < 5; i++){
        EXPECT_EQ(l2->Get(i+1), 2*i + 11);
    }
    for(int i = 5; i < 9; i++){
        EXPECT_EQ(l2->Get(i+1), i+1);
    }
}
TEST(linefunc, result) {
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    linefunc<int> p1(a2, a1, 9, 9);
    int a3[] = {1, 2, 2, 2, 3, 2, 2, 2, 2};
    int res = p1.result(a3);
    EXPECT_EQ(res, 94);
}