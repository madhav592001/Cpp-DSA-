#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define N 100
vector<int> adj[N];
vector<bool> vis(N);
stack<int> st;

void dfs(int node)
{
    vis[node] = true;
    for (auto it : adj[node])
    { 
        if (!vis[it])
        {
            vis[it] = true;
            dfs(it);
        }
    }
    st.push(node);
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

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    cout << "The topological sort is : ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}