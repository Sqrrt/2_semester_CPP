
#ifndef LAB3_MYCLASSES_H
#define LAB3_MYCLASSES_H
#include <iostream>
typedef struct PersonID{
    int series;
    int number;
}PersonID;
using namespace std;
class Student{
private:
    char* name;
    char* surname;
    char* lastname;
    PersonID id;
public:
    PersonID GetID(){
        return id;
    }
    Student (char* a,char* b, char* c, int s, int num){
        name = a;
        surname = b;
        lastname = c;
        id.number =num;
        id.series = s;
    }
    bool operator <(Student* st) const{
        if(st->id.series > id.series){
            return true;
        }
        else if(st->id.series == id.series){
            if(st->id.number < id.number){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    bool operator >(Student* st) const{
        if(st->id.series < id.series){
            return true;
        }
        else if(st->id.series == id.series){
            if(st->id.number < id.number){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    bool operator ==(Student* st) const{
        if(st->id.series == id.series && st->id.number == id.number){
            return true;
        }
        else{
            return false;
        }
    }
    ostream& operator <<(ostream &os){
        return os<< name<<" "<< surname<<" "<< id.series<<" "<< id.number;
    }
};
using namespace std;
class Teacher{
private:
    char* name;
    char* surname;
    char* lastname;
    char* subject;
    PersonID id;
public:
    Teacher (char* a, char* b, char* c, char* d, int s, int num){
        name = a;
        surname = b;
        lastname = c;
        subject = d;
        id.number =num;
        id.series = s;
    }
    PersonID GetID(){
        return id;
    }
    bool operator <(Teacher* st) const{
        if(st->id.series > id.series){
            return true;
        }
        else if(st->id.series == id.series){
            if(st->id.number < id.number){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    bool operator >(Teacher* st) const{
        if(st->id.series < id.series){
            return true;
        }
        else if(st->id.series == id.series){
            if(st->id.number < id.number){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    bool operator ==(Teacher* st) const{
        if(st->id.series == id.series && st->id.number == id.number){
            return true;
        }
        else{
            return false;
        }
    }
    ostream& operator <<(ostream &os){
        return os<< subject<<" "<< name<<" "<< surname<<" "<< id.series<<" "<< id.number;
    }
};
#endif //LAB3_MYCLASSES_H
