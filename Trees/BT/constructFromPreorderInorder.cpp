/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
  TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder,
                            int &preStart, int inStart, int inEnd) {

    if (inEnd < inStart) {
      return NULL;
    }

    TreeNode *node = new TreeNode(preorder[preStart++]);

    int inIndex = -1;

    for (int i = inStart; i <= inEnd; i++) {
      if (inorder[i] == node->val) {
        inIndex = i;
        break;
      }
    }

    node->left =
        buildTreeHelper(preorder, inorder, preStart, inStart, inIndex - 1);
    node->right =
        buildTreeHelper(preorder, inorder, preStart, inIndex + 1, inEnd);

    return node;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

    if (inorder.size() == 0) {
      return NULL;
    }
    int preStart = 0;

    return buildTreeHelper(preorder, inorder, preStart, 0, inorder.size() - 1);
  }
};