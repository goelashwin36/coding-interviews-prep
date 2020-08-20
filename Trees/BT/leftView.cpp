

/*
 * Author: Ashwin Goel
 */

/*
 Left View of Binary Tree

Practice the problem here:
https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

To visualize the problem, you can see the leftmost node in ever level is displayed.

This means we need to consider two things:
1. For every level, store the left most node
2. Iterate in such a way that the left most node of any level is accessed first(Inorder)

Therefore,

We simply iterate using Inorder traversal
Consider a map: mp[level][node->data]

For every level, if it's not present in the map then we add a key value pair (level, node->data)

Since we are iterating in such a way that leftmost node in a level is always iterated first

Therefore, once we add the key value pair in map, we don't need to modify it.

Consider:


          1
       /     \
     2        3
   /         /
  4         6
   \
     8

Inorder Traversal:

Node Level
 4  -  2(New)
 8  -  3(New)
 2  -  1(New)
 1  -  0(New)
 6  -  2(Repeated)
 3  -  1(Repeated)

 Out left view = 1 2 4 8

 It can be seen that we've only considered nodes which are encountered for the first time in that level.

 Hope you've got a good idea about the solution now.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;           //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

// Method that returns the left view.

void leftViewHelper(Node *root, int level, int horz, map<int, int> &mp)
{

    if (root == NULL)
        return;

    leftViewHelper(root->left, level + 1, horz - 1, mp);

    if (mp.find(level) == mp.end())
        mp[level] = root->data;

    leftViewHelper(root->right, level + 1, horz + 1, mp);

    return;
}

void leftView(Node *root)
{
    map<int, int> mp;

    leftViewHelper(root, 0, 0, mp);

    for (auto itr : mp)
    {
        cout << itr.second << " ";
    }
}
