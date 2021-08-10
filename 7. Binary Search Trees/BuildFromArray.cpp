#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node *insertBST(node *root, int val)
{
    if (root == nullptr)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Inorder of Bst is always sorted 
 
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " "; // binary search tree inorder traversal always gives us the sorted order
    inorder(root->right);
}

// normal binary tree time complexity - search - O(n) and in BST O(log n )

node *searchInBst(node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchInBst(root->left, key);
    }
    else
    {
        return searchInBst(root->right, key);
    }
}

//  Delete a Node
//  Case 1 - node is a leaf - directly delete node
//  Case 2 - node has a child - replace the node with the child
//  Case 3 - node has 2 child - 1. find the inorder succesor (inorder sequence ma 3 ke baad ane wali node)
//  2. replace the node with inorder succesor
//  3. Delete the node

node *inorderSucc(node *root)
{
    node *curr = root;
    while (curr && curr->left != nullptr)          // root ka right bheja ha 
    {
        curr = curr->left;
    }
    return curr;
}

node *deleteInBST(node *root, int key)
{

    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3 :
        node *temp = inorderSucc(root->right);  // apan ne root ka right bheja ha  kyuki sorted hota ha
        root->data = temp->data;              // aur uska right wala replace kara ha
        deleteInBST(root->right, temp->data);
    }
    return root;
}

// construct binary search tree from preorder

node *constructBst(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{

    if (*preorderIdx >= n)
    {
        return nullptr;
    }

    node *root = nullptr;
    if (key > min and key < max)
    {
        root = new node(key);
        ++*preorderIdx ;

        if (*preorderIdx < n)
        {
            root->left = constructBst(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }

        if (*preorderIdx < n)
        {
            root->right = constructBst(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }    // ek bar levt ban ke a jayega aur abhi bhi less than n ha to right 
    }

    return root;
}

void printPreorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// check for BST if a bst if given to you

bool isBst(node *root, node *min, node *max)      // minimum allowed and maximum allowed
{

    if (root == nullptr)
        return true;

    if (min != nullptr and root->data <= min->data)
    {
        return false;
    }

    if (max != nullptr and root->data >= max->data)
    {
        return false;
    }

    bool leftValid = isBst(root->left, min, root);
    bool rightValid = isBst(root->right, root, max);

    return leftValid and rightValid;
}

// sorted array to balanced binary search tree ->

// 1. make middle element the root .
// 2. Recursively , do the same for subtrees
//     a. start to mid-1 for left subtree
//     b. mid+1 to end for right subtree

node *sortedArraytoBST(int arr[], int start, int end)
{

    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);

    root->left = sortedArraytoBST(arr, start, mid - 1);
    root->right = sortedArraytoBST(arr, mid + 1, end);

    return root;
}


int main()
{

    // int arr[] = {10, 20, 30, 40, 50};
    // node *root = sortedArraytoBST(arr, 0, 4);

    // printPreorder(root);

    // node *root = new node(5);
    // root->left = new node(2);
    // root->right = new node(4);

    // cout << isBst(root, nullptr , nullptr ) ;

    // int preorder[] = {10, 2, 1, 13, 11};

    // int n = 5;
    // int preorderIdx = 0;

    // node *root = constructBst(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);

    // printPreorder(root);   

    // node *root = nullptr;
    // root = insertBST(root, 4);
    // insertBST(root, 2);
    // insertBST(root, 5);
    // insertBST(root, 1);
    // insertBST(root, 3);
    // insertBST(root, 6);
    // inorder(root) ;
    // deleteInBST (root , 5 ) ;
    // inorder(root) ;
    // print inorder to check whether it is right or wrong
    // if (searchInBst(root, 5) == nullptr)
    // {
    //     cout << "Key does not exist ";
    // }
    // else
    // {
    //     cout << "Key exist ";
    // }
    return 0;
}