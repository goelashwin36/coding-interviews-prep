
/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

Iterate in Right, Root, Left

As mentioned, we need to modify val of every node such that it has a value equal
to sum of the values of nodes that are greater than or equal to current node's
val.

Therefore, the rightmost node is the largest node, followed by it's parent and
the the parent's left child and soo on.

Therefore, at every root, add it's value to the sum and make sum as it's val.

NOTE: Here sum is passed by reference which means that the same sum can be
modified and accessed in every recursion call.
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
  void bstToGst(TreeNode *root, int &sum) {
    if (root == NULL) {
      return;
    }
    // Traversal: Right Root Left
    bstToGst(root->right, sum);

    sum += root->val;
    root->val = sum;

    bstToGst(root->left, sum);
  }
  TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    bstToGst(root, sum);
    return root;
  }
};