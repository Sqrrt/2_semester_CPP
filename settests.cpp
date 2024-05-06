#include "set.h"
#include "gtest/gtest.h"
#include <iostream>
TEST(set, inputoutput){
    int arr[] ={1,3,2,4,8,6,7,9,5,10};
    vector<int> v = {8,4,-2,5,6,9,11};
    Set<int> s1(arr,10);
    Set<int> s2(v);
    Set<int> s3;
    s3.addelem(2);
    s3.addelem(3);
    s3.addelem(1);
    string str1 = s1.savedeepset();
    string str2 = s2.savedeepset();
    string str3 = s3.savedeepset();
    EXPECT_EQ(str1, " 1 2 3 4 5 6 7 8 9 10");
    EXPECT_EQ(str2, " -2 4 5 6 8 9 11");
    EXPECT_EQ(str3, " 1 2 3");
    string str4 = s1.savebfsset();
    string str5 = s2.savebfsset();
    string str6 = s3.savebfsset();
    EXPECT_EQ(str4, " 1 3 2 4 8 6 9 5 7 10");
    EXPECT_EQ(str5, " 8 4 9 -2 5 11 6");
    EXPECT_EQ(str6, " 2 1 3");
}
TEST(set, boolfunctions){
    int arr[] ={1,3,2,4,8,6,7,9,5,10};
    Set<int> s1(arr,10);
    int arr2[] ={1,2,4,7,9,5,10};
    Set<int> s2(arr2,7);
    int arr3[] ={8,6,-2,5,4,9,11};
    Set<int> s3(arr3,8);
    Set<int> s4(arr3,8);
    ASSERT_TRUE(s1.subset(&s2));
    ASSERT_FALSE(s1.subset(&s3));
    ASSERT_TRUE(s1.search(7));
    ASSERT_FALSE(s1.search(11));
    ASSERT_FALSE(s1.search(-2));
    ASSERT_TRUE(s3.equal(&s4));
    ASSERT_FALSE(s3.equal(&s2));
}
TEST(set, operations){
    int arr[] ={1,3,2,4,8,6,7,9,5,10};
    Set<int> s1(arr,10);
    int arr2[] ={1,2,4,7,9,5,10};
    Set<int> s2(arr2,7);
    int arr3[] ={8,4,-2,5,6,9,11};
    Set<int> s3(arr3,7);
    Set<int> s4(arr3,7);
    Set<int> s5(arr,10);
    Set<int>* res1 = s1.plus(&s3);
    Set<int>* res2 = s2.minus(&s4);
    Set<int>* res3 = s5.intersect(&s4);
    string str1 = res1->savedeepset();
    string str2 = res2->savedeepset();
    string str3 = res3->savedeepset();
    EXPECT_EQ(str1, " -2 1 2 3 4 5 6 7 8 9 10 11");
    EXPECT_EQ(str2, " 1 2 7 10");
    EXPECT_EQ(str3, " 4 5 6 8 9");
}
TEST(set, adddelete){
    int arr[] ={1,3,2,4,8,6,11,9,5,10};
    Set<int> s1(arr,10);
    int arr2[] ={1,2,4,7,9,5,10};
    Set<int> s2(arr2,7);
    int arr3[] ={8,4,-2,5,6,9,11};
    Set<int> s3(arr3,7);
    s1.addelem(15);
    s1.addelem(7);
    s1.deleteelem(11);
    s2.addelem(8);
    s2.addelem(3);
    s3.deleteelem(6);
    s3.deleteelem(5);
    string str1 = s1.savedeepset();
    string str2 = s2.savedeepset();
    string str3 = s3.savedeepset();
    EXPECT_EQ(str1, " 1 2 3 4 5 6 7 8 9 10 15");
    EXPECT_EQ(str2, " 1 2 3 4 5 7 8 9 10");
    EXPECT_EQ(str3, " -2 4 8 9 11");
}

int f1(int d){
    return (3*d);
}
int f2(int a, int b){
    return a + b;
}
bool f3(int a){
    if (a > 2 && a < 7){
        return true;
    }
    else{
        return false;
    }
}

TEST(set, map_where_reduce){
    int arr[] ={1,3,2,4,8,6,11,9,5,10};
    Set<int> s1(arr,10);
    Set<int>* s11 = s1.map(f1);
    Set<int>* s22 = s1.where(f3);
    int k = s1.reduce(f2,0);
    string str1 = s11->savedeepset();
    string str2 = s22->savedeepset();
    EXPECT_EQ(k, 59);
    EXPECT_EQ(str1, " 3 6 9 12 15 18 24 27 30 33");
    EXPECT_EQ(str2, " 3 4 5 6");
}