
#ifndef LAB2ND_CLASSES_H
#define LAB2ND_CLASSES_H

#include <iostream>
using namespace std;
class ComplexNumber{
private:
    double Re;
    double Im;
public:
    ComplexNumber(double a, double b){
        Re = a;
        Im = b;
    }
    ComplexNumber(){
        Re = 0;
        Im = 0;
    }
    ComplexNumber& operator = (ComplexNumber const& C)= default;
    ComplexNumber& operator + (ComplexNumber C){
        this->Re = Re + C.Re;
        this->Im = Im + C.Im;
        return (*this);
    }
    ComplexNumber& operator * (ComplexNumber& C){
        double a = Re;
        this->Re = Re * C.Re - Im * C.Im;
        this->Im = a * C.Im + Im * C.Re;
        return (*this);
    }
    bool operator == (ComplexNumber& C) const{
        if (Re == C.Re && Im == C.Im) return true;
        return false;
    }
    bool operator != (ComplexNumber & C) const{
        if (Re == C.Re && Im == C.Im) return false;
        return true;
    }
    ostream& operator << (ostream& out) const{
        return out << "Re = "<< Re << ", Im = " << Im << endl;
    }
};
typedef struct PersonID{
    int series;
    int number;
}PersonID;
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
#endif //LAB2ND_CLASSES_H