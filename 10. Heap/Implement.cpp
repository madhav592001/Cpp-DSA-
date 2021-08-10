// we will implement min heap ->
// 1. getMini() -> returns the root element of minheap .
// 2. getMax() -> returns the root element of Max Heap .
// 3. extractMin() -> removes the mimimum element from minheap . O(n) .
// 5. insert() -> inserting a new key takes O(logn) time . we add a new key new key at the end of the tree . if new key is greater the its parent , then we don't need to do anything . Otherwise , we need to traverse up to fix the violated heap properly .
// 6. delete() -> deleting a key also takes O(logn) time. WE replace the key to be deleted wigh mimimum infinite by aclling decreseKey() , the minus infinite value must reach root , so we call extractMin() to remove the key .
// 5. heapify() -> heapify is the process of creating a heap datastructure from a binary tree. it is used to create Min or Max heap .

#include <iostream>
#include <math.h>
#include<climits>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    a = temp;
}

class MinHeap
{
public:
    int *harr;     // pointer to array of elements in heap
    int capacity;  // max. possible size of min heap
    int heap_size ; // current size

    MinHeap(int cap)
    {
        heap_size = -1 ; 
        capacity = cap;
        harr = new int[cap]; // dynamic memory allocation
    }

    void lineraSearch(int val)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == val)
            {
                cout << "Value found ";
                return;
            }
        }
        cout << "value not found ";
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << harr[i] << " ";
        }
    }

    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    void insertKey(int k)
    {
        if (heap_size >= capacity)
        {
            cout << "Overflow ";
            return;
        }

        heap_size++;

        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i); // returns (i-1) / 2 to check above
        }
    }

    void MinHeapify(int i)
    {
        int l = left(i);  // index 1
        int r = right(i); // index 2 returns
        int smallest = i; // smallest = harr[0] or 0

        if (l < heap_size && harr[l] < harr[i])  // if left is small
            smallest = l;

        if (r < heap_size && harr[r] < harr[smallest])   // left is small then right check
            smallest = r;

        if (smallest != i)        // i should be smallest because it is MinHeap
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin()
    {
        if (heap_size <= 0)
            return INT_MAX; // check condition in main func. and if it
                            // INT_MAx then no elements

        if (heap_size == 1)
        {
            heap_size--; // only one value
            return harr[0];
        }

        int root = harr[0]; // more than one elements .

        harr[0] = harr[heap_size - 1]; // last element in the heap

        heap_size--;

        MinHeapify(0); // index 0 // entire heap is recreated 

        return root;
    }

    void decreseKey(int i , int new_val) {
        harr[i] = new_val ;   //value decrese kar di taaki minHeap rule break ho jaye new value = INT_MIN

        while(i!=0 && harr[parent(i)] > harr[i] ){
            swap(harr[parent(i)] , harr[i] ) ; // jisko delete karna ha vo smallest jayegi
            i = parent(i) ; 
        }
    }

    void deleteKey(int i)
    { 
        decreseKey(i,INT_MIN) ; //min value kyuki root pe laana ha

        extractMin() ; // fir smallest ko delete karke arrange kar denge 
                        //extractMin ma heapify function bhi hota ha (arrange karne ke liye)
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
    // int s;
    // cout << "enter the size of MinHeap : " << endl;
    // cin >> s;
    // MinHeap obj(s);
    // cout << "MinHeap created" << endl;

    // int option, val;

    // do
    // {
    //     cout << "What you want to perform ? "
    //          << "select option number . Enter 0 to exit " << endl;

    //     cout << "1.Insert key " << endl;
    //     cout << "2 search key " << endl;
    //     cout << "3. delete key " << endl;
    //     cout << "4.get min" << endl;
    //     cout << "5. extract min" << endl;
    //     cout << "6.height of heap" << endl;
    //     cout << "7. print / traverse heap values " << endl;
    //     cout << "8. clear screen" << endl;
    //     cout << "0.exit program" << endl;

    //     cin >> option;

    //     switch (option)
    //     {
    //     case 1:
    //         cout << "Enter the value to INSERT in Heap : ";
    //         cin >> val;
    //         obj.insertKey(val);
    //         break;

    //     case 2:
    //         cout << "Enter the value to search : ";
    //         cin >> val;
    //         obj.lineraSearch(val);
    //         break;

    //     case 3:
    //         cout << "Enter the index no to delete : ";
    //         cin >> val;
    //         // obj.deleteKey(val) ;
    //         break;

    //     case 4:
    //         cout << "Get Min value : ";
    //         // cout<<obj.getMin() ;
    //         break;

    //     case 5:
    //         cout << "Extract Min Value : ";
    //         cout<<obj.extractMin()<<endl ;
    //         break;

    //     case 6:
    //         cout << "Heap height : ";
    //         cout << obj.height() << endl;
    //         break;

    //     case 7:
    //         cout << "print Heap array : " << endl;
    //         obj.printArray();
    //         break;

    //     case 8:
    //         system("cls");
    //         break;

    //     default:
    //         cout << "Enter proper number";
    //         break;
    //     }

    // } while (option != 0);
    return 0;
}