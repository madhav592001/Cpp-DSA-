//!        Dijkstra Algorithm : Shortest path in Undirected Graph with weights
#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n, m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];  //? adj and weight

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Enter the edge and weight : ";
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;   //!   {dis,node}

    vector<int> dis(n + 1, INT_MAX); //! distance array

    int src;
    cout << "Enter the src : ";
    cin >> src;

    dis[src] = 0;

    pq.push(make_pair(0, src));       //! dis and node

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        vector<pair<int, int>>::iterator it;         //! adj list iterator

        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            int next = it->first;
            int nextDist = it->second;

            if (dis[next] > dis[node] + nextDist)
            {
                dis[next] = dis[node] + nextDist;
                pq.push(make_pair(dis[next], next));
            }
        }
    }

    cout << "The distance from the src are : " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << dis[i] << endl;
    }

    return 0;
}
