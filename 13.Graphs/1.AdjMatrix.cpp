#include <iostream>
#include <vector>
using namespace std;

// adjacency matrix

int main()
{
    int n, m;
    cout << "Enter the no of nodes and no of edges : ";
    cin >> n >> m;

    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 0)); // sabko 0 se in. kara

    cout << "Enter the connected edges" << endl;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y; // edges from where to where

        adjm[x][y] = 1; // mark the edges in matrix
        adjm[y][x] = 1;
    }

    cout << "adjacency matrix of above graph is given by : " << endl;

    for (int i = 1; i < n + 1; i++) // representation
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }

    if (adjm[3][7] == 1)
        cout << "There is an edge between 3 and 7 ";
    else
        cout << "no edge"; // find out edge or not O(1) .

    return 0;
}