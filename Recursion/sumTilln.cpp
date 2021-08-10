#include<iostream>
using namespace std ;

int sumTilln(int n){
	if(n==0){
		return 0 ;
	}
	return n + sumTilln(n-1) ;
}

int main(){
	int n ;
    cout<<" enter the value of n" ;
	cin>>n;
	cout<<sumTilln(n) ; 
	return 0;
}