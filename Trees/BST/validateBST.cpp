/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/validate-binary-search-tree/

There can be two approaches to this problem:

1. Recall a very beautiful property of BST i.e. its inorder traversal gives a
sorted array. Thus, iterate using inorder methof(Left, Root, Right) and keep
appending node's val to a vector. At the end check if the vector is sorted or
not.


2. The second approach is comparatively complex to understand.

Ideally what you may think is that you will iterate in inorder method and
compare every left and right child's value with it's parent and return
true/false accordingly.

    5
   / \
  1   8
     / \
    6   9

For this tree, the above approach will give correct ans.

But, consider the below tree:

    5*
   / \
  1   8
     / \
    4*  9

This is not a valid BST but the above approach will return True. Why?
If you can't find the reason the consider nodes marked with *.

PS: This question was asked to me in Microsoft and I made the same mistake
without even realizing.

Let's see the correct approach:

For every node, we will consider a minn and a maxx value and every node's val
should be greater than minn and less than maxx.

Now let's see how to find minnn and maxx.


    5
   / \
  1   8
 /   / \
0   6   9

Consider this tree. Initialize minn with least value say -10e15 and maxx with
greatest value say 10e15.

For the root node, it's val can be anything.. Right?

So:
-------------
Node: 5
minn = -10^15
maxx = 10^15

returns True
-------------
Node: 1
minn = -10^15
maxx = 5

At this node, it is understood that it should be less than 5 and greater than
minimum possible.

So we can infer that: when we move left, the minn remains the same and max
becomes min(maxx, root->val) since everytime we move left, we need to limit the
max value.

returns True
-------------
Node: 0
minn = -10^15
maxx = 1

returns True
-------------
Node: 8
minn = 5
maxx = 10^15

When we move right, we know that the value can be be greater than it's parent's
value and less than the maximum possible value.

Therefore, we can infer than when we move right, minn becomes max(minn,
root->val) and maxx remains the same

This happens because everytime we move right, we need to limit the lower bound
equal to parent's value.

returns True

-------------
Node: 6
minn = 5
maxx = 8

-------------
Node: 9
minn = 8
maxx = 10^15


Hope the solution is clear.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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
  bool isValidBST(TreeNode *root, ll minn, ll maxx) {

    if (root == NULL)
      return true;

    ll data = root->val;

    if (data <= minn || data >= maxx)
      return false;

    return isValidBST(root->left, minn, min(maxx, data)) &&
           isValidBST(root->right, max(minn, data), maxx);
  }

  bool isValidBST(TreeNode *root) {
    return isValidBST(root, -9999999999999, 9999999999999);
  }
};