#ifndef LAB2ND_VECTOR_H
#define LAB2ND_VECTOR_H
#include "arraysequence.h"
#include "listsequence.h"
#include "sequence.h"
#include <cmath>
using namespace std;
template <class T>
class myvector{
private:
    Sequence<T>* vec;
public:
    myvector() {
        this->vec = new ArraySequence<T>();
    }
    myvector(myvector<T> & v){
        this->vec = new ArraySequence<T>(*(ArraySequence<T>*) v.vec);
    }
    myvector(int size){
        this->vec = new ArraySequence<T>(size);
    }
    myvector(T* items, int count){
        this->vec = new ArraySequence<T>(items, count);
    }
    int GetLength() const{
        return this->vec->GetLength();
    }
    T Get(int index) const{
        return this->vec->Get(index);
    }
    T GetFirst() const{
        return this->vec->GetFirst();
    }
    T GetLast() const{
        return this->vec->GetLast();
    }
    void Append(T item){
        this->vec->Append(item);
    }
    void Prepend(T item){
        this->vec->Prepend(item);
    }
    void InsertAt(T item, int index){
        this->vec->InsertAt(item, index);
    }
    myvector<T>* plus(myvector<T>* v){
        auto* v2 = new myvector<T>();
        if(this->vec->GetLength() == v->GetLength()) {
            for (int i = 0; i < v->GetLength(); i++) {
                 v2->vec->Append(v->Get(i+1) + this->vec->Get(i+1));
            }
        }
        else{
            throw my(3,(char*) "Different sizes of vectors");
        }
        return v2;
    }
    myvector<T>* mult(double num){
        auto* v2 = new myvector<T>();
        for(int i = 0; i < this->vec->GetLength(); i++){
            v2->Append(this->vec->Get(i+1) * num);
        }
        return v2;
    }
    void Set(int index, T item){
        this->vec->Set(index, item);
    }
    double length(){
        double l = 0;
        for(int i = 0; i < this->vec->GetLength(); i++){
            l = l + (this->vec->Get(i+1))* (this->vec->Get(i+1));
        }
        l = sqrt(l);
        if(l > 0) {
            l = round(l * 100) / 100;
        }
        if(l < 0){
            l = round(-l * 100) / 100;
        }
        return l;
    }
    T multscalar(myvector<T>* v){
        T m = 0;
        if(this->vec->GetLength() == v->GetLength()) {
            for (int i = 0; i < v->GetLength(); i++) {
                m = m + (v->Get(i+1) * this->vec->Get(i+1));
            }
        }
        else{
            throw my(3,(char*) "Different sizes of vectors");
        }
        return m;
    }
    myvector<T>* GetSubVector(int start, int end){
        auto* v2 = new myvector<T>();
        v2->vec = this->vec->GetSubSequence(start, end);
        return v2;
    }
    myvector<T>* Concat(myvector<T>* v){
        auto* v2 = new myvector<T>();
        v2->vec = this->vec->Concat(v->vec);
        return v2;
    }
};
#endif