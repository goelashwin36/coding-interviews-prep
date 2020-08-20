/*
 * Author: Ashwin Goel
 */

/*
 Check for Balanced Tree

Practice the problem here:
https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

Before coming to this problem, learn how to find height of a Binary Tree.

In this problem:
1. We simply find the height of the left and the right subtree
2. Calculate the absolute diff and if it's greater than 1 then false is returned
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

//This helper function is used to calculate height of the left and the right subtree
//If the difference between both is found to be greater than on the "isBal" is made "false".
int isHeightBalancedHelper(Node *root, bool &isBal)
{
    if (!root)
        return 0;

    int leftHeight = isHeightBalancedHelper(root->left, isBal);
    int rightHeight = isHeightBalancedHelper(root->right, isBal);

    if (abs(leftHeight - rightHeight) > 1)
        isBal = false;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root)
{
    bool isBal = true;
    isHeightBalancedHelper(root, isBal);

    return isBal;
}
