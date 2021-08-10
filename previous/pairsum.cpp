#include<bits/stdc++.h>
using namespace std ; 

int pairsum(int arr[] , int n , int k ){
int low = 0 ; 
int high = n-1 ; int sum = 0  ;
while(low<high){
    sum = arr[low] + arr[high] ; 
    if(sum==k) return 1 ; 
    
    else if( sum > k ) high-- ;

    else low++ ;
    }
    return 0 ;
}

int main(){

int n ; 
cout<<"enter the size of array ";
cin>>n;
int k ; 
cout<<"enter the number" ; 
cin>>k;
int arr[n] ;
for( int i = 0 ; i < n ; i++) cin>>arr[i] ; 
cout<< pairsum(arr,n,k) ; 



}