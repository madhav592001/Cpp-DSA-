#include<iostream>
using namespace std ;

int fiboonaci(int n){
	if(n==0) return 0 ;
	if(n==1 ){
		return 1 ; 
	}
	return fiboonaci(n-1) + fiboonaci(n-2) ; 
}

int main(){
	int n  ; 
	cout<<"enter the position " ; 
	cin>>n ; 
	cout<<"the fiboonaci series is "<<fiboonaci(n) ;
	return 0 ;
}