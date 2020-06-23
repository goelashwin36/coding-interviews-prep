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

class Solution {
public:
  int findTilt(TreeNode *root, int &tiltSum) {
    if (root == NULL) {
      return 0;
    }

    // Calculate sum of left and right subtrees
    int leftSum = findTilt(root->left, tiltSum);
    int rightSum = findTilt(root->right, tiltSum);

    // Increment sum by finding tilt value of the node
    tiltSum += abs(leftSum - rightSum);

    // Return the sum of left, right subtree and the node
    return root->val + leftSum + rightSum;
  }
  int findTilt(TreeNode *root) {
    int tiltSum = 0;
    findTilt(root, tiltSum);
    return tiltSum;
  }
};