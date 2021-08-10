#include <bits/stdc++.h>
using namespace std;

class base{
    public :
    virtual void print(){                   // we use virtual keyword to override this fun with derived class 
        cout<< "this is the base class " <<endl ; 
    }
    void display(){
        cout<<"this is the base class display fun "<<endl ; 
    }
};

class derived : public base {
  public :
  void print() {
      cout<<"this is the derived class "<<endl ; 
  }
     void display(){
        cout<<"this is the derived class display fun "<<endl ; 
    }
};


int main()
{
    base *baseptr ;
    derived d  ;
    baseptr = &d ;  

    baseptr -> print() ; 
    baseptr -> display() ; 
    return 0;
}

// function overloading  compile - time  polymorphism

// class ApnaCollege{
// public :
// void fun(){
//     cout<< "i am a function with no arguement "<<endl;
// }
// void fun(int a){
//     cout<<"i am a function with int  arguement "<<endl ;
// }

// void fun(double a){
//     cout<<"I am a function with double arguement "<<endl ;
// }

// };




// class Complex                  // compile time polymorphism
// {
// private:
//     int real, img;

// public:
//     Complex(int r = 0, int i = 0)
//     {
//         real = r;
//         img = i;
//     }

//     Complex operator+(Complex const &obj)
//     {                                           // operator overloading
//         Complex res;
//         res.img = img + obj.img;
//         res.real = real + obj.real;
//         return res;
//     }

//     void display()
//     {
//         cout << real << " + i" << img << endl;
//     }
// };