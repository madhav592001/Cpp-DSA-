// print vertical order of binary tree
// arr = 10 7 4 3 11 14 6
// har nodos ki line ka top element jo sabse pehle waha par ha

//         10
//      7       4
//   3     11     6
//         14
// vertical order    3 7 10 11 14 4 6

// compute horizontal distance from center then left -1 and right +1 ;

// using hashing
// 1.starting root node
// 2. recursively call left and right with hd-1 and hd+1
// base case current node = null return

// make a map = key are horizontal distance and value is vector of values of that distance

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;

    node(int key)
    {
        key = key;
        left = right = nullptr;
    }
};

void getVerticalOrder(node *root, int hDis, map<int, vector<int>> &m)
{

    if (root == nullptr)
        return;

    m[hDis].push_back(root->key); // abhi hDis 0 ha isiliye root ko push

    getVerticalOrder(root->left, hDis - 1, m);
    getVerticalOrder(root->right, hDis + 1, m);
}

int main()
{
    node *root = new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->right->left = new node(6);

    map<int, vector<int>> m;

    int hDis = 0;

    getVerticalOrder(root, hDis, m);

    map<int, vector<int>>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }

    return 0;
}