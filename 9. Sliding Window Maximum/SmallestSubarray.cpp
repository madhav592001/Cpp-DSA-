// for a given array and an integer x , find the minimum subarray size for which sum = x

// Brute force -> O(n^2)

// Sliding Window -
// 1. use variable ans , sum and start
// 2. Iterate over array and start adding elements to sum
// 3. If sum>x , remove elements from the start

#include <iostream>
using namespace std;

int minSubarraySize(int arr[], int n, int x)
{
    int sum = 0;
    int minLength = x + 1;
    int start = 0, end = 0;

    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }

        while (sum > x && start < n)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;
    int ans = minSubarraySize(arr, n, x);

    if (ans == n + 1)
    {
        cout << "No subarray exists ";
    }
    else
    {
        cout << "The minimum size of subarray is : " << ans;
    }
    return 0;
}