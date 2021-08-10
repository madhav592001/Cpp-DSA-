//! agar acyclic ha to toposort pura ho jayega nhi to nhi hoga

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 20
vector<int> adj[N];

int main()
{
    int n, m;
    cout << "Enter the no of NODES and EDGES : ";
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the edge : ";
        cin >> u >> v;

        adj[u].push_back(v);
    }

    queue<int> q;
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;       // hamne count variable rakh liya jisse pata chalege ke toposort hua ke nhi

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (count == n)
        cout << "No cycle";
    else
        cout << "cycle";

    return 0;
}
