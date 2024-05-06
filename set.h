#ifndef LAB3_SET_H
#define LAB3_SET_H
#include "tree.h"
#include <algorithm>
using namespace std;
template <class T>
class Set{
private:
    bTree<T>* set;
    vector<T> vspomintersect(vector<T> a1, vector<T> a2){
        int count = a2.size();
        vector<T> vec;
        for(int i = 0; i < count; i++){
            if(find(a1.begin(), a1.end(), a2[i]) != a1.end()){
                vec.push_back(a2[i]);
            }
        }
        return vec;
    }
public:
    //constructors
    Set(){
        set = new bTree<T>;
    }
    Set(T* items, int count){
        this->set = new bTree<T>(items, count);
    }
    explicit Set(vector<T> vec){
        this->set = new bTree<T>(vec);
    }
    Set(const Set<T> & s){
        this->set = new bTree<T>(*s.set);
    }

    //add and delete
    void addelem(T item){
        this->set->addtotree(item);
    }
    void deleteelem(T item){
        this->set->deleteelem(item);
    }

    //bool functions
    bool search(T item){
        return this->set->searchbool(item);
    }
    bool subset(Set<T>* s){
        vector<T> a1 = s->set->savetree();
        vector<T> a2 = this->set->savetree();
        int count = a1.size();
        int d = 0;
        for(int i = 0; i < count; i++){
            if(set->searchbool(a1[i])){
                d++;
            }
        }
        if(d == count){
            return true;
        }
        else{
            return false;
        }
    }
    bool equal(Set<T>* s){
        vector<T> a1 = s->set->savetree();
        vector<T> a2 = this->set->savetree();
        if(a1 == a2){
            return true;
        }
        else{
            return false;
        }
    }

    //maths functions
    Set<T>* plus(Set<T>* s){
        auto* newSet = new Set(*this);
        vector<T> a1 = s->set->savebfstovector();
        newSet->set->addmanyfromvector(a1);
        return newSet;
    }
    Set<T>* intersect(Set<T>* s) {
        vector<T> a1 = s->set->savebfstovector();
        vector<T> a2 = this->set->savebfstovector();
        vector<T> v1 = vspomintersect(a1, a2);
        auto* a = new Set<T>(v1);
        return a;
    }
    Set<T>* minus(Set<T>* s){
        auto* newSet = new Set(*this);
        vector<T> a1 = s->set->savebfstovector();
        int count = a1.size();
        for(int i = 0; i < count; i++){
            if(this->set->searchbool(a1[i])){
                newSet->set->deleteelem(a1[i]);
            }
        }
        return newSet;
    }

    //save to string functions
    string savedeepset(){
        vector<T> a1 = set->savetree();
        return this->set->savetostring(a1);
    }
    string savebfsset(){
        vector<T> a1 = set->savebfstovector();
        return this->set->savetostring(a1);
    }
    vector<T> save_vector(){
        return set->savebfstovector();
    }
    //map, where, reduce
    Set<T>* map(T(*func)(T)){
        auto* newSet = new Set<T>;
        newSet->set = this->set->map(func);
        return newSet;
    }
    Set<T>* where(bool(*func)(T)){
        auto* newSet = new Set<T>;
        newSet->set = this->set->where(func);
        return newSet;
    }
    T reduce(T(*func)(T,T), T d){
        T res = d;
        res = this->set->reduce(func, res);
        return res;
    }
};

template <typename T>
void printSet(Set<T>* s){
   s->set->printtree();
}
#endif //LAB3_SET_H
