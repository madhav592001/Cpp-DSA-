// indian coin change problem -

// problem - you are given an array of Denominations and a value x. you need to find the minimum number of coins to make value x .

// we have infinite supply of coins .

// approach -
// 1. start from the largest value and take it till we can , then switch to smaller one .

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no of denominations : ";
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;
    cout << "Enter the amount : ";
    cin >> x;

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += x / a[i];      // isse pata chalega ko kitne note ham utha sakte ha
        x -= x / a[i] * a[i]; //utne rupees minus kar diye (ans isliye minus nhi kiya kyuki decimal ma bhi ho sakta ha)
    }

    cout << ans << endl;
}