// subarray of size k with palindromic concatenation

// palindrome -> words that are spelled the same from foreword as well as backword

//  for a given array and an integer k , check if any subarray of size k exists in teh array such that concatenation of elements form a palindrome

// approach 1 : generate all subarrays -> O(n^2)
//              check if their concatenation forms a palindrome -> O(n)

// Approach : store concatenatinon of initial k elements
//   iterate over the array and start deleting elements from the start and edding elements from the end
//   at each step , check if concatenation is a palindrome

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(int n)
{
    int temp = n;
    int number = 0;

    while (temp > 0)
    {
        number = number * 10 + temp % 10;
        temp = temp / 10;
    }
    if (number == n)
    {
        return true;
    }
    return false;
}

int findPalindromicSubarray(vector<int> arr, int k) // return the starting point
{
    int num = 0;

    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }

    if (isPalindrome(num))
    {
        return 0;
    }

    for (int j = k; j < arr.size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];  // pehle hatayenge aur jodenge

        if (isPalindrome(num))
        {
            return j - k + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;

    int ans = findPalindromicSubarray(arr, k);

    if (ans == -1)
        cout << "No subarray exists";
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}