//*           take a node and chech for its minimal edge and connect it to node . Then check for both and continue till the no of nodes are
//*           equal to the actual nodes.

//!            Brute force

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, m;
    cout << "Enter the node , edge and its weight : ";
    cin >> N >> m;

    vector<pair<int, int>> adj[N];

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "enter the edge : ";
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
 
    vector<int> parent(N, -1);           // todo MST build karne ke liye
    vector<int> key(N, INT_MAX);         //? we will select shortest key among all the weights of edges
    vector<int> mst(N, false);          // ?    node is added in mst or not ye janne ke liye

    priority_queue<pair<int, int>>, vector<pair<int,int>>, greater<pair<int, int>>> pq;      //? MINHEAP : to get the minimal key value at top (key,index)

    key[0] = 0;
    parent[0] = -1;                     //!      0 ka koi parent nhi ha kyuki vo pehla element ha

    pq.push({0,0}) ;                    //? key,node (initially 0 is minimal)

    for(int count = 0 ; count < N-1 ; count++)
    {
        int u = pq.top().second ;      //? index because that is node and it will always retun minimal because it is a minHeap
        pq.pop() ; 

        mst[u] = true ;                //? minimal waale ko mst ma daala

        for(auto it : adj[u])
        {
            int v = it.first ; 
            int weight = it.second ; 
            
            if(mst[v] == false and key[v] > weight )     // todo: Sabse minimal key lenge jitni bhi nodes ha usme se
            {
                parent[v] = u ;        // todo: baad ma print karane je liye
                pq.push({key[v],v}) ;  //? pushing first so that it cannot update later
                key[v] = weight ;
            }
        }

    }

    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }

    return 0;
}