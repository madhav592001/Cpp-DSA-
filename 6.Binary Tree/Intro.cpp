#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Pre-order Traversal

void preOrder(struct node *root)
{

    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// InOrder traversal

void inOrder(struct node *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// postOrder

void postOrder(struct node *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end - 1; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

// making tree from preorder and inorder

node *buildTree(int preorder[], int inorder[], int start, int end) // start and end of inorder
{

    static int idx = 0 ;
    if (start > end)
        return nullptr;
    int curr = preorder[idx];
    idx++;
    struct node *node = new struct node(curr);
    if (start == end)
        return node;
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);
    return node;
}

void inorderPrint(node *root)
{
    if (root == nullptr)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

// Build tree from postorder and inorder

node *buildTreefromPostOrder(int postorder[], int inorder[], int start, int end)
{

    static int idx = end;

    if (start > end)
        return nullptr;

    int val = postorder[idx];
    idx--;
    node *curr = new node(val);

    if (start == end)
        return curr;

    int pos = search(inorder, start, end, val);

    curr->right = buildTreefromPostOrder(postorder, inorder, pos + 1, end);
    curr->left = buildTreefromPostOrder(postorder, inorder, start, pos - 1);

    return curr;
}

int32_t main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left = new node(4);
    root->left->right = new node(5);

    return 0;
}