
/*
 * Author: Ashwin Goel
 */

/*
Binary Tree Maximum Path Sum between any nodes

Practice the problem here:
https://leetcode.com/problems/binary-tree-maximum-path-sum/

Check comments for explanation.
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPathSumHelper(TreeNode *root, int &maxx)
{
    //If root is NULL then sum = 0
    if (!root)
        return 0;

    //Calculating max sum of left and right subtree
    int lSum = maxPathSumHelper(root->left, maxx);
    int rSum = maxPathSumHelper(root->right, maxx);

    //At any node, max sum is max of: current root->val, current root->val + maxSumLeftSubtree + maxSumRightSubtree

    //Finding max sum at current node.
    int maxSum = max(root->val, root->val + lSum + rSum);
    maxx = max(maxx, maxSum);

    //NOTE: If the max sum at current node is found to be negative then we return 0. We need not return negative sum since we want to maximise the sum.
    //This idea was taken from Kadane's algorithm
    return max(0, max(root->val, max(root->val + lSum, root->val + rSum)));
}
int maxPathSum(TreeNode *root)
{

    int maxx = -999999;
    maxPathSumHelper(root, maxx);
    return maxx;
}
