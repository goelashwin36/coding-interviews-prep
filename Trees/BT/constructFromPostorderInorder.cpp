/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int postIndex;
    vector<int> inorder;
    vector<int> postorder;


    TreeNode* buildTreeHelper(int inStart, int inEnd){

        if(inEnd < inStart) return NULL;


        TreeNode* node = new TreeNode(postorder[postIndex--]);

        int inIndex = -1;
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == node->val){
                inIndex = i;
                break;
            }
        }

        //Move to right then left
        node->right = buildTreeHelper(inIndex+1, inEnd);
        node->left = buildTreeHelper(inStart, inIndex-1);

        return node;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        postIndex = post.size()-1;
        inorder = in;
        postorder = post;

        return buildTreeHelper(0, inorder.size()-1);

    }
};