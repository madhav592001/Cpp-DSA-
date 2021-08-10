#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

#define N 20
vector<pair<int, int>> adj[N];
vector<bool> vis(N, false);
stack<int> st; // toposort


void topoSort(int node) // DFS
{
    vis[node] = true;

    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            vis[it.first] = true;
            topoSort(it.first);
        }
    }
    st.push(node);
}

void shortestPath(vector<int> &dis)
{
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dis[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dis[node] + it.second < dis[it.first])  //  todo: src ka distance aur uska weight add karke uska dist kam aa rha ha to
                {
                    dis[it.first] = dis[node] + it.second;       // todo: replace kar do
                }
            }
        }
    }

    cout << "The distance of following nodes from source : " << endl;

    for (auto i : dis)
    {
        cout << i << " : " << dis[i] << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the no of nodes and edges : ";
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Enter the edge and weight : ";
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    vector<int> dis(n, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoSort(i);
        }
    }

    
    int src;
    cout << "Enter the src : ";
    cin >> src;

    dis[src] = 0;

    shortestPath(dis);

    return 0;
}
