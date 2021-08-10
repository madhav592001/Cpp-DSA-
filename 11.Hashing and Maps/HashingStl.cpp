// for hashing , there are two Data Structures

//              Maps         UnOrdered-Maps
// insertion   O(logn)          O(1)
// accessing   O(logn)          O(1)
// deletion     O(logn)         O(n)   in this map got better

// Maps are implemented using Red-Black trees . 

// UnOrdered-Maps are implemented using HashTables( basically
// array of buckets )

// Maps are keyvalue pairs - key value 

//    map<int,int> mp ; 
//    unordered_map<int,int> mp ; 


#include<bits/stdc++.h>
using namespace std ; 

int main()
{ 
    map<int,int> m ; 

    m[8] = 2 ; // like array 
    
    cout<<m[8] ; 

    return 0 ; 
}
