
#ifndef LAB2ND_MYEXCEPTION_H
#define LAB2ND_MYEXCEPTION_H

#include <iostream>
#include <exception>
using namespace std;
class my{
private:
    int number;
    char* str;
public:
    my(int a, char* str){
        this->number = a;
        this->str = str;
        cout<< "error "<< number << ", " << str << endl;
    }
};
#endif //LAB2ND_MYEXCEPTION_H