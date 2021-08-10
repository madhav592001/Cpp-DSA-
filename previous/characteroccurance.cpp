#include<bits/stdc++.h>

using namespace std ; 

int main(){
    string s  ; 
    cout<<"enter string" ;
    getline(cin,s) ; 

    int check[256] ; 
    for( int i = 0 ; i < 256 ; i++)
    check[256] = 0 ;

   for( char c : s){
       int index = (int) c ;
       check[index]++;
   }

for( int i = 0 ; i < 256 ; i++){
    int current = check[i] ; 
    int j = i-1 ; 
    while( check[j] > current && j>=0){
        check[j+1] = check[j] ; 
        j-- ; 
    }
    check[j+1]  = current ; 
}
cout<<check[255] ; 
return 0 ;
}