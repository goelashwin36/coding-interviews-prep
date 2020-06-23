/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/
We simply find height of the tree at every node and return it.
The height at any node is found by calculating the heights of the left and the
right subtree and finding max of them + 1(current node)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxDepth(TreeNode *root) {

    // If root does not exist means height will be 0
    if (root == NULL) {
      return 0;
    }

    // Calculate heights of left and right subtree
    int x = maxDepth(root->left);
    int y = maxDepth(root->right);

    // Find which subtree has more height
    if (x > y) {
      // x+1 represents height of left subtree + 1(current node)
      return x + 1;
    } else {
      // x+1 represents height of right subtree + 1(current node)
      return y + 1;
    }
  }
};