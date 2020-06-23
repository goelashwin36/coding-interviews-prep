/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/binary-tree-postorder-traversal/
Postorder: Left Right Root

1. If the current node exists then add it to stack and move to left
2. If left node is NULL then
2.1 pop the last node from stack and store it in temp variable
2.2 Since the traversal in Left, Right, Root therefore, we simply can't print
the popped value, we first need to iterate it's Right subtree. Therefore, we
maintain a set which basically tells which node needs to be simply printed and
which node's right tree is to be traversed. 2.3 If a node is present in set it
means that we have not iterated its right tree. Therefore, whenever we pop a
node, we see if it is present in the set or not. 2.3.1 If yes then we push it
again and move to it's right tree 2.3.2 If No then we simply pop it and print
it's value
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
  vector<int> postorderTraversal(TreeNode *root) {
    // Writing iterative solution

    // This vector stores the final answer
    vector<int> res;
    vector<TreeNode *> stack;
    TreeNode *itr = root;

    unordered_set<TreeNode *> st;
    while (itr != NULL || !stack.empty()) {
      // If current node is not NULL then add it to stack, set and move to left
      if (itr != NULL) {
        stack.pb(itr);
        // Inserting in set means that the node's right sub tree hasn't been
        // traversed
        st.insert(itr);
        itr = itr->left;
      } else {
        // Pop the last element
        TreeNode *temp = stack.back();
        stack.pop_back();

        // See if it's right subtree is traversed
        if (st.find(temp) != st.end()) {
          st.erase(st.find(temp));
          stack.pb(temp);
          itr = temp->right;
        }
        // Simply print the node if it's right subtree is traversed
        else {
          res.pb(temp->val);
          itr = NULL;
        }
      }
    }
    return res;
  }
};