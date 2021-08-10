// count no of subarrays with sum 0
// given an array = 1 -1  1  -1

// we will store prefix sum of elements in an array .

// prefix sum is the sum till i'th element you traversed in array

// 1 -1 1 -1 -> 1 0 1 0

// for an array of prefix sum if two elements repeat then i+1 to j-1 .

// Approach =
// 1. map prefix sum to a map .
// 2. for every key choose 2 values from all the occurances of particular prefsum(Mc2) ;
// 3. special case : for prefSum = 0 , we have to also include them .

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> count;

    int prefSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefSum += a[i];
        count[prefSum]++;
    }

    int ans = 0;

    map<int, int>::iterator it;

    for (it = count.begin(); it != count.end(); it++)
    {
        int c = it->second;

        ans += (c * (c - 1)) / 2;

        if (it->first == 0)
        {
            ans += it->second;
        }
    }

    cout << ans << endl;

    return 0;
}