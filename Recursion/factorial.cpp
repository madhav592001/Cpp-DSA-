#include<iostream>
using namespace std ;

int fact(int n ){
	if(n==1){
		return 1 ;
	}
	

	return n * fact(n-1);
}
int main(){
	int n;
	cout<<" enter the no for which you have to calculate factorial ";
	cin>>n;
	cout<<fact(n) ;
}