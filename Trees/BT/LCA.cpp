/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Basically, at every node we check if the node p or q is present in the left of
the right subtree If at any node, we find one at the left subtree and one at the
right subtree, we return that node But that node should be returned till the
last For that we return either the left subtree or the right one whichever
exists

Also suppose we find that root = q || root = p. Now we don't need to traverse
it's left and the right subtree bcs it's obvious that the ans will be the root
itself
*/
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root)
      return NULL;
    if (root == p || root == q)
      return root;
    TreeNode *leftIsPresent = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightIsPresent = lowestCommonAncestor(root->right, p, q);
    if (leftIsPresent && rightIsPresent)
      return root;
    return leftIsPresent ? leftIsPresent : rightIsPresent;
  }
};