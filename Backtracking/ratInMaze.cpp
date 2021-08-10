#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{

    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }

    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArr)
{

    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;   //? reached the end 
        return true; // base case
    }
    if (isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;

        if (ratInMaze(arr, x + 1, y, n, solArr)) // calling recursively
        {
            return true; // uske age chal sakte ha ke nhi
        }
        if (ratInMaze(arr, x, y + 1, n, solArr))
        {
            return true;
        }
        solArr[x][y] = 0; // if both if condition does not return true then there is no way reaching the destination
        return false;     // backtracking
    }
    return false;
}
int main()
{
    int n;
    cout << " enter the size of matrix : ";
    cin >> n;

    cout << "enter the values in form of 0 and 1 in which 0 for unsafe position and 1 for safe position " << endl;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0,n ,solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Your rat can not reach its final destination " << endl;
    }
    return 0;
}