#ifndef LAB3_TREE_H
#define LAB3_TREE_H

#endif //LAB3_TREE_H
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
template <typename T>
class bTree {
public:
    struct Elem {
        T data;
        Elem *l;
        Elem *r;
    };
    Elem *root;
private:
    vector<T> bfssavetovector(Elem* el){
        vector<T> v;
        queue<Elem*> q;
        q.push(el);
        while(!q.empty()){
            Elem* e = q.front();
            q.pop();
            if(e->l){
                q.push(e->l);
            }
            if(e->r){
                q.push(e->r);
            }
            v.push_back(e->data);
        }
        return v;
    }
    vector<T> savetovector(Elem* el, vector<T> items) {
        if (el->l) {
            items = savetovector(el->l, items);
        }
        items.push_back(el->data);
        if (el->r) {
            items = savetovector(el->r, items);
        }
        return items;
    }

public: void printdeep(Elem* e){
        if (e == NULL){
            return;
        }
        printdeep(e->l);
        cout<< e->data<< " ";
        printdeep(e->r);
    }
private:
    void addelem(T item, Elem **t) {
        if (*t == nullptr) {
            *t = new Elem();
            (*t)->data = item;
            return;
        }
        if((*t)->data == item){
            cout<<"element "<< item<< " repeated, it will be skipped\n";
        }
        else {
            if ((*t)->data > item) {
                addelem(item, &((*t)->l));
            }
            if((*t)->data < item) {
                addelem(item, &((*t)->r));
            }
        }
    }
    bool searchboolelem(Elem *el, T item){
        if(el == nullptr){
            return false;
        }
        if (el->data == item) {
            return true;
        }
        else {
            if (el->data > item) {
                searchboolelem(el->l, item);
            }
            else if (el->data < item) {
                searchboolelem(el->r, item);
            }
        }
    }

    void rotateright(Elem* el, Elem* el2, Elem* el3){
        if(el){
            el->r = el3;}
        el2->l = el3->r;
        el3->r = el2;
    }
    void rotateleft(Elem* el, Elem* el2, Elem* el3){
        if(el){
            el->r = el3;}
        el2->r = el3->l;
        el3->l = el2;
    }

    void tolist(){
        Elem* el = nullptr, *par = root, *el2;
        while(par != nullptr){
            el2 = par->l;
            if(el2 != nullptr){
                rotateright(el, par, el2);
                par = el2;
            }
            else{
                el = par;
                par = par->r;
            }
            if(el == 0){
                this->root = par;
            }
        }
    }
    void tobalancetree(){
        Elem* el = root;
        int n;
        n = 0;
        while(el->r){
            el = el->r;
            n++;
        }
        if(n < 3){
            return;
        }
        int m = (int)pow(2,((int)(log10(n+1)/log10(2))))-1;
        Elem* el1 = nullptr;
        Elem* par = this->root;
        Elem* el2 = this->root->r;
        this->root = this->root->r;
        for(int i = 0; i < n - m; i++){
            rotateleft(el1, par, el2);
            el1 = el2;
            par = el1->r;
            if(par) {
                el2 = par->r;
            }
            else{
                break;
            }
        }
        while(m > 1){
            m = m/2;
            Elem* ell = nullptr;
            Elem* parr = root;
            Elem* ell2 = parr->r;
            root = root->r;
            for(int i = 0; i < m; i++){
                rotateleft(ell, parr, ell2);
                ell = ell2;
                parr = ell->r;
                if(parr){
                    ell2 = parr->r;
                }
                else{
                    break;
                }
            }
        }
    }

    Elem* searchelem(Elem *el, T item) {
        if(el == nullptr){
            return NULL;
        }
        if (el->data == item) {
            return el;
        }
        else {
            if (el->data > item) {
                searchelem(el->l, item);
            }
            else if (el->data < item) {
                searchelem(el->r, item);
            }
        }
    }
//public: void summa(Elem *t, )
public: void beautifulprinttree(Elem *t,int level) {
        if (t) {
            beautifulprinttree(t->r, level + 1);
            for (int i = 0; i < level; i++) {
                cout<<"  ";
            }
            cout << t->data << endl;
            beautifulprinttree(t->l, level + 1);
        }
    }
private:
    int elembalance(Elem *t) {
        int g,f;
        if(t->r){
            int a = elemheight(t->r, 0, 0);
            g = a + 1;
        }
        else{g = 0;}
        if(t->l){
            int b = elemheight(t->l, 0, 0);
            f = b + 1;
        }
        else{f = 0;}
        return g - f;
    }
    int elemheight(Elem*t, int level, int count1){
        if (t) {
            count1 = elemheight(t->r, level + 1, count1);
            for (int i = 0; i < level; i++) {
                if (count1 < level){
                    count1 = level;
                }
            }
            count1 = elemheight(t->l, level + 1, count1);
        }
        return count1;
    }

    int equal(Elem* el1, Elem* el2, int count){
        if (el1 == nullptr && el2){
            count = 1;
            return count;
        }
        if(el2 == nullptr){
            return count;
        }
        count = equal(el1->l, el2->l, count);
        if (el1->data != el2->data) {
            count = 1;
            return count;
        }
        count = equal(el1->r, el2->r, count);
        return count;
    }

    Elem* additionaldeleteelem(Elem* el, T item){
        if(el == nullptr){
            return el;
        }
        if(item == el->data) {
            Elem *temp;
            if (el->r == NULL) {
                temp = el->l;
            } else {
                Elem *ptr = el->r;
                if (ptr->l == NULL) {
                    ptr->l = el->l;
                    temp = ptr;
                } else {
                    Elem *pmin = ptr->l;
                    while (pmin->l != NULL) {
                        ptr = pmin;
                        pmin = ptr->l;
                    }
                    ptr->l = pmin->r;
                    pmin->l = el->l;
                    pmin->r = el->r;
                    temp = pmin;
                }
            }
            delete el;
            return temp;
        }
        else if(item < el->data) {
            el->l = additionaldeleteelem(el->l, item);
        }
        else{
            el->r = additionaldeleteelem(el->r, item);
        }
        return el;
    }

    Elem* copyelem(Elem* elem){
        if(elem == NULL){
            return NULL;
        }
        Elem* el = new Elem;
        el->data = elem->data;
        el->l = copyelem(elem->l);
        el->r = copyelem(elem->r);
        return el;
    }

    void additionalMap(bTree<T>& t, Elem* el, T(*func)(T)){
        if(el) {
            t.addtotree(func(el->data));
            additionalMap(t, el->l, func);
            additionalMap(t, el->r, func);
        }
    }
    void additionalWhere(bTree<T>& t, Elem* el, bool(*func)(T)){
        if(el) {
            if (func(el->data)) {
                t.addtotree(el->data);
            }
            additionalWhere(t, el->l, func);
            additionalWhere(t, el->r, func);
        }
    }
    void additionalReduce(Elem* el, T(*func)(T, T), T& res){
        if(el) {
            res = func(el->data, res);
            additionalReduce(el->l, func, res);
            additionalReduce(el->r, func, res);
        }
    }
public:
    //constructors
    bTree (){
        root = new Elem;
        root = nullptr;
    }
    bTree(T *items, int count){
        root = new Elem;
        root->data = items[0];
        root->l = root->r = nullptr;
        for(int i = 1; i < count; i++){
            addelem(items[i],&root );
        }
    }
    explicit bTree(vector<T> vec){
        root = new Elem;
        root->data = vec[0];
        root->l = root->r = nullptr;
        int count = vec.size();
        for(int i = 1; i < count; i++){
            addelem(vec[i], &root);
        }
    }
    bTree(const bTree<T> & tree){
        if(tree.root == nullptr){
            root = nullptr;
        }
        else{
            root = copyelem(tree.root);
        }
    }

    ~bTree(){
        deleteTree(root);
    }

    //add and delete
    void addmanytotree(T *items, int count) {
        for (int i = 1; i < count; i++) {
            addelem(items[i], &root);
        }
    }
    void addmanyfromvector(vector<T> vec){
        int d = vec.size();
        for(int i = 0; i < d; i++){
            addelem(vec[i], &root);
        }
    }
    void addtotree(T item){
        addelem(item, &root);
    }
    void deleteelem(T item){
        root = additionaldeleteelem(root, item);
    }
    void deleteTree(Elem *temp) {
        if (temp != nullptr) {
            deleteTree(temp->l);
            deleteTree(temp->r);
            delete temp;
        }
    }

    //save functions
    vector<T> savebfstovector(){
        return bfssavetovector(root);
    }
    vector<T> savetree(){
        vector<T> items;
        return savetovector(root,items);
    }
    string savetostring(vector<T> &v){
        ostringstream os;
        for(T i: v) os <<" "<< i;
        return os.str();
    }

    Elem* search(T item) {
        return searchelem(root, item);
    }
    bool searchbool(T item){
        return searchboolelem(root, item);
    }

    Elem* GetRoot(){
        return root;
    }

    //balance
    int findbalance(){
        int k = elembalance(root);
        return k;
    }
    void balancetree(){
        tolist();
        tobalancetree();
    }

    // equal and subtree
    bTree<T>* subtree(bTree<T>* tree){
        auto* t = new bTree<T>;
        t->root = subtreelem(root, tree->root);
        return t;
    }
    bool istreesequal(Elem* t){
        Elem* el = searchelem(root,t->data);
        int a = equal(el,t,0 );
        if(a == 0){
            return true;
        }
        else{
            return false;
        }
    }

    //map, where, reduce
    bTree<T>* map(T(*func)(T)){
        auto* newTree = new bTree<T>;
        if (root == nullptr) {
            return newTree;
        }
        additionalMap(*newTree, root, func);
        return newTree;
    }//no changes
    bTree<T>* where(bool(*func)(T)){
        auto* newTree = new bTree<T>;
        if (root == nullptr) {
            return newTree;
        }
        additionalWhere(*newTree, root, func);
        return newTree;
    }//no changes
    T reduce(T(*func)(T,T),T d){
        T res = d;
        if (root == nullptr) {
            return res;
        }
        additionalReduce(root,  func, res);
        return res;
    }//no changes

    /*Elem* leftbalance(Elem* el){
        if(el->r) {
            Elem *temp = el->r;
            el->r = temp->l;
            temp->l = el;
            return temp;
        }
        return NULL;
    }
    Elem* rightbalance(Elem* el){
        if(el->l) {
            Elem *temp = el->l;
            el->l = temp->r;
            temp->r = el;
            return temp;
        }
        return NULL;
    }
    void rightb(){
        root = rightbalance(root);
    }
    void leftb(){
        root = leftbalance(root);
    }*/
};

template <typename T>
void printdeeptree(bTree<T> tree){
    printdeep(tree.GetRoot());
}
template <typename T>
void printtree(bTree<T> tree) {
    tree.beautifulprinttree(tree.GetRoot(), 0);
}