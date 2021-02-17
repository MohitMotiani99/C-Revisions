/*
OPERATOR OVERLOADING

    -get ops to work for user defined classes;
    -Ret_type operator +(input){
        
    }
    -these ops cant be overloaded
        --.
        --::
        --?:
        --sizeof
    -for op overloading to work at least one of the operands
        should be user defined
    -Assignment op is already made for each class by compiler
        auto uses copy contructor
    -conversion ops can also be written
        -converting fraction class obj to float
        operator float(){
            return float(num)/float(den);
        }
        -must be member method
    -except conv other ops can be either members or global fun
    -any constr that can be called with a single argument works as a
        conv constr,means it can also be used for implicit
        conv to the class being constructed.
        
        eg:
        class Point{
            Point(int i=0,int j=0){
                x=i;y=j;
            }
        };
        int main(){
            Point t(20,30);
            t=30;//x becomes 30
        }
    -global overloading is making the global op overloaded fun
    as friend fun of class
    
    -new & delete
        
        --can be overloaded globally or internally
        --if done as member fun then these op only overloaded for 
            that particular class
            else in globally for all prog.
        --new operator
            
            -void* operator new(size_t size);
            -retuns ptr to beginning of block
        
            -eg:
            class student{
                void* operator new(size_t size){
                    void *p=::new student();//callin the global new op
                    return p;
                }
            }
            -in global overloading without class cant use 
            ::new ,it will go in rec so use
            void *p=malloc(size);
        
        --delete operator
        
            -void operator delete(void *p)
            
            -eg:
            class student{
                void operator delete(void* p){
                    free(p);
                }
            }
        --new & delete overloaded bcoz then they can accept dome 
            args also
            eg:
            void *operator new (size_t size,char c){
                void *p;
                p=malloc(size);
                if(p!=NULL)
                    *p=c;
                return p;
            }
            int main(){
                char *ch=new('#') char;
            }
        --also provide garbage collectors(https://www.educba.com/c-plus-plus-garbage-collection/)
        --exception handling can be added
        --customized ops
        --can use realloc to allocate mem dynamically
        --extra performance steps
    
*/
