#include<bits/stdc++.h>
using namespace std ; 

void swap( int *a , int *b){
    int temp = *b ; 
    *b = *a ; 
    *a = temp ; 
    } 

    int main(){
     
     int a = 10 ;  int b = 202 ; 
     int *aptr ; int *bptr ; 
     aptr = &a ; bptr = &b ; 

     swap(&a,&b) ;

     cout<<a<<" "<<b ; 
     return  0 ; 
    }