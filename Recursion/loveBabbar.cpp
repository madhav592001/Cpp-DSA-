#include <bits/stdc++.h>
using namespace std;

void convert_to_number(string s)
{
    if(s.length() == 0) return ; 

    string arr[] = { "zero" , "one" , "two" , "three" , "four" , "five" } ; 

    cout<<arr[s[0]] ; 
    string ros = s.substr(1,s.length()-1) ; 
    return convert_to_number(ros) ; 
}

int main()
{
    string s ;
    cin >> s ;

    convert_to_number(s);

    // cout<<fibonacci ;

    return 0;
}