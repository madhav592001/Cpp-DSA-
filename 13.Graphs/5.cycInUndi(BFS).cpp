#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N);

bool isCycle(int node, int parent)
{
    queue<pair<int, int>> q;

    vis[node] = true;
    q.push({node, parent});

    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push({it, node});
            }
            else if (par != it) // agar ye vis ha aur par it nhi ha to cycle ha
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the edge : ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i, -1))
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
    {
        cout << "Cycle is present";
    }
    else
    {
        cout << "cycle is not present";
    }
    return 0;
}