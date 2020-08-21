/*
 * Author: Ashwin Goel
 */

/*
 Maximum Path Sum between 2 Leaf Nodes

Practice the problem here:
https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

1. At every node, we calculate the max leaf to node sum of left and right subtree
2. If both left and right subtree exist which means there is a leaf to leaf path possible
Therefore, we just find leafToLeafSum = maxLeftSubtreeSum + maxRightSubtreeSum + root->data(current root data)
The leafToLeafSum is compared with the max sum found so far(maxx)
And we return max of (maxLeftSubtreeSum,maxRightSubtreeSum) + root->data.  Why???
3. If only left subtree exist then we simply return (maxLeftSubtreeSum + root->data)
4. If only right subtree exist then we simply return (maxRightSubtreeSum + root->data)


Read this for better understanding
https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int maxPathSumHelper(Node *root, int &maxx)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return root->data;

    //Calculating Leaf to Node sum of left and right subtree
    int leftSum = maxPathSumHelper(root->left, maxx);
    int rightSum = maxPathSumHelper(root->right, maxx);

    //If leaf to leaf path exists
    if (root->left && root->right)
    {
        maxx = max(maxx, leftSum + rightSum + root->data);
        return max(leftSum + root->data, rightSum + root->data);
    }
    else if (root->left)
    {
        return leftSum + root->data;
    }
    else if (root->right)
    {
        return rightSum + root->data;
    }
}

int maxPathSum(Node *root)
{
    int maxx = -999999999;
    maxPathSumHelper(root, maxx);
    return maxx;
}