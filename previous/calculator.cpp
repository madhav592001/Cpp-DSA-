#include<iostream>
using namespace std;

int main(){
    int a , b ;
    char x;
    cout<<"enter two numbers" ;
    cin>>a>>b;

    cout<<"enter the operation + , - , / ,* ";
    cin>>x;

    switch (x){
        case '+' :
        cout<<"the sum of the no. is "<<a+b<<endl;
        break;

        case '-' :
        cout<<"the minus of two no are "<<a-b<<endl;
        break;

         case '/' :
        cout<<"the division of two no are "<<a/b<<endl;
        break;

         case '*' :
        cout<<"the minus of two no are "<<a*b<<endl;
        break;

        default:
        cout<<"wrong operation";
    }
    return 0 ;
}