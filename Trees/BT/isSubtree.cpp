
/*
 * Author: Ashwin Goel
 */

// Subtree of Another Tree

/*
https://leetcode.com/problems/subtree-of-another-tree/
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
  bool findIsSubtreeHelper(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL)
      return true;
    if (root1 == NULL || root2 == NULL)
      return false;

    return root1->val == root2->val &&
           findIsSubtreeHelper(root1->left, root2->left) &&
           findIsSubtreeHelper(root1->right, root2->right);
  }

  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == NULL)
      return false;
    return findIsSubtreeHelper(s, t) || isSubtree(s->left, t) ||
           isSubtree(s->right, t);
  }
};
