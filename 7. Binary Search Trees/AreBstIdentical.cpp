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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    else if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *root1 = new Node(1);
    root1->right = new Node(3);
    root1->left = new Node(2);
    Node *root2 = new Node(1);
    root2->right = new Node(4);
    root2->left = new Node(2);

    bool Identical = isIdentical(root1, root2);

    if (Identical)
        cout << "Both BST's are identical " << endl;
    else
        cout << "Both BST's are not identical" ;
    return 0;
}

// Strategy -
// 1 . if both empty return true ;
// 2 . check if both nodes are non-empty
//     a . check whether the data on the nodes is equal or not ;
//     b . check if left subtrees are same
//     c . if right are same
// 3. if (a,b,c) are true then true , else false