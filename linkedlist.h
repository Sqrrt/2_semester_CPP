
#ifndef LAB2ND_LINKEDLIST_H
#define LAB2ND_LINKEDLIST_H

#include <iostream>
#include "myexception.h"
using namespace std;
template <class T>
class LinkedList{
private:
    struct Node{
        T data;
        Node* next;
    };
    Node* head;
    Node* end;
    int size;
public:
    LinkedList(){
        head = nullptr;
        end = nullptr;
        size = 0;
    }
    LinkedList(T* items, int count){
        if (count < 0){
            throw my(1,(char*) "Size must be positive");
        }
        head = new Node;
        size = count;
        Node* count2 = head;
        head->data = items[0];
        for (int j = 1; j < count - 1; j++){
            Node* node = new Node;
            node->data = items[j];
            count2->next = node;
            count2 = node;
        }
        end = new Node;
        count2->next = end;
        end->next = nullptr;
        end->data = items[count-1];
    }
    LinkedList(int count){
        if (count < 0){
            throw my(1,(char*) "Size must be positive");
        }
        head = new Node;
        size = count;
        Node* count2 = head;
        head->data = T();
        for (int j = 1; j < count - 1; j++){
            Node* node = new Node;
            node->data = T();
            count2->next = node;
            count2 = node;
        }
        end = new Node;
        count2->next = end;
        end->next = nullptr;
        end->data = T();
    }
    LinkedList (LinkedList<T> & list) {
        size = list.size;
        if (size > 0) {
            head = new Node;
            head->data = list.head->data;
            Node *prevNode = head;
            Node *listnode = list.head->next;
            while (listnode != nullptr) {
                Node *newNode = new Node;
                newNode->data = listnode->data;
                prevNode->next = newNode;
                prevNode = newNode;
                listnode = listnode->next;
            }
            prevNode->next = nullptr;
            end = prevNode;
        }
    }
    ~LinkedList(){
        Node* temp = head;
        while(temp != nullptr){
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    int GetLength() const{
        return size;
    }
    T GetFirst() const{
        return head->data;
    }
    T GetLast() const{
        return end->data;
    }
    T Get(int index) const{
        index = index - 1;
        if (index < 0){
            throw my(1,(char*) "Size must be positive");
        }
        if (index >= size){
            throw my(2,(char*) "Index out of range");
        }
        else{
            Node* count = head;
            for (int i = 0; i < index; i++){
                count = count->next;
            }
            return count->data;
        }
    }
    void Prepend(T element){
        Node * temp = new Node;
        temp->data = element;
        size++;
        if(head == nullptr){
            head = temp;
            end = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }
    void Append(T item){
        Node* tmp = new Node;
        tmp->data = item;
        tmp->next = nullptr;
        size++;
        if(head == nullptr) {
            head = tmp;
            end = tmp;
            return;
        }
        end->next = tmp;
        end = tmp;
    }
    void InsertAt (T item, int index){
        if(index == 1){
            Prepend(item);
            return;
        }
        if(index == size + 1){
            Append(item);
            return;
        }
        if (index <= 0){
            throw my(1,(char*) "Size must be positive");
        }
        if (index > size + 1){
            throw my(2,(char*) "Index out of range");
        }
        else {
            index = index - 1;
            Node *tmp;
            tmp = head;
            Node *last;
            Node *newNode = new Node;
            newNode->data = item;
            for (int i = 0; i < index; i++) {
                if (i + 1 == index) {
                    last = tmp;
                }
                tmp = tmp->next;
            }
            Node *a = last->next;
            last->next = newNode;
            newNode->next = a;
            size += 1;
        }
    }
    LinkedList<T>* GetSubList (int start, int endd){
        if (start <= 0 || endd <= 0){
            throw my(1,(char*) "Size must be positive");
        }
        if (start > size + 1 || endd > size + 1){
            throw my(2,(char*) "Index out of range");
        }
        if (start > endd){
            throw my(3,(char*) "enter start index first");
        }
        endd = endd - 1;
        start = start - 1;
        auto* SubList = new LinkedList<T>;
        SubList->size = endd - start + 1;
        Node* first = head;
        for (int i = 0; i < start; i++){
            first = first->next;
        }
        SubList->head = new Node;
        SubList->head->data = first->data;
        Node* prev = SubList->head;
        for(int j = start + 1; j <= endd; j++){
            first = first->next;
            Node* temp = new Node;
            temp->data = first->data;
            prev->next = temp;
            prev = temp;
        }
        prev->next = nullptr;
        SubList->end = prev;
        return SubList;
    }
    LinkedList<T>* Concat (LinkedList<T>* list){
        auto* pList = new LinkedList<T>(*this);
        if(list->size == 0){
            return pList;
        }
        pList->size = this->size + list->size;
        Node* prev = new Node;
        pList->end->next = prev;
        prev->data = list->head->data;
        Node* newNode = list->head->next;
        for(int i = 1; i < list->size; i++){
            Node* temp = new Node;
            prev->next = temp;
            temp->data = newNode->data;
            newNode = newNode->next;
            prev = temp;
        }
        prev->next = nullptr;
        pList->end = prev;
        return pList;
    }
    void Set(int index, T item){
        if (index <= 0){
            throw my(1,(char*) "Size must be positive");
        }
        if (index > size){
            throw my(2,(char*) "Index out of range");
        }
        Node* count = head;
        for(int i = 0; i < index - 1; i++){
            count = count->next;
        }
        count->data = item;
    }
};
#endif //LAB2ND_LINKEDLIST_H