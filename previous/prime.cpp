#include<iostream>
using namespace std;

int main(){
 int n ; bool isPrime = true ;  
cout<<"enter the number ";
cin>>n;
for( int i = 2  ; i < n ; i++)
{
    if(n%i == 0) {

     isPrime=false ;
     break ;
     }


}
if(n==0) isPrime =false ;

if(!isPrime) cout<<"the no. is not  a prime no" ;
else cout<<"the no is prime";
return 0 ;
}