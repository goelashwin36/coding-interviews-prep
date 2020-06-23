/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

The solution is fairly simple.

Consider the BST:

    5
   / \
  1   8
     / \
    6   9
     \
      7

For nodes 7, 9 keep iterating from node till the root and where both the paths
merge that node is the LCA. For eg: 7->6->8 9->8 Since both meet at 8 therefore,
8 is the LCA

Or,

We can do it the other way.
Start iterating from the root and search for nodes. The node at which both the
paths diverge becomes the LCA.

For 7, 9 the LCA is 8.
for 1, 9 the LCA is 5

Let's consider 7, 9

Start from the root and keep searching for both the nodes

At node=5 both 7,9 lie on the right

At node=8 we can see that 7 lies on the left and 9 lies on the right and we can
say that both the paths diverge. Therefore, 8 become the LCA.

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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

    while (root != NULL) {
      // If both nodes less than that of parent => move left
      if (root->val > p->val and root->val > q->val)
        root = root->left;
      // If both nodes greater than that of parent => move right
      else if (root->val < p->val and root->val < q->val)
        root = root->right;
      // If paths diverge then return node
      else
        return root;
    }

    return root;
  }
};
