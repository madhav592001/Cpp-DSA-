#include<bits/stdc++.h>
using namespace std ;

int linearsearch( int arr[] , int  x , int toFind){
bool ispresent = false ; int index ; 
    for( int i = 0 ; i < x ; i++){
        if( arr[i] == toFind ){ 
        index = i ;
        ispresent = true ;
        break ;
        } 
    }
    if(ispresent)  return index ;
    else return -1 ;


}

int main(){
     int n ; 
     cin>> n ;

     int a[n] ;
     for( int i = 0 ;i < n ; i++){
        cin>>a[i];
    }
    
    int key ;
    cin>>key ;
    
    cout<<linearsearch(a , n , key ) ; 
return 0 ;
}