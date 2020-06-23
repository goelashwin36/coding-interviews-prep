/*
https://leetcode.com/problems/binary-tree-inorder-traversal/
Inorder: Left Root Right

The algorithm is simple:

1. If there is a left node then add it to the stack then move to left
2. If left node is NULL then
2.1 pop the last node from stack and print it
2.2 See if the last popped node has any right pointer. If yes then move to right
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

#define pb push_back

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    // Writing iterative solution

    // This vector stores the final answer
    vector<int> res;

    if (root == NULL) {
      return res;
    }

    vector<TreeNode *> stack;
    TreeNode *itr = root;

    // Initializing stack with head
    stack.pb(itr);

    while (!stack.empty()) {
      // If left exists then move to left and add it to stack
      if (itr->left) {
        stack.pb(itr->left);
        itr = itr->left;
      } else {
        // Pop the last element and print it
        // Here temp variable is taken as we don't want to modify the actual itr
        // variable as this may cause a problem
        TreeNode *temp = stack.back();
        stack.pop_back();
        res.pb(temp->val);

        // Move to right if possible
        if (temp->right) {
          stack.pb(temp->right);
          itr = temp->right;
        }
      }
    }
    return res;
  }
};