#include<iostream>
using namespace std ; 

int main(){
int a  ,   b  , c ;

cout<< " enter the value of integers \n" ;
cin>>a;cin>>b;cin>>c;

if(a>b){
    if(a>c){
        cout<<"a is largest" ;
    }else cout<<"c is largest";
}else{
    if(b>c) cout<<"b is largest";
    else cout<<" c is largest";
}



}