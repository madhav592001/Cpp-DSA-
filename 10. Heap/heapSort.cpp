#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int cap)
    {
        capacity = cap;
        heap_size = cap;
        harr = new int[capacity];
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);

        int smallest = i;

        if (i != 0 && harr[i] > harr[l])
        {
            smallest = l;
        }
        if (i != 0 && harr[smallest] > harr[r])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin()
    {
        if (heap_size <= 0)
        {
            return INT_MIN;
        }

        int root = harr[0];

        harr[0] = harr[heap_size - 1];

        heap_size--;

        MinHeapify(0);

        return root;
    }

    void HeapSort()
    {
        int temp[capacity];
        for (int i = 0; i < capacity ; i++)
        {
            temp[i] = extractMin() ;
            cout<<temp[i]<<" " ; 
        }
    }

    void getUnsortedArray()
    {
        for (int i = 0; i < capacity; i++)
        {
            cin >> harr[i];
        }
    }

    void printArray()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << harr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int s;
    cout << "Enter the size of heap ";
    cin >> s;
    MinHeap obj(s);
    obj.getUnsortedArray();
    cout << "Unsorted Array : ";
    obj.printArray();
    for (int i = (s / 2) - 1; i >= 0; i--)
    { // 4 isliye kyuki 10 ke array ma 4 he nodes ho skti ha rightMost node 2*i+2
        obj.MinHeapify(i);
    }
    cout << "heap sorted array : ";
    obj.HeapSort();
    return 0;
}