
// Strategy 
// 1 . use two stacks - current level and next level 
// 2 . variable left to right
// 3 . if lefttoright , push left child then right else push right child then left


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int main()
{
    
    return 0;
}