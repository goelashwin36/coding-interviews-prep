/*
 * Author: Ashwin Goel
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

/*

Traversal: Root Right Left

Since we need to find the Right view therefore let's traverse the Right node
first It is understood that at every level, the right node will be traversed
first Therefore, we use a set to store all the levels for which we've found the
Rightmost node;

*/
class Solution {
public:
  void rightSideView(TreeNode *root, int level, unordered_set<int> &st,
                     vector<int> &result) {
    if (root == NULL) {
      return;
    }
    // Following Root, Right, Left

    // If we've not traversed the level before then add the node to the result
    // array and add level to visited set
    if (st.find(level) == st.end()) {
      st.insert(level);
      result.push_back(root->val);
    }

    // Else simply move to right and then left
    rightSideView(root->right, level + 1, st, result);
    rightSideView(root->left, level + 1, st, result);
    return;
  }

  vector<int> rightSideView(TreeNode *root) {
    unordered_set<int> st;
    vector<int> result;
    rightSideView(root, 0, st, result);
    return result;
  }
};