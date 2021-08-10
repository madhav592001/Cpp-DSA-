#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void funA()
    {
        cout << "A is inherited " << endl;
    }
};

class B : public A
{
public:
    void funB()
    {
        cout << "B is inherited " << endl;
    }
};

class C : public B
{
public:
};

int main()
{
    C c;
    c.funA();
    c.funB();
    return 0;
}

// class A{
// public:
// void fun(){
//     cout<<"inherited "<<endl ;
// }
// };

// class B : public A {                   // single inheritance
// };




// 2 . // Multiple inheritence

// class A {
//     public :
// void funcA(){
//     cout<<"inherited a "  ;
// }
// };

// class B {
//     public :
//     void funcB(){
//      cout<<"inherited b ";
//     }
// };

// class C : public A , public B{
//     public :

// };



// 3 . Multilevel inheritence
// class A {
//     public :
//     void funA(){
//         cout<<"A is inherited "<<endl  ;
//     }
// };

// class B : public A {
//     public :
//     void funB(){
//     cout<< "B is inherited "<<endl  ;
// } };

// class C : public B {
//     public :
// } ;