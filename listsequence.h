
#ifndef LAB2ND_LISTSEQUENCE_H
#define LAB2ND_LISTSEQUENCE_H

#include <iostream>
#include "sequence.h"
#include "linkedlist.h"
template <class T>
class LinkedListSequence:public Sequence<T>{
private:
    LinkedList <T>* items;
public:
    LinkedListSequence (T* data, int size){
        this->items = new LinkedList<T> (data, size);
    }
    explicit LinkedListSequence (int size){
        this->items = new LinkedList<T> (size);
    }
    LinkedListSequence (){
        this->items = new LinkedList<T>;
    };
    LinkedListSequence (LinkedListSequence<T> &list){
        this->items = new LinkedList<T> (* list.items);
    }
    ~LinkedListSequence (){
        delete items;
    }
    T GetFirst() const{
        return items->GetFirst();
    }
    T GetLast() const{
        return items->GetLast();
    }
    int GetLength() const{
        return items->GetLength();
    }
    T Get(int index) const{
        return items->Get(index);
    }
    void Append(T item) {
        this->items->Append(item);
    }
    void Prepend(T item) {
        items->Prepend(item);
    }
    void InsertAt(T item, int index){
        items->InsertAt(item, index);
    }
    void Set(int index, T data){
        items->Set(index, data);
    }
    Sequence<T>* GetSubSequence(int start, int end){
        auto* SubList = new LinkedListSequence<T>;
        SubList->items = items->GetSubList(start, end);
        return (Sequence<T>*)SubList;
    }
    Sequence<T>* Concat(Sequence<T>* list){
        auto* ConCatList = new LinkedListSequence<T>;
        ConCatList->items = items->Concat(((LinkedListSequence<T>*)(list))->items);
        return (Sequence<T>*)ConCatList;
    }
};
#endif