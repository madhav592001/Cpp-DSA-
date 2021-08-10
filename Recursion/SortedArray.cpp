#include<iostream>
using namespace std ;

bool sorted(int a[] , int n ){

	if(n==1){
		return true ;
	}

bool restArray = sorted( a + 1 , n-1);

return ( a[0] < a[1] && restArray ) ; 

}

int main(){
	int n ;
	cout<<"enter the size of array " ; 

	int a[n] ; 

    cout<<"enter the elements of array" ;

	for ( int i=0 ; i<n ;i++){
		cin>>a[i];
	}

	if(sorted(a,n)){
		cout<<"the array is sorted" ; 
	}else{
		cout<<"the array is not sorted"  ; 
	}
	return 0 ;
}