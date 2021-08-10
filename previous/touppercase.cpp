#include<bits/stdc++.h>
using namespace std ;

int main() {
    string str ; 
    cout<<"enter the string" ; 
       getline(cin , str) ; 

       for( int i = 0 ; i < str.size() ; i++){

        if( str[i] <= 'z' && str[i] >= 'a')
           str[i] -= 32 ; 

       }
       
// convert to lower case  +32  
       cout<<str ; 


}