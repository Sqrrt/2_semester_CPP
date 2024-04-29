#ifndef LAB2ND_LINEFUNC_H
#define LAB2ND_LINEFUNC_H
#include <iostream>
#include "arraysequence.h"
#include "listsequence.h"
#include "sequence.h"
#include <cmath>
using namespace std;
template <class T>
class linefunc{
private:
    Sequence<T>* el;
    int len = 0;
public:
    linefunc(){
        this->el = new ArraySequence<T>();
    }
    explicit linefunc(int size){
        this->el = new ArraySequence<T>(size);
        this->len = size;
    }
    linefunc(linefunc<T>& f) {
        this->el = new ArraySequence<T>(*(ArraySequence<T>*) f.el);
        this->len = f.len;
    }
    linefunc(T* items, const int* x, int count, int num){
        T* it = new T[num];
        for(int i = 1; i <= num; i++){
            T a = 0;
            for(int j = 0; j < count; j++){
                if(x[j] == i){
                    a = a + items[j];
                }
            }
            it[i - 1] = a;
        }
        this->el = new ArraySequence<T>(it, num);
        this->len = num;
    }
    int GetLength() const{
        return this->len;
    }
    void Set(int index, T item){
        this->el->Set(index, item);
    }
    T Get(int index) const{
        return this->el->Get(index);
    }
    T GetFirst() const{
        return this->el->GetFirst();
    }
    T GetLast() const{
        return this->el->GetLast();
    }
    void Append(T item){
        this->el->Append(item);
        len++;
    }
    void Prepend(T item){
        this->el->Prepend(item);
        len++;
    }
    void InsertAt(T item, int index){
        this->el->InsertAt(item, index);
        len++;
    }
    linefunc<T>* GetSubLinefunc(int start, int end){
        auto* f = new linefunc<T>();
        f->el = this->el->GetSubSequence(start, end);
        f->len = end - start;
        return f;
    }
    linefunc<T>* Concat(linefunc<T>* func){
        auto* pol = new linefunc<T>();
        pol->el = this->el->Concat(func->el);
        pol->len = (this->len + func->len);
        return pol;
    }
    linefunc<T>* plus(linefunc<T>* func) {
        auto* res = new linefunc<T>();
        if(func->len != len){
            while(func->len < len){
                func->Append(0);
            }
            while(func->len > len){
                this->el->Append(0);
            }
        }
        for(int i = 0; i < len; i++){
            res->el->Append(this->el->Get(i+1) + func->el->Get(i+1));
        }
        return res;
    }
    linefunc<int>* mult(double num){
        auto* res = new linefunc<T>();
        for(int i = 0; i < this->el->GetLength(); i++){
            res->el->Append(this->el->Get(i+1) * num);
        }
        return res;
    }
    T result(T* items){
        T res = 0;
        for(int i = 0; i < len; i++){
            res = res + (items[i]) * (this->el->Get(i + 1));
        }
        return res;
    }
};
#endif //LAB2ND_LINEFUNC_H