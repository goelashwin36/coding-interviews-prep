/*
 * Author: Ashwin Goel
 */

/*
Count Leaves in Binary Tree

Practice the problem here:
https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int countLeaves(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}