#include<iostream>
using namespace std ;

int LastOccurance( int a[] , int n , int i , int key ){
	if(a[i] == key ){
		return i ; 
	}
	return LastOccurance( a , n , i-1 , key ) ; 
}

int main(){
	int n ; 
	cout<<"enter the size of array" ; 
	cin>>n ; 

	int a[n] ; 

	for(int i = 0 ; i < n ; i++){
		cin>>a[i] ; 
	}

     int key ; 
	cout<<"enter the key you want to find " ;
    cin>>key;

    int i = n-1 ; 
    cout<<LastOccurance(a , n ,  i ,  key ) ; 
    return 0 ;
}


// int firstOccurance( int a[] , int n , int i , int key ){
// 	if(a[i] == key ){
// 		return i ; 
// 	}
// 	return firstOccurance( a , n , i+1 , key ) ; 
// }

// int main(){
// 	int n ; 
// 	cout<<"enter the size of array" ; 
// 	cin>>n ; 

// 	int a[n] ; 

// 	for(int i = 0 ; i < n ; i++){
// 		cin>>a[i] ; 
// 	}

//      int key ; 
// 	cout<<"enter the key you want to find " ;
//     cin>>key ; 
//     int i = 0 ; 
//     cout<<firstOccurance(a , n ,  i , key ) ; 
//     return 0 ;
// }