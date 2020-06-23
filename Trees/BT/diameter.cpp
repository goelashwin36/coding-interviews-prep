/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/diameter-of-binary-tree/
We need to find the longest path betweek any two nodes in a tree.
          1
         / \
        2   3
       / \
      4   5

At Node 2,

leftHeight = 1
leftHeight = 1

dia = 1+1 = 2

We return 1+1 = 2(Height of tree with node 2 as parent)

At Node 1,

leftHeight = 2
leftHeight = 1

dia = 2+1 = 3(max diameter)


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
  int diameterOfBinaryTree(TreeNode *root, int &dia) {
    if (root == NULL)
      return 0;

    // Finding height of left and right subtree
    int leftHeight = diameterOfBinaryTree(root->left, dia);
    int rightHeight = diameterOfBinaryTree(root->right, dia);

    // Diameter at any node is leftHeight+rightHeight. We find the max of it.
    dia = max(dia, leftHeight + rightHeight);

    // Max height of the subtree is returned
    if (leftHeight > rightHeight)
      return leftHeight + 1;
    else
      return rightHeight + 1;

    // same as -> return max(leftHeight+1, rightHeight+1)
  }

  int diameterOfBinaryTree(TreeNode *root) {
    int dia = 0;
    diameterOfBinaryTree(root, dia);
    return dia;
  }
};