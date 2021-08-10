#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = nullptr;
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

// Catalan No se possible no of Bst's nikal rhe ha fir sab trees ko vector ma store karenge

vector<node *> ConstructTree(int start, int end) // starting value 1 aur end 3
{
    vector<node *> trees; // har tree ki root
    if (start > end)
    {
        trees.push_back(nullptr);
        return trees;
    }
    for (int i = start; i < end; i++)
    {
        vector<node *> leftSubtree = ConstructTree(start, i - 1);
        vector<node *> rightSubtree = ConstructTree(start + 1, end);

        for (int j = 0; j < leftSubtree.size(); j++)
        {
            node *left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                node *right = rightSubtree[k];
                node *node = new struct node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void printPreOrder(node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
    cout << endl;
}

int main()
{
    vector<node *> totalTrees = ConstructTree(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        printPreOrder(totalTrees[i]);
        cout << endl;
    }
    return 0;
}