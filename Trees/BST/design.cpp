/*
 * Author: Ashwin Goel
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
  TreeNode *searchNode(TreeNode *root, int key) {
    TreeNode *itr = root;

    while (itr != NULL) {
      if (itr->val < key)
        itr = itr->right;
      else if (itr->val > key)
        itr = itr->left;
      else
        return itr;
    }
    return itr;
  }
  TreeNode *insertNode(TreeNode *root, int key) {

    if (root == NULL) {
      return new TreeNode(key);
    }

    if (key > root->val)
      root->right = insertNode(root->right, key);

    else if (key < root->val)
      root->left = insertNode(root->left, key);

    return root;
  }

  // Method to return node with max value in a tree
  TreeNode *findMax(TreeNode *root) {
    TreeNode *itr = root;

    while (itr->right) {
      itr = itr->right;
    }
    return itr;
  }

  // Method to delete a none with val=key in a tree
  TreeNode *deleteNode(TreeNode *root, int key) {

    // Search in right subtree
    if (!root)
      return root;
    else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    }
    // Search in left subtree
    else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    }
    // Node found
    else {
      // Current node(root) is to be deleted

      // No child nodes
      if (!root->left && !root->right) {
        delete root;
        root = NULL;
      }
      // Only left child node exists
      else if (root->left && !root->right) {
        TreeNode *temp = root->left;
        delete root;
        return temp;
      }
      // Only right child node exists
      else if (!root->left && root->right) {
        TreeNode *temp = root->right;
        delete root;
        return temp;
      }
      // Both children exist
      else {
        // Find max val child of left subtree. Replace the value and delete the
        // max val child in the left subtree.
        TreeNode *maxLeft = findMax(root->left);
        // Change the current node's val to maxLeft's val
        root->val = maxLeft->val;

        // Now we need to remove the node maxLeft from the left subtree.
        // Therefore, we again recurse.
        root->left = deleteNode(root->left, maxLeft->val);
      }
    }
    return root;
  }
};

/*
Deletion in BST
----------------

Just like we search a node in a BST recursively, the same way we search the node
to be deleted here.

Consider the BST:

    5
   / \
  1   9
     / \
    8   10
   /
  6
   \
    7

Once the node is found, there are 3 cases:

The node to be deleted has:

1. Zero children

In this case we simply delete the node and make it NULL

For Node = 7

Delete the node

    5
   / \
  1   9
     / \
    8   10

2. One chid(Left or Right):

In this case:

2.1 We store the left/right child of the node to be deleted(whichever exists)
2.2 Delete the current node
2.3 Return the node we stored in step 2.1

For Node = 8

8 has only one child(left = 6)

Following the steps above
1. Store left child = 6
2. Delete the current node
3. Return left child

Thus, 9's left becomes subtree with root = 6


    5
   / \
  1   9
     / \
    6   10
    \
     7

3. Both the children exist

Now this one is little tricky,

In this case:

3.1 We find either the max val in the left subtree or min val in the right
subtree 3.2 Assign max val to the node we need to delete 3.3 Delete the node
found in step 3.1

For node = 9

Following the steps above:
1. Finding max val of left subtree = 8
2. Assigning max val(8) to the node we need to delete(9)

    5
   / \
  1   8*
     / \
    8#  10
   /
  6
   \
    7
3. Delete the node max val. Now this becomes another subproblem.

We need to delete 8(#) from the tree.
Now we need to folow the 2nd case i.e. node has one child and we're done.

It might be difficult to explain here. If you couldn't understand then probably
watch a video on YouTube.
*/
