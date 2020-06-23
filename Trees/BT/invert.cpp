/*
https://leetcode.com/problems/invert-binary-tree/
The question is same as find mirror of a tree.

The basic idea is to swap the left and the right subtree of all the nodes only
once.

For that we need to find a suitable Traversal.

Both Preorder and Postorder works but not Inorder.. Why?


     4
   /   \
  2     7
 / \   / \
1   3 6   9

Following inorder: Left Root Right

At node:1
We swap left and right subtree(NULL,  NULL)

Then at node: 2
We again swap left and right subtree

     4
   /   \
  2     7
 / \   / \
3   1 6   9

Now acc to inorder, we need to move Right. Can you spot the problem now?

Therefore, we are going to use either preorder or postorder

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == NULL)
      return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};