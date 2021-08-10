//*                Shortest path in undirected graph with unit weights
#include <iostream>
#include <vector>
#include <queue>
#include<climits>
using namespace std;

#define N 20

void ShortestPath(vector<int> adj[], int n, int src)      // BFS
{
    vector<int> dis(n, INT_MAX);
    queue<int> q;

    dis[src] = 0;

    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dis[node] + 1 < dis[it])
            {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }

    cout<<"The distance of following nodes from source : "<<endl ; 

    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << dis[i] << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;

    vector<int> adj[N];

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Enter the edge : ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cout << "Enter the source : ";
    cin >> src;

    ShortestPath(adj, n, src);
    

    return 0;
}