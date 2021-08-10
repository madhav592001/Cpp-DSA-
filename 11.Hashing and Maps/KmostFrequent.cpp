// top k most frequent element in the stream .

// Given an array : 1 2 2 2 3 4
// and  k = 2

// we have to output elements in decreasing frequency till we reach (k+1)th distinct elements .

// 1 -> 1
// 2 -> 1 2 3
// 3 -> (k+1)th elements

// Approach
// 1. create a map .
// 2 while travelling , keeep track of elements and when we find (k+1)th without element = break ;
// 3. Output the element and frequency using map

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        int presentSize = freq.size();

        if (freq[a[i]] == 0 && presentSize == k)
        {
            break;
        }

        freq[a[i]]++;
    }

    vector<pair<int, int>> ans;
    map<int, int>::iterator it;

    for (it = freq.begin(); it != freq.end(); it++)
    {
        if (it->second != 0)
        {
            ans.push_back(it->second, it->first);
        }
    }

    sort(ans.begin(), ans.end(), greater<pair<int, int>>);

    vector<pair<int,int>>::iterator it1;

    for (it1 = ans.begin(); it1 != ans.end(); it1++)
    {
        cout << it1->second << " " << it1->first << endl;
    }
    return 0;
}