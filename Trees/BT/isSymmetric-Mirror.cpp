/*
 * Author: Ashwin Goel
 */

/*
Symmetric Tree

Practice the problem here:
https://practice.geeksforgeeks.org/problems/symmetric-tree/1


The idea is simple.

1. A tree is symmetric if at every node the left and right subtree are mirror or each other
2. Two trees are mirror of each other if
    2.1 Both the roots have same value
    2.2 Right subtree of the left tree and left subtree of the right tree should be mirror images.
    2.3 Left subtree of the left tree and the right subtree of the right tree should be mirror images.

         5
       /   \
      1     1
     /       \
    2         2

Therefore, we take two nodes in the helper function(root1 and root2)
Initially, both of them point to the root node.

We know that data of both the nodes should be same or both of them should be null.
Also, (root1->left, root2->right) should be mirror images and
(root1->right, root2->left) should also be mirror images as discussed above.

At the end, we take the "logical AND" of all these conditions.

*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isSymmetricHelper(struct Node *root1, struct Node *root2)
{
    //If both nodes are NULL
    if (!root1 && !root2)
        return true;
    //If any one is NULL
    if (!root1 || !root2)
        return false;

    return root1->data == root2->data && isSymmetricHelper(root1->left, root2->right) && isSymmetricHelper(root1->right, root2->left);
}

bool isSymmetric(struct Node *root)
{
    return isSymmetricHelper(root, root);
}