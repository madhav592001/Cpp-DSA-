//*                Disjoint Set Union

#include<bits/stdc++.h>
using namespace std ; 

#define N 20 ;
vector<int> parent[N] ; 
vector<int> rank[N] ;            //? or size

void makeSet()
{
    for(int i = 0 ; i < n ; i++)
    {
        parent[i] =i ;
        rank[i] = 0 ; 
    }
}

int findParent(int node)
{
    if(node == parent[node])
    {
        return node ; 
    }
    else parent[node] =  findParent(parent[node]) ;   //? also doing Path compression
}

void union(int x , int y)
{
    x = findParent(x) ; 
    y = findParent(y) ; 

    if(rank[x] < rank[y])                 //!     Smaller rank should be connected to larger rank
    {
        parent[x] = y ; 
    }
    else if(rank[x] > rank[y])
    {
        parent[y] = x ;
    }
    else
    {
        parent[y] = x ;
        rank[x]++ ; 
    }
}

int main()
{
    makeSet() ; 
    return 0 ; 
}