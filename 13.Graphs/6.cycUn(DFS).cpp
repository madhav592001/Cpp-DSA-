#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<bool> vis(N, false);

bool isCycle(int node, int parent)
{
    vis[node] = true;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (isCycle(i, node))
            {
                return true;
            }
        }
        else if (i != parent)       // agar visited ha to i parent ke baraabar to nhi ha 
        {
            return true;
        }
    }
    return false;
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

    bool cycle = false;

    for (int i = 1; i <= n; i++)
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
