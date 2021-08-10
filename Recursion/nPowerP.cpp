#include<iostream>
using namespace std ;

int nPowerP(int n , int p){
	if(p==0) return 1 ;

	return n*nPowerP(n,p-1);
}
int main(){
	int n  ; int p ;
	cout<<" enter the number"<<endl;
	cin>>n;
	cout<<"enter the power"<<endl;
	cin>>p ; 

	cout<<"n raised to the power p is "<<nPowerP(n , p ) ; 
	return 0 ; 
}