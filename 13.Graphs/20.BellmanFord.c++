#include<iostream>
#include<vector>
#include<climits>
using namespace std ; 

struct node{
    public:
    int u,v,wt ; 

    node(int first , int second , int weight)
    {
        u = first ; 
        v = second ; 
        wt = weight ; 
    }
};

int main()
{
    int N,m ; 
    cout<<"Enter the node and edges : "  ;
    cin>>N>>m ; 

    vector<node> edges ;

    for(int i = 0 ; i < m ; i++) 
    {
        int u,v,wt ;
        cout<<"Enter the edge and weight : " ; 
        cin>>u>>v>>wt ;

        edges.push_back(node(u,v,wt)) ;
    }

    int src ; 
    cout<<"Enter the src : " ;
    cin>>src ; 

    vector<int> dist(N,INT_MAX) ;            //*          distance vector

    for(int i = 1 ; i <= N-1 ; i++)
    {
        for(auto it : edges)
        {
            if(dist[it.u] + it.wt < dist[it.v] )
            {
                dist[it.v] = dist[it.u] + it.wt ; 
            }
        }
    }

    int fl = 0 ; 
    for(auto it : edges)                    //?            To detect a negative cycle
    { 
        if(dist[it.u] + it.wt < dist[it.v] )
        {
            cout<<"Negative Cycle" ; 
            fl = 1 ;
            break ; 
        }
    }

    if(!fl)
    {
        for(int i = 0 ; i < N ; i++)
        {
            cout<<i<<" "<<dist[i] ; 
        }
    }

    return 0 ; 
}