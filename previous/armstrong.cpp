#include<iostream>
using namespace std;

int main(){

int n ;
cout<<"enter the no.";
cin>>n;

int temp = 0 ; int sum=0 ; 
int temp1 = n ;
while(temp1>0){

temp = temp1%10;
temp1 /= 10 ; 
sum += (temp*temp*temp) ;  

}
if(n == sum) cout<<"the no. is armstrong";
else cout<<"not armstrong" ;


return 0 ;
}