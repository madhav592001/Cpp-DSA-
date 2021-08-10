// for a given array and an integer k , find the maximum perfect numbers in a subarrayof size k .

// Perfect No. -> is a no. if it is equal to the sum of its proper divisors except the no itself .

// Trick -> 'convert the given array into a binary array with values 0 and 1 only'

// Approach -> 1. initialize a variable to store sum of divisors
//             2. traverse every no. less than arr[i] and add it to sum if it is divisor of arr[i]
//             3. if the sum of all the divisors is equal to arr[i] , then only the number is a perfect no .

// find the maximum sum of subarray from all possible subarrays of size k .

#include <bits/stdc++.h>
using namespace std;

bool isNoPerfect(int n)
{
    int sum = 1;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                sum += i;
            }
            else
            {
                sum += i + n / i;
            }
        }
    }

    if (sum == n and n!=1)
    {
        return true;
    }
    return false;
}

int maxSum(int arr[], int n, int k)
{
    if (n < k)
    {
        cout << "Invalid values ";
        return -1;
    }

    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res += arr[i];
    }
    int sum = res;

    for (int i = k; i < n ; i++)
    {
        sum += arr[i] - arr[i - k];
        res = max(res, sum);
    }
    return res;
}

int maxPerfectNo(int arr[], int n, int k)
{

    for (int i = 0; i < n; i++)
    {
        if (isNoPerfect(arr[i]))
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }

    return maxSum(arr, n, k);
}

int main()
{
    int arr[] = {28,2,3,6,496,99,8128,24} ; 
    int k = 4 ; 
    int n = 8 ; 

    cout<<maxPerfectNo(arr,n,k) <<endl ; 
    return 0;
}