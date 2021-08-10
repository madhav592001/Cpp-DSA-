#include <bits/stdc++.h>
#include <queue>
#include <math.h>
using namespace std;

class node
{
public:
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

// level order traversal
void printLevelOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        if (node != nullptr)
        {
            cout << node->data << " ";
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(nullptr);
        }
    }
}

// Sum at kth level
int sumAtK(node *root, int k)
{

    if (root == nullptr)
        return -1;

    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    int level = 0;
    int sum = 0;

    while (level != k)
    {

        node *node = q.front();
        q.pop();

        if (node != nullptr)
        {
            if (level == k)
            {
                sum += node->data;
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(nullptr);
            level++;
        }
    }
    return sum;
}

// count of all nodes in a binary tree
int CountNodes(node *root)
{
    if (root == nullptr)
        return 0;
    return CountNodes(root->left) + CountNodes(root->right) + 1;
}

// Sum of all the nodes  in a binary tree
int sumOfNodes(node *root)
{
    if (root == nullptr)
        return 0;
    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
}

// Height of a binary tree -> it is the depth of the tree's deepest node
int Height(node *root)
{

    if (root == nullptr)
        return 0;

    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Diameter of a binary Tree -> no of nodes in the longest path between any two leaves

// int Diameter(node *root)
// {

//     if (root == nullptr)
//         return 0;

//     int leftHeight = Height(root->left);
//     int rightHeight = Height(root->right);

//     int currDiameter = leftHeight + rightHeight + 1;

//     int leftDiameter = Diameter(root->left);
//     int rightDiameter = Diameter(root->right);

//     return max(currDiameter, max(leftDiameter, rightDiameter));
// }

int Diameter(node *root, int *height)
{

    if (root == nullptr)
    {
        *height = 0;
        return 0;
    }

    int lh = 0;
    int rh = 0;
    int lDiameter = Diameter(root->left, &lh);
    int rDiameter = Diameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

// sum replacement

void sumReplacement(node *root)
{

    if (root == nullptr)
        return;

    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left != nullptr)
    {
        root->data += root->left->data;
    }

    if (root->right != nullptr)
    {
        root->data += root->right->data;
    }
}

void preorder(node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Balanced height tree -> for each node , the difference betweeen the heights of the left subtree and right subtree <= 1

// bool isBalanced(node *root)
// {
//     if (root == nullptr)
//         return true;

//     if (isBalanced(root->left) == false)
//     {
//         return false;
//     }
//     if (isBalanced(root->right) == false)
//     {                                      // Time Complexity = n times for each node and hiehgt func. for each node O(n^2)
//         return false;                      // that is why we will write a different func.
//     }

//     int lh = Height(root->left);
//     int rh = Height(root->right);

//     if (abs(lh - rh) <= 1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// New Function

bool isBalanced(node *root, int *height) // int *height for reducing time complexity to O(n)
{
    if (root == nullptr)
    {
        return true;
    }

    int lh = 0, rh = 0;
    if (isBalanced(root->left, &lh) == false)
    {
        return false;
    }
    if (isBalanced(root->right, &rh) == false)
    {
        return false; // Time Complexity - O(n)
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Right View - the rightest element of each level

void rightView(node *root)
{

    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        int n = q.size(); // size of the nodes
        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            q.pop(); // Time Complexity O(n)
            if (i == n - 1)
            {
                cout << curr->data << " "; // right-most node
            }
            if (curr->left != nullptr)
                q.push(curr->left);

            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }
}

// Left View

void leftView(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size(); // size of the nodes
        for (int i = 0; i < n; i++)
        {
            node *temp = q.front();
            q.pop(); // Time Complexity O(n)
            if (i == 0)
            {
                cout << temp->data << " ";
            }
            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }
}

// minimum distance between two Nodes - 1. find the lca (lowest common ancestor) 2 . find distance of n1 (d1) and n2 (d2) from LCA
// 3. return d1+d2

node *lca(node *root, int n1, int n2)
{

    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }

    if (left == nullptr && right == nullptr)
    {
        return nullptr;
    }
    if (left != nullptr)
    {
        return lca(root->left, n1, n2);
    }
    if (right != nullptr)
    {
        return lca(root->right, n1, n2);
    }
}

int findDistance(node *root, int k, int dist)
{

    if (root == nullptr)
        return -1;

    if (root->data == k)
        return dist;

    int left = findDistance(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }

    return findDistance(root->right, k, dist + 1);
}

int distance(node *root, int n1, int n2)
{

    node *lca1 = lca(root, n1, n2);
    int d1 = findDistance(lca1, n1, 0);
    int d2 = findDistance(lca1, n2, 0);

    return d1 + d2;
}

// Maximum path sum - maximum possible sum of a path in a binary tree , starting and ending of any node

int maxPathSumUtil(node *root, int &ans)
{

    if (root == nullptr)
    {
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max ( root->data , max(root->data +right , root->data + left ) ) ; 
    return singlePathSum ; 
}

int maxPathSum(node *root)
{
    int ans = INT_MIN;

    maxPathSumUtil(root, ans);

    return ans;
}



int main()
{
    node *root = new node(1);
    root->left = new node(-12);
    root->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(-6);
    root->left->left = new node(4);

    cout<<maxPathSum(root) ; 

    // leftView(root);

    // int height = 0;

    // cout << isBalanced(root, &height) << endl; // height balance

    // node *root2 = new node(1);
    // root2->left = new node(2);
    // root2->left->left = new node(3);
    // cout << isBalanced(root2, &height);

    // preorder(root);
    // sumReplacement(root);
    // cout << endl;
    // preorder(root);
    return 0;
}