// for
//     a given array and integers k and x, find the maximum sum subarray of size k and having sum less than x.

// approach 1 : compute sum  of all possible subarrays of size k .
// T.C -> O(n*k)

// approach 2 :
// 1 . calculate sum of first K elements .
// 2 . initialize ans with this sum
// 3 . iterate over rest of array
//     keep adding one element in sum and removing one from start
//     compare new sum wigh ans in each iteration
// T.C -> O(n)

#include <bits/stdc++.h>
using namespace std;

void maxSubArraySum(int arr[], int n, int k, int x)
{

    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int ans = 0;

    if (sum < x)
    {
        ans = x;
    }

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k - 1 ];
        sum = sum + arr[i];

        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }
    cout << ans << " is the max subarray sum that is less than x";
}

int main()
{
    int arr[] = {7,5,4,6,8,9} ; 
    int n = 6 ; 
    int k = 3 ; 
    int x = 20 ; 
    maxSubArraySum(arr,n,k,x) ; 
    return 0;
}