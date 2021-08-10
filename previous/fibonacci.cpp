#include<bits/stdc++.h>
using namespace std ;

void fibonacci(int  x , int  y , int z ){
cout<<x<<" "<<y<<" ";
for ( int i = 3 ; i<= z ; i++){
    int sum  = x + y ;
    cout<<sum<<" ";
    x = y ;
    y = sum ; 
}

}

int main() {

int a  =  0 ; int  n ;
int  b  = 1 ; 
cout<<"enter n";
cin>>n;

fibonacci(a , b , n) ;

}
