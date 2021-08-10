#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 6;
vector<bool> vis(N, false);
vector<int> adj[N];

void bfs(int i)
{
    if (!vis[i])
    {
        queue<int> q;
        q.push(i);
        vis[i] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    // cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        // cout << "Enter the edge : ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "The BFS of this graph is : ";

    for (int i = 1; i <= n; i++) // for all the components
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    return 0;
}
