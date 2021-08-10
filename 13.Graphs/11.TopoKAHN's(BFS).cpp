//              KAHN's Algorithm
// 1.make an indegree array and put all the nodes which are of 0 indegree in queue .
// 2.perform dfs on them and reduce their indegrees by 1 .and print the nodes.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 50

void topoSort(vector<int> adj[], int n)
{
    queue<int> q;
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the no of NODES and EDGES : ";
    cin >> n >> m;

    vector<int> adj[N];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the edge : ";
        cin >> u >> v;

        adj[u].push_back(v);
    }

    topoSort(adj, n);

    return 0;
}
