#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    vector<int> a(n);

    cout << "enter the elements in array : ";

    for (auto &i : a)
    {
        cin >> i;
    }

    int target;
    cout << "Enter the target : ";
    cin >> target;

    bool found = false;

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        int lo = i + 1, hi = n - 1;
        while (hi > lo)
        {
            int current = a[i] + a[lo] + a[hi];
            if (current == target)
            {
                found = true;
                break;
            }
            if (current > target)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
    }
    if (found)
        cout << "found ";
    else
        cout << "Not Found ";

    return 0;
}