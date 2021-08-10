#include<iostream>
#include<vector>
using namespace std;

#define N 500
vector<int> adj[N]; // array of vectors ( read from right to left )

int main()
{
    int n, m;
    cout << "ENTER THE NO OF NODES AND EDGES : ";
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y; // connected from where to where
        cin >> x >> y;

        adj[x].push_back(y); // us vector ma push back kiya y ko aur vice versa
        adj[y].push_back(x);
    }

    cout << "Adjacency list of the above graph is given by: ";

    for (int i = 1; i < n + 1; i++)
    {
        cout << i << "->";
        vector<int>::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}