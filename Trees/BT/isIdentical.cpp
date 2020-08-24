/*
 * Author: Ashwin Goel
 */

/*
Determine if Two Trees are Identical

Practice the problem here:
https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
*/

#include <bits/stdc++.h>
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

bool isIdentical(Node *r1, Node *r2)
{
    if (!r1 && !r2)
        return true;
    if (!r1 || !r2)
        return false;
    return r1->data == r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}