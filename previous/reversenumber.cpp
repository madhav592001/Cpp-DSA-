#include<iostream>
using namespace std ;
int main(){
    int n ;
    cout<<"enter the no.";
    cin>>n;

    int reverse =0 ;
    int temp = n ;
    while(n>0){
        temp = n%10;
        n = n/10;
        reverse = reverse*10 + temp;
    }
    cout<<"the reverse of the no is "<<reverse;
}