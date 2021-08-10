#include <iostream>
#include <vector>
using namespace std;

#define N 500
vector<int> adj[N];
vector<int> color(N, -1);

bool bipartiteDFS(int node)
{
    if (color[node] == -1)
    {
        color[node] = 1;
    }

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!bipartiteDFS(it))
            {
                return false;
            }
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    cout << "Enter the no of NODES and EDGES : ";
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
            if (!bipartiteDFS(i))
            {
                bipartite = false;
                break;
            }
        }
    }

    if (bipartite)
        cout << "It is a bipartite";
    else
        cout << "it is not a bipartite";
    return 0;
}