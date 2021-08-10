// if a graph has odd length cycle , it is not bipartite
// if it does not have any odd length cycle it is bipartite

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<int> color(N, -1); // all -1

bool bipartiteBFS(int src)
{
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cout << "Enter the edge : ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool bipartite = true;

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (bipartiteBFS(i) == 0)
            {
                bipartite = false;
                break;
            }
        }
    }

    if (bipartite)
        cout << "it is bipartite";
    else
        cout << "it is not a bipartite ";

    return 0;
}