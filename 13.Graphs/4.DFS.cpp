#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N);

void dfs(int node)
{
    cout << node << " ";
    vis[node] = true;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
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

    cout << "The DFS of this graph is : ";

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    return 0;
}