#include <iostream>
#include <vector>
using namespace std;

#define N 100
vector<int> adj[N];
vector<bool> vis(N, false);
vector<bool> dfsVis(N);

bool isCycle(int node)
{
    vis[node] = true;
    dfsVis[node] = true;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (isCycle(it))
            {
                return true;
            }
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = false;         //! we are moving back from recursive calls (backtracking)
    return false;
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
    }

    bool cycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i))
            {
                cycle = true;
            }
        }
    }

    if (cycle)
        cout << "There is a cycle";
    else
        cout << "There is no cycle";

    return 0;
}