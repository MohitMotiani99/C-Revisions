/*
MULTIPLE INHERITANCE

    -eg: class C:public B,public A
    -order of constr exec is B->A->C
    
    -Diamond Problem
        --when 2 super classes of a class have a common base
            class.
        --constr & destr of common base called twice when an object of derived
            class of subclasses is created
        --so final class has 2 copies of all members of superbase
            so ambiguities.
        --virtual inheritance of super base classes by 2 derived classes
        --this always calls the def constr(0 param) of super base
            class even when we want to call parametrised one.
        --so sol is call superbase class constr also in grandchild constr
        

*/

#include<bits/stdc++.h>
using namespace std;
class Person{
  public:
    Person(int x){
        cout<<"Person(int) called"<<endl;
    }
    Person(){
        cout<<"Person() called"<<endl;
    }
};
class Faculty:virtual public Person{
  public:
    Faculty(int x):Person(x){
        cout<<"Faculty(int) called"<<endl;
    }
};
class Student:virtual public Person{
  public:
    Student(int x):Person(x){
        cout<<"Student(int) called"<<endl;
    }
};
class TA:public Faculty,public Student{
    public:
        TA(int x):Student(x),Person(x),Faculty(x){//order here doesnt matter
            cout<<"TA(int)"<<endl;
        }
};
int main(){
    TA ta1(30);
}
