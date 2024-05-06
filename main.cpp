#include <iostream>
#include "set.h"
//#include "classes.h"
using namespace std;
/*int main() {
    int arr[] = {1, 2, 3, 4, 8, 6, 7, 9, 5, 10};
    int arr2[] = {8, 4, -2, 5, 6, 9, 11};
    bTree<int> a(arr, 10);
    //bTree<int> a(1);
    //a.addmany(arr, 10);
    printtree(a);
}
    bTree<int> a2(8);
    a2.addmany(arr2, 7);
    int l = a.findbalance();
    cout<< l;
    cout<<"\n\n";
    a.balanced();
    vector<int> A2 = a.savebfs();
    a.printtree();
    string str = a.savestring(A2);
    Set<int> s1(arr,10);
    Set<int> s2(arr2, 7);
    //s1.plus(s2);
    //s1.minuus(s2);
    s1.printSet();
    cout<< "fff\n";
    s2.printSet();
    cout<< "fff\n";
    Set<int> s3 = s1.intersect(s2);
    s3.printSet();
    cout<< "fff";
    //Set<int> s3(arr, 10);
    if(s1.subset(s2)){
        cout<< "yeah";
    }
    cout<< "\n";
    if(a.booltree(a2.GetRoot())){
        cout << "yeah";
    }
    else {
        cout << "ooh";
    }
    return 0;
}*/
#include <gtest/gtest.h>
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/*
bTree<int> enter() {
    int* A;
    int b;
    cout << "Write number of elements";
    cin >> b;
    cout << "Now enter the elements";
    for (int i = 0; i < b; i++) {
        cin >> A[i];
    }
    bTree<int> t(A,b);
    return t;
}
int menutree() {
    bTree<int> t;
    bTree<int> t2;
    cout<< "What do you want to do:\n1)enter new tree\n2)enter second tree\n3)search sub tree\n4)balance tree\n5)print tree\n)";
    int s;
    cin >> s;
    switch (s) {
        case 1:
            t = enter();
            break;
        case 2:
           t2 = enter();
           break;
        case 3:
            if(t.booltree(t2.GetRoot())){
                cout<< "first tree included second";
            }
            else{
                cout<< "first tree doesn't included second";
            }
            break;
        case 4:
            t.balanced();
            break;
        case 5:
            t.printtree();
            break;
    }
}
int main() {
    int ll;
    cout << "Do you want to work:\n1)with tree\n2)with set\n3)exit";
    int q;
    cin >> q;
    while (true) {
        switch (q) {
            case 1:
                menutree();
                break;
            case 2:
                menuset();
                break;
            case 3:
                return 0;
        }
    }
}
*/
