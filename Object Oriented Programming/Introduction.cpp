#include <bits/stdc++.h>
using namespace std;

class student
{

    string name;

public:
    int age; // by  default all data members are private
    bool gender;

    student()
    {
        cout << "default constructor " << endl; // default constructor
    }

    student(string s, int a, int g)
    {
        cout << "paramaterized constructor ";
        name = s; // parametrized constructor
        age = a;
        gender = g;
    }

    student(student &a)
    {
        cout << "default copy constructor ";
        name = a.age; // default copy consturctor
        age = a.age;
        gender = a.gender;
    }

    void SetName(string s)
    {             // setter function
        name = s; // agar kisi ko public nhi karna ha to use function ma istemaal karne ke liye
    }

    void getName()
    {
        cout << name << endl;
    }

    void printInfo()
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "gender : " << gender << endl;
    }

    ~student()
    {
        cout << "destructor called " << endl; // it is called when we move out of main function
    }

    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    student a("madhav", 19, 0);

    student b("rahul ", 10, 0);

    student c = a; // copy constructor          student c = a ;    one more method

    if (c == a)
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }

    return 0;
}

// student arr[3] ;

//    for(int i = 0 ; i<3 ; i++){
//     string s ;
//     cout<<"name : " ;
//     cin>>s ;
//     arr[i].SetName(s) ;
//     cout<<"age : " ;            // baar baar na karna pade isliye class ka array bana liya
//     cin>>arr[i].age ;
//     cout<<"gender ( 0 for male  and 1 for female ) : " ;
//     cin>>arr[i].gender ;
//    }

//    for(int i = 0 ; i<3 ; i++ ){
//        arr[i].printInfo() ;
//    }

//     student a ;
//     a.name = "madhav"  ;
//     a.age = 19 ;
//     a.gender = 0 ;