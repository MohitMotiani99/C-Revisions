/*

VIRTUAL FUNCTION
    
    -like abstract fun
    -can have body
    -overridden
    -late binding using base class ptr or ref
    -runtime plomorph
    -never static
    -not necessary for child to override
    -virtual destructor possibe
    -virtual constructor not
    
    --if a class has virtual function and object is created then
        a virtual pointer(vptr) is inserted as data memeber of
        the class to point to VTABLE of that class.
        For each object a new vptr inserted as member of class
    
    --Irrespective of obj created or not,a static array of function 
        pointer called vtable where each cell contains the address 
        of each virtual function contained in that class.
        
    --each subclass of class containing virtual fun has own
        VTABLE
        
    -cant change the sign of overriden func else error when 
        called by base class ptr bcoz base does not have that fun
    
    --when we create obj of derived class the compiler creates
        a pointer as a data memeber of the class containing
        address of VTABLE of derived class
    
    VTABLE
    --is a lookup table of funs to resolve calls in dynamic
    --every class with virtual fun or a sub class of those
        has a vtable of its own.
    --contains 1 entry for each v fun that can be called by
        the obj of the class.
    --entries are fun pointer that pts to most derived fun
        accessible by that class
    --compiler adds a *__vptr to base class and when class
        is instantiated it pts to its VTABLE;
    --vptr inherited by derived class
    --initially adds vptr to the most base class
    --if in a subclass any virtual derived fun is not 
        overridden then base fun is put in its VTABLE

*/
#include<bits/stdc++.h>
using namespace std;
/*
class base{
    public :
        virtual void print(){
            cout<<"Print Base"<<endl;
        }
        void show(){
            cout<<"Show Base"<<endl;
        }
};
class derived: public base{
    //automatically considered as virtual function
  void print(){
      cout<<"Print Derived"<<endl;
  } 
  void show(){
      cout<<"Show Derived"<<endl;
  }
};
/*int main(){
    
    derived d;
    base &ptr=d;//as a ref of child obj
    //ptr=d;
    
    //base p;
    //p=d  
    //p.print()///cant do this bcoz this will call base show
    
    base *ptr2;
    ptr2=&d;//as a ptr to derived obj
    
    ptr2->print();
    ptr2->show();
    
    ptr.print();
    
    ptr.show();
}*/

/*
 FUNCTION POINTERS
    
    --stores address of fun
    --eg: comp in sort fun
    --as a listener or callback fun
        eg:-call diff functions on diff events
    --to pass fun as an argument
    --void (*foo)(int)
        -foo is the ptr to fun taking 1 int arg and returns
        void
    --to call fun from fptr you treat it as the name of fun
    --calling auto perferms the dereferncing
    --void * ptrs can point to anything
        
*/
/*
void my_func(int x){
    cout<<x<<endl;
}
int main(){
    void (*foo)(int);
    foo=&my_func;
    foo(2);
    (*foo)(2);//this is also fine
}

*/

/*
VIRTUAL DESTRUCTOR

    -deleting a derived class obj using a ptr to base
        having non virtual destructor results in 
        undefined behaviour.
    -default dest deletes obj after the lifetine
        of the prog.
    --before a derived class constr is called all of its
        bas e class constr are called
    --before a base destructor is called destructor for all
        its child class obj is called
    --to remove undefined behaviour make base class destr
        virtual that will lead to proper order
    
*/
class base {
    public :
        base(){
            cout<<"Contructing base"<<endl;
        }
        virtual ~base(){
            cout<<"Destructing Base"<<endl;
        }
};
class derived:public base{
    public:
        derived(){
            cout<<"Contructing Derived"<<endl;
        }
        ~derived(){
            cout<<"Destructing Derived"<<endl;
        }
};
int main(){
    derived *d=new derived();
    base *b=d;
    //delete d;
    delete b;
    //derived d1=derived();
    
}
