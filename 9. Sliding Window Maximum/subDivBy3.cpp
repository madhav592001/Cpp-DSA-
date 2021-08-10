// Number formed from subarray of size k , divisible by 3

// for a given array and an integer k , check if any subarray of size k exists in the array such that elements in the subarray form a number divisible by 3

// a no is only and only divisible by 3 if sum of its digits is divisible by 3

// approach :
// 1. sum of initial k elements from the array
// 2. use sliding window technique and one by one , start substraccting elements from the end and adding from the end .
// 3. At each step , chack if sum divisible by 3 or not . It it is , print the elements .

#include <iostream>
#include <vector>
using namespace std;

void computeNumberFromSubarray(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    bool found = false;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (found)
            break;

        sum = sum + arr[i] - arr[i - k];

        if (sum % 3 == 0)
        {
            ans = make_pair(i - k + 1, i);
            found = true;
        }
    }

    if (!found)
    {
        ans = make_pair(-1, 0);
    }
    if (ans.first == -1)
    {
        cout << "Answer does not exist";
    }
    else
    {
        cout << "The starting number is " << arr[ans.first] << " and the ending number is " << arr[ans.second];
    }
}

int main()
{
    vector<int> arr = {84,23,45,12,56,82} ;
    int k = 3 ; 
    computeNumberFromSubarray(arr,k) ; 
    return 0;
}