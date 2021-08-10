// for a given array , find the peak element in the array . peak element is one which is greater than both left and right .

// corner cases :
// ascending array : last array is peak
// descending  : first element
// all same : each element is peak

// Strategy : use binary search , analyse indices from 0 to n-1

#include <iostream>
using namespace std;

int findPeak(int arr[], int low, int high, int n)
{
    int mid = (low + (high - low)) / 2;

    if ((mid == 0 or arr[mid - 1] <= arr[mid]) and (mid == n - 1 or arr[mid + 1] <= arr[mid]))
    {
        return mid;
    }

    else if (mid > 0 and arr[mid - 1] > arr[mid])
    {
        return findPeak(arr, low, mid - 1, n);
    }
    else
    {
        findPeak(arr, mid + 1, high, n);
    }
}

int main()
{
    int arr[] = {0, 6, 8, 5, 7, 9};
    int n = 6;

    int peak = findPeak(arr, 0, n - 1, n);

    cout << "Peak element is on : " << peak;
    return 0;
}