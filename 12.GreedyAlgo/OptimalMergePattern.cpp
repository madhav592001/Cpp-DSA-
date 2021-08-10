// you are given n files with their computation times in an array .

// Operation : choose / take any two files , add their computation times and append it to the list of computation times . { cost = sum of computation time } .

// do this until we are left with only one file in an array

// we have to do this computation such that we get minimum cost daily

// 5 2 4 7
//  7 11 18 -> 36 ; // not necessarily min.

// Approach :
// 1. push all the elements to MinHeap.
// 2. take top 2 elements one by one and add the cost to ans . push the merged file to the minHeap .
// 3. when a singe element remains , output the cost .

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n;
    cout << "Enter the no. of files : ";
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(a[i]);
    }

    int ans = 0;

    while (minHeap.size() > 1)
    {
        int e1 = minHeap.top();
        minHeap.pop();
        int e2 = minHeap.top();
        minHeap.pop();

        ans += e1 + e2;
        minHeap.push(e1+e2);
    }

    cout << ans << endl;
    return 0 ; 
}