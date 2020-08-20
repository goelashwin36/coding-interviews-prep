

/*
 * Author: Ashwin Goel
 */

/*
 Bottom View of Binary Tree

Practice the problem here:
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

For every node, consider two properties: level and horizontal distance

Level is the level of a node.
Horizontal distance is the horizontal distance from the the root.

Consider the below Binary Tree:

         10
       /    \
      20    30
     /  \
    40   60

Bottom View = 40 20 60 30

For Node = 10: Horizontal Distance = 0, Level = 0
Moving Down
For Node = 20: Horizontal Distance = -1(one node left of 10), Level = 1
For Node = 30: Horizontal Distance = +1(one node right of 10), Level = 1
Moving Down
For Node = 40 Horizontal Distance = -2(two nodes left of 10), Level = 2
For Node = 60 Horizontal Distance = 0(Exactly below the root), Level = 2

Now compairing the Bottom View and these distances, we can make out for any horizontal distance, node with maximum level should be considered.

The solution implements the same idea.

We use a map to store (node,level) corresponding to a horz distance.
If at any horz distance, if no node in the map is present or level of current node > level of node stored in the map, we change the node.


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

// Method that returns the bottom view.

void bottomViewHelper(Node *root, map<int, pair<int, int>> &mp, int horz, int level)
{

    if (root == NULL)
        return;
    //Iterating in Preorder
    //If no node corresponding to horz is present or its level is less than current level
    if (mp.find(horz) == mp.end() || mp[horz].second <= level)
        mp[horz] = make_pair(root->data, level);

    bottomViewHelper(root->left, mp, horz - 1, level + 1);
    bottomViewHelper(root->right, mp, horz + 1, level + 1);
}
vector<int> bottomView(Node *root)
{
    vector<int> res;
    map<int, pair<int, int>> mp;

    bottomViewHelper(root, mp, 0, 0);

    //Filling res vector from the map
    for (auto itr : mp)
        res.push_back(itr.second.first);

    return res;
}
