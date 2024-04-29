#ifndef LAB2ND_ARRAYSEQUENCE_H
#define LAB2ND_ARRAYSEQUENCE_H
#include <iostream>
#include "sequence.h"
#include "array.h"
template <class T>
class ArraySequence:public Sequence <T>{
private:
    DynamicArray<T>* items;
public:
    ArraySequence(){
        this->items = new DynamicArray<T>;
    };
    ArraySequence(ArraySequence<T> const &seq){
        this->items = new DynamicArray<T>(*seq.items);
    }
    explicit ArraySequence(int size2){
        this->items =new DynamicArray<T>(size2);
    }
    ArraySequence(T* items2, int count){
        this->items =new DynamicArray<T>(items2, count);
    }
    ~ArraySequence() {
        delete items;
    }
    int GetLength() const{
        return this->items->GetSize();
    }
    T Get(int index) const{
        return this->items->Get(index);
    }
    T GetFirst() const{
        return this->items->Get(1);
    }
    void Set(int index, T value){
        this->items->Set(index, value);
    }
    T GetLast() const{
        return this->items->Get(items->GetSize());
    }
    Sequence<T>* GetSubSequence(int start, int end){
        //int size = items->GetSize();
        auto* SubSequence = new ArraySequence<T>;
        for(int i = start; i <= end; i++){
            SubSequence->Append(this->items->Get(i));
        }
        return (Sequence<T>*)SubSequence;
    }
    void Append(T item){
        this->items->Resize(this->items->GetSize() + 1);
        this-> items->Set(this->items->GetSize(), item);
    }
    void Prepend(T item){
        this->items->Resize(this->items->GetSize() + 1);
        this->items->setter(1, item);
    }
    void InsertAt(T item, int index){
        this->items->Resize(this->items->GetSize() + 1);
        this->items->setter(index, item);
    }
    Sequence <T>* Concat (Sequence <T> *list){
        int newSize = this->items->GetSize() + ((ArraySequence*)list)->
                items->GetSize();
        auto* ConcatSequence = new ArraySequence<T>;
        for(int i = 0; i < this->items->GetSize(); i++){
            ConcatSequence->Append((*items).Get(i+1));
        }
        for(int j = this->items->GetSize(); j < newSize; j++){
            ConcatSequence->Append(((ArraySequence*)list)->
                    items->Get(1 + j - this->items->GetSize()));
        }
        return (Sequence<T>*)ConcatSequence;
    }
};
#endif //LAB2ND_ARRAYSEQUENCE_H