// you are given an array with n elements , calculate the maximum
// sum of k , consecutive elements.

// Brute force : 1. iterate from i = 0 to i = n-k-1 in outer loop .
// 2. starting from every j = i compute sum of k elements and maintain the minimum .

// Optimal solution :
// 1. compute sum of first k elements .
// 2. while incresing i . substract a[i-1] and add a[i+k-1] in the previous su , which will become current sum ;

#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    cout << "Enter the array elements : ";

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sum = 0, ans = INT_MAX;

    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }
    cout<<sum<<" " ; 

    ans = min(ans, sum);

    for (int i = 1; i < n - k + 1; i++)  // n -1 isliye kyuki ye lop  i+k-1 tak ka to sum le he rha ha . 
    {
        sum -= a[i - 1];
        sum += a[i + k - 1];
        ans = min(ans, sum);
        cout<<sum<<" " ; 
    }

    cout<<endl ; 
    cout << ans;

    return 0;
}