// https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/
/*
Preorder: Root Left Right

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
  vector<int> preorderTraversal(TreeNode *root) {
    // Iterative solution

    // This vector stores the final answer
    vector<int> res;
    vector<TreeNode *> stack;
    TreeNode *itr = root;

    while (itr != NULL || !stack.empty()) {

      // If left exists then add itr to stack move to left
      if (itr != NULL) {
        res.pb(itr->val);
        stack.pb(itr);
        itr = itr->left;
      } else {
        itr = stack.back();
        stack.pop_back();
        itr = itr->right;
      }
    }
    return res;
  }
};