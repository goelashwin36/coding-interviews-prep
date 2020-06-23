
/*
Traversal: Inorder(root, left, right)

We take a vector `levelTrav` which stores the final level order traversal.

We don't necessarily need to traverse in level order to get a level order
traversal

We traverse in preorder, and every node's val is pushed in the respective level

For example:

    3
   / \
  9  20
    /  \
   15   7


   Node:3
   Level: 0
   levelTrav: [[3]]

   Node:9
   Level: 1
   levelTrav: [[3],[9]]

   Node:20
   Level: 1
   levelTrav: [[3],[9, 20]]

   Node:15
   Level: 2
   levelTrav: [[3],[9, 20], [15]]

   Node:7
   Level: 2
   levelTrav: [[3],[9, 20], [15, 7]]

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
  void levelOrderRecursive(TreeNode *root, int level, vector<vector<int>> &levelTrav) {
    if (root == NULL) {
      return;
    } else {
      // If new level encountered then we add empty vector to the end of the
      // levelTrav
      if (level + 1 > levelTrav.size()) {
        vector<int> temp;
        levelTrav.emplace_back(temp);
      }
      // Push root->val in the respective level
      levelTrav[level].emplace_back(root->val);
    }

    levelOrderRecursive(root->left, level + 1, levelTrav);
    levelOrderRecursive(root->right, level + 1, levelTrav);
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> levelTrav;
    levelOrderRecursive(root, 0, levelTrav);

    return levelTrav;
  }
};