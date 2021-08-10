// we are given an ascending sorted array that has been rotated from a pivot point (unknown to us ) and and element x . Seaarch for x in the array with complexity less that of linear search .

// Strategy :
// orignal array = [10,20,30,40,50]
// rotated array = [30,40,50,10,20]
// search the element : 10
// at index 3

// 1. first find the pivot point
// 2. apply binary search on both halfs .

#include <iostream>
using namespace std;

int searchInRotatedArray(int arr[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[left] <= arr[mid])
    {
        if (key >= arr[left] and key <= arr[mid])
        {
            return searchInRotatedArray(arr, key, left, mid - 1);
        }
        else
        {
            return searchInRotatedArray(arr, key, mid + 1, right);
        }
    }

    if (key >= arr[mid] and key <= arr[right])
    {
        return searchInRotatedArray(arr, key, mid + 1, right);
    }
    return searchInRotatedArray(arr, key, left, mid - 1);
}

int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int n = 8;
    int key = 11;

    int i = searchInRotatedArray(arr, key, 0, n - 1);

    if (i == -1)
        cout << "Key does not exist " << endl;
    else
    {
        cout << "key exists ";
    }
    return 0;
}