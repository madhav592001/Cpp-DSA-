// Numbers are coming and we have to tell the median after each input
// Brute force - After every input , sort the array {n(log(n) time)}
// and then quote the median .
// Using heaps ->
// 1. keep one maxHeap and one MinHeap
// 2. Partition the array into two parts
// if sizes of maxHeap and minHeap not equal = top of larger size Heap
// else avg of top of both

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqMin;
priority_queue<int, vector<int>> pqMax;

void insert(int x)
{
    if (pqMin.size() == pqMax.size())
    {
        if (pqMax.size() == 0)
        {
            pqMax.push(x);
            return;
        }

        if (x < pqMax.top())
        {
            pqMax.push(x);
        }
        else
        {
            pqMin.push(x);
        }
    }
    else
    {
        // two cases possible
        // Case1 : size of maxHeap is greater
        // Case1 : size of minHeap is greater

        if (pqMax.size() > pqMin.size())
        {
            if (x >= pqMax.top())
            {
                pqMin.push(x);
            }
            else
            {
                int temp = pqMax.top();
                pqMax.pop();
                pqMin.push(temp);
                pqMax.push(x);
            }
        }
        else
        {
            if (x <= pqMin.top())
            {
                pqMax.push(x);
            }
            else
            {
                int temp = pqMin.top();
                pqMin.pop();
                pqMax.push(temp);
                pqMin.push(x);
            }
        }
    }
}

double findMedian()
{
    if (pqMax.size() == pqMin.size())
    {
        return (pqMin.top() + pqMax.top()) / 2.0;
    }
    else if (pqMax.size() > pqMin.size())
    {
        return pqMax.top();
    }
    else
    {
        return pqMin.top();
    }
}

int main()
{
    insert(10);
    cout << findMedian() << endl;
        insert(6);
            insert(5);
                insert(2);
                 cout << findMedian() << endl;

    return 0;
}