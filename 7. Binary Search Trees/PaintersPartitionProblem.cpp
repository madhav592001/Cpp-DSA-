// n -> length of n different boards
// m -> painters available

// a painter paints 1 unit of board in 1 unit of time and each painter will paint cnsecutive boards . fingd the minimum time that will be riquired to paint all the boards .

// Strategy :
// apply binary search for mimimum and maximum possible values of 'min' length of boards to be painted

// chech feasiblity - assign boards to each painter in a sequential manner , while the current length of assigned boards don't exceed the value set by binary search .
// if during the allocation the number of painters don't exceed the limit of 'm' then the solutin is feasible . else it is not

#include <iostream>
using namespace std;

int findFeasible(int boards[], int n, int limit)
{
    int sum = 0;
    int painters = 1;

    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (sum > limit)
        {
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}

int PaintersPartition(int boards[], int n, int m)
{
    int totalLength = 0;
    int k = 0; // largest board size
    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }

    int low = k;
    int high = totalLength;

    while (low < high)
    {
        int mid = (low + high) / 2;
        int painters = findFeasible(boards, n, mid);
        if (painters <= m)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;
    cout << "Mimimum time to paint boards : " << PaintersPartition(arr, n, m);
    return 0;
}