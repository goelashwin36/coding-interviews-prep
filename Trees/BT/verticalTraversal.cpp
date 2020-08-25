/*
 * Author: Ashwin Goel
 */

/*
Vertical Traversal of Binary Tree

Practice the problem here
https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1


If you carefully see the pattern then let's consider two attributes Horizontal distance from center(horz)
and level.

The elements are printed in the following order: First horizontal distance then level.

Consider the following.

       1
    /    \
   2      3
 /   \      \
4     5      6

Vertical Traversal: 4 2 1 5 3 6

Node Horz Level
  4   -2   2
  2   -1   1
  1    0   0
  5    0   2
  3    1   1
  6    2   2

 Therefore, what we do is consider a map(horz:vector<int>)

 We do a level order traversal so that nodes are accessed in increasing level.

 Node for every horizontal distance, we push the node's value in the map.

 At the end, we combine all the vectors in order or horizontal distances and return.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> verticalOrder(Node *root)
{
    //Do a level order traversal and store all the values in a map

    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int horz = q.front().second;
        q.pop();
        mp[horz].push_back(curr->data);

        if (curr->left)
            q.push(make_pair(curr->left, horz - 1));
        if (curr->right)
            q.push(make_pair(curr->right, horz + 1));
    }

    //Combining all the vectors
    vector<int> vertical;
    for (auto itr : mp)
    {
        for (int i = 0; i < (itr.second).size(); i++)
        {
            vertical.push_back((itr.second)[i]);
        }
    }
    return vertical;
}
