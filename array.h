
#ifndef LAB2ND_ARRAY_H
#define LAB2ND_ARRAY_H

#include <iostream>
#include "myexception.h"
using namespace std;
template <typename T>
class DynamicArray {
private:
    T *data;
    int size;
    int capacity;
public:
    DynamicArray(){
        data =  nullptr;
        size = 0;
        capacity = 0;

    }
    explicit DynamicArray(int siz) {
        if (siz < 0){
            throw my(1,(char*) "Size must be positive");
        }
        size = siz;
        capacity = siz;
        data = new T[siz];
        for (int i = 0; i < siz; i++) {
            data[i] = T();
        }
    }
    DynamicArray(DynamicArray<T> &dynamicArray) {
        size = dynamicArray.size;
        capacity = size;
        data = new T[size];
        for (int j = 0; j < size; j++) {
            data[j] = dynamicArray.data[j];
        }
    }
    ~DynamicArray() {
        delete[] data;
    }
    int GetSize() const{
        return size;
    };
    T Get(int index) const{
        if (index < 0){
            throw my(1,(char*) "Size must be positive");
        }
        if (index > size){
            throw my(2,(char*) "Index out of range");
        }
        return data[index-1];
    };
    void Set(int index, T value) {
        if (index > size){
            throw my(2,(char*) "Index out of range");
        }
        if (index < 0){
            throw my(1,(char*) "Index must be positive");
        }
        else {
            data[index - 1] = value;
        }
    }
    DynamicArray(T *items, int count2) {
        int count = count2;
        if (count < 0){
            throw my(1,(char*) "Size must be positive");
        }
        int i = 0;
        size = count;
        capacity = count;
        data = new T[size];
        while( i != count) {
            data[i] = items[i];
            i++;
        }
    }
    void setter(int index, T value){
        if (index <= 0){
            my(1,(char*) "Size must be positive");
            throw exception();
        }
        if (index > size){
            throw my(2,(char*) "Index out of range");
        }
        data[size] = data[size - 1];
        for(int i = size - 1; i > index - 1; i--){
            data[i] = data[i-1];
        }
        data[index - 1] = value;
    }
    void Resize(int newSize) {
        if (newSize > capacity) {
            int newCapacity = max(newSize, size * 2);
            T *newData = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            data = newData;
            capacity = newCapacity;
            size = newSize;
        }
        if (newSize <= capacity) {
            T* newData = new T[capacity];
            for (int i = 0; i < newSize; i++) {
                newData[i] = data[i];
            }
            data = newData;
            size = newSize;
        }
    }
};
#endif //LAB2ND_ARRAY_H