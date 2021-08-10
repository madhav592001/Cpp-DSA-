#include<iostream>
using namespace std ;

void inc(int n){
if(n==0 ) return;
inc(n-1) ; 
cout<<n<<" " ;  
}


int main(){
	int n ; 
	cout<<"enter the n " ; 
	cin>>n ; 

   inc(n) ; 
}