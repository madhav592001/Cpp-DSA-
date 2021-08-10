// Heaps are of two types -> MIN_HEAP and MAX_HEAP

// but in STL , there is only implementation of MAX_HEAP that is called
// priority Queue

// time complexities->push = O(log(n))
//     pop = O(log(n))
//         top = O(1)
//             size = O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>> maxHeap;              // max heap
    priority_queue<int, vector<int>, greater<int>> minHeap ; // min heap
     
     maxHeap.push(2) ; 
     maxHeap.push(3) ; 
     maxHeap.push(1) ; 

     cout<<maxHeap.top() ; // 3
     maxHeap.pop()  ; 
     cout<<maxHeap.top() ; // 2

     minHeap.push(4) ;  // same commands 
     
   return 0;
}