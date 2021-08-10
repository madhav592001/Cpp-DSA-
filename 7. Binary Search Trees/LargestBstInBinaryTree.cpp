#include <iostream>
#include <climits>
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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBst;
};

Info largestBstinBt(Node *root)
{
    if (root == nullptr)
    {
        return
        {
            0, INT_MIN, INT_MAX, 0, true 
        } ; 
    }
    if (root->left == nullptr and root->right == nullptr)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBstinBt(root->left);
    Info rightInfo = largestBstinBt(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if (leftInfo.isBst and rightInfo.isBst and leftInfo.max < root->data and rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(leftInfo.max, max(rightInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBst = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans); // agar root bst ma nhi ha to

    curr.isBst = false;
    return curr;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(20);
    root->left->left = new Node(5);
    root->right = new Node(30);

    cout << "Largest BSt in Bt : " << largestBstinBt(root).ans << endl;

    return 0;
}

// for each node store the following info .
// 1 . min in subtree
// 2 . max in subtree
// 3 . subtree size
// 4 . size of largest bst
// 5 . isBst

// Recursively , traverse in a bottom-up manner and find out the size of largests BST