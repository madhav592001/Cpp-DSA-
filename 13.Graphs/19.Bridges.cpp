//todo:               if ( lowestTime[adj] > time[node] )

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
#define N 20

void dfs(int node, int parent, vector<int> &tim, vector<int> &low, int &timer, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = true;
    tim[node] = low[node] = timer++ ;

    for (auto it : adj[node])
    {
        if (it == parent)            //? if its a parent means it is going backward
            continue;

        if (!vis[it])       //! agar poori dfa ke baad bhi vis nhi ha to 
        {
            dfs(it, node, tim, low, timer, vis, adj); //todo usko visit karo
            low[node] = min(low[node], low[it]);      //todo lowest possible insert karo
            if (low[it] > tim[node])                  //? agar lowestTime[adj] > time[node]
            {
                cout << node << " " << it << endl;   //todo this is a bridge
            }
        }
        else                                  //! vis ha to
        {
            low[node] = min(low[node], tim[it]); //todo apne adj ki lowest possible value rakh do
        }
    }
}

int main()
{
    int n;
    int m;
    cout << "Enter the node and edges : ";
    cin >> n >> m;

    vector<int> adj[N];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the edge : ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tim(n, -1);
    vector<int> low(n, -1);
    vector<bool> vis(n, false);
    int timer = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, tim, low, timer, vis, adj); //? -1 for parent
        }
    }

    return 0;
}