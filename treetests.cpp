#include "tree.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>
TEST(bTree, inputoutput){
    bTree<int> t1;
    t1.addtotree(1);
    t1.addtotree(2);
    int arr[] ={1,3,2,4,8,6,7,9,5,10};
    bTree<int> t2(arr,10);
    vector<int> v1 = {5,3,2,4,8,9,7,6};
    bTree<int> t3(v1);
    bTree<int> t4(t2);
    vector<int> vv1 = t1.savetree();
    vector<int> vv2 = t1.savebfstovector();
    vector<int> vv3 = t2.savetree();
    vector<int> vv4 = t2.savebfstovector();
    vector<int> vv5 = t3.savetree();
    vector<int> vv6 = t3.savebfstovector();
    vector<int> vv7 = t4.savetree();
    vector<int> vv8 = t4.savebfstovector();
    ASSERT_THAT(vv1, testing::ElementsAre(1,2));
    ASSERT_THAT(vv2, testing::ElementsAre(1,2));
    ASSERT_THAT(vv3, testing::ElementsAre(1,2,3,4,5,6,7,8,9,10));
    ASSERT_THAT(vv4, testing::ElementsAre(1,3,2,4,8,6,9,5,7,10));
    ASSERT_THAT(vv5, testing::ElementsAre(2,3,4,5,6,7,8,9));
    ASSERT_THAT(vv6, testing::ElementsAre(5,3,8,2,4,7,9,6));
    ASSERT_THAT(vv7, testing::ElementsAre(1,2,3,4,5,6,7,8,9,10));
    ASSERT_THAT(vv8, testing::ElementsAre(1,3,2,4,8,6,9,5,7,10));
}
TEST(bTree,adddelete){
    int arr[] ={1,3,2,4,8,6,7,9,5,10};
    int arr2[] = {8,4,-2,5,6,9,11};
    bTree<int> a1(arr,10);
    bTree<int> a2(arr2,7);
    a2.addtotree(7);
    a2.deleteelem(9);
    a2.addtotree(3);
    a1.deleteelem(7);
    a1.deleteelem(3);
    vector<int> v1 = a1.savebfstovector();
    vector<int> v2 = a2.savebfstovector();
    ASSERT_THAT(v1, testing::ElementsAre(1,4,2,8,6,9,5,10));
    ASSERT_THAT(v2, testing::ElementsAre(8,4,11,-2,5,3,6,7));
}
TEST (bTree, boolfunctions){
    int arr[] ={1,3,2,4,8,6,7,9,5,10};
    bTree<int> t1(arr,10);
    int arr2[] ={3,2,4,8};
    bTree<int> t2(arr2,4);
    int arr3[] ={8,4,-2,5,6,9,11};
    bTree<int> t3(arr3,8);
    ASSERT_TRUE(t1.istreesequal(t2.GetRoot()));
    ASSERT_FALSE(t1.istreesequal(t3.GetRoot()));
    ASSERT_TRUE(t1.searchbool(7));
    ASSERT_FALSE(t1.searchbool(11));
    ASSERT_FALSE(t1.searchbool(-2));
}
TEST(bTree,balance){
    int arr[] ={2,1,3,4,8,6,7,9,5,10};
    bTree<int> t1(arr,10);
    EXPECT_EQ(4,t1.findbalance());
    t1.balancetree();
    ASSERT_LT(t1.findbalance(),2);
    ASSERT_GT(t1.findbalance(),-2);
}
int func1(int d){
    return (3*d);
}
int func2(int a, int b){
    return a + b;
}
bool func3(int a){
    if (a > 2 && a < 7){
        return true;
    }
    else{
        return false;
    }
}
TEST(bTree, map_where_reduce){
    int arr[] ={2,1,3,4,8,6,7,9,5,10};
    bTree<int> t1(arr,10);
    bTree<int>* t2 = t1.map(func1);
    bTree<int>* t3 = t1.where(func3);
    int g = t1.reduce(func2, 0);
    vector<int> v1 = t2->savetree();
    vector<int> v2 = t3->savetree();
    ASSERT_THAT(v1, testing::ElementsAre(3,6,9,12,15,18,21,24,27,30));
    ASSERT_THAT(v2, testing::ElementsAre(3,4,5,6));
    EXPECT_EQ(g, 55);
}