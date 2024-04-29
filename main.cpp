#include <iostream>
#include "sequence.h"
#include <gtest/gtest.h>
using namespace std;
int main(int argc, char** argv) {
        testing::InitGoogleTest(&argc, argv);
        cout << "Hello, World!\n";
        return RUN_ALL_TESTS();
}