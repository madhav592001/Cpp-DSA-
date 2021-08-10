// we are given n items with weight and value {weight,value} of each item and the capacity of knapsack(Sack) 'W' . we need to put these items in knapsack such that final value of items in knapsack is maximum .

// value - 21 24 12 40 30
// weight -7  4  6  5  6

// W = 20kg

// we will find value per unit weight - 3 6 2 8 5

// then sort in decresing order according to value per unit weight pick from the starting till capacity .

// Maximum value - 40+24+30+15(3*5) = 109

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double v1 = (double)p1.first / p1.second;
    double v2 = (double)p2.first / p2.second; // calculating value per unit

    return v1 > v2;
}

int main()
{
    int n;
    cout << "Enter the no of items : ";
    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    int w;
    cout << "Enter the max. weight of Knapsack : ";
    cin >> w;

    sort(a.begin(), a.end(), compare);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (w >= a[i].second)
        {
            ans += a[i].first; // value
            w -= a[i].second;  // weight
            continue;
        }

        double vw = (double)a[i].first / a[i].second; // agar kisi item ka pura value nhi aaya to isiliye

        ans += vw * w;                                // jitna bhi weight bacha ha uski max. value per unit weight

        w = 0;
        break;
    }

    cout << "The maximum value is : " << ans;

    return 0;
}