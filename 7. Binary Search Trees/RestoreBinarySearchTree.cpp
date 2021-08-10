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

void calcPointers(Node *root, Node *first, Node *mid, Node *last, Node *prev)
{
    if (root == nullptr)
    {
        return;
    }
    calcPointers(root->left, first, mid, last, prev);

    if (prev and root->data < prev->data)
    {
        if (first)
        {
            first = prev;
            mid = root;
        }
        else
        {
            last = root;
        }
    }
    prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void RestoreBst(Node *root)
{
    Node *first, *mid, *last, *prev;
    first = mid = last = prev = nullptr;

    calcPointers(root, first, mid, last, prev);

    if (first and last)
    {
        swap(&(first->data), &(last->data));
    }

    else if (first and mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

void inorder(Node* root) { 
    if(root== nullptr) return ; 

    inorder(root->left) ; 
    cout<<root->data << " " ; 
    inorder(root->right) ; 
}

int main()
{
    Node *root = new Node(6) ; 
    root->left = new Node(9) ; 
    root->right = new Node(3) ; 
    root->left->left = new Node(1) ; 
    root->left->right = new Node(4) ; 
    root->right->right = new Node(13) ; 
    inorder(root) ; 
    cout<<endl ; 
    RestoreBst(root) ; 
    inorder(root) ; 
    return 0;
}

// Strategy
// bst's inorder sequence is always sorted
// elements in  a sorted array are swapped

// Case 1 -  swap elements are not adjacent to each other .
// Case 2 -  swap elements are adjacent

// Maintain three pointers first last and mid

// case 1 -  {1,8,3,5,5,6,7,2}
// first : previous node where 1'st number < previous that is 8
// mid : number where 1'st number < previous[3]
// last : 2'nd node where number < previous[3]

// case 2 - {1,2,4,3,5,6,7,8}
// first : previous node where 1'st time property violates or < previous[4]
// mid : mid no where 1'st number < previous[3]
// last : nullptr
// swap first and mid