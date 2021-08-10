
// Given  an array of 0's and 1's , we may change upto k values from 0 to 1
// Return the length of the longest (contigeous) subarray that contain only 1's

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cout << "enter the size of array : ";
    cin >> n;

    vector<int> a(n);

    cout << "enter the elements of array : ";

    for (auto &i : a)
    {
        cin >> i;
    }

    int k;
    cout << "enter the k : ";
    cin >> k;

    int zerocnt = 0;
    int i = 0;
    int ans = 0;

    for (int j = 0; j < n; j++)
    {

        if (a[j] == 0) // [i...j]
        {
            zerocnt++;
        }

        while (zerocnt > k)
        {
            if (a[i] == 0)
            {
                zerocnt--;
            }
            i++;
        }
        // zerocnt <= k
        ans = max(ans, j - i + 1);
    }

    cout << ans;

    return 0;
}