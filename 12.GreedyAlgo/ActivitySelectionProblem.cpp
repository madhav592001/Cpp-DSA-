//! Problem : you are given n activities with their start time and finish time .
//! select the maximum number of activities that can be performed by a single person , assuming that a person can only work on a single activity at a time .

//! Greedy -
//! if you are at the i'th activity , what should be your next step ?

//! Take the next activity which ends first .

//! sort the activities with respect to end times .

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    cout << "Enter the no of activities : ";
    cin >> n;

    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cout << "Enter the start and end time : ";
        cin >> start >> end;

        v.push_back({start, end});
    }
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int take = 1;

    int end = v[0][1];

    for (int i = 0; i < n; i++)
    {
        if (v[i][0] >= end)
        {
            take++;
            end = v[i][1];
        }
    }

    cout << take;
}