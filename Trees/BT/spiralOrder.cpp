
/*
 * Author: Ashwin Goel
 */

/*
Zigzag/Spiral Level order traversal


Practice the problem here:
https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
or
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


Check comments for explanation. This can be done both iterative and recursive way.

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

#define mp make_pair
void printSpiral(Node *root)
{

    if (root == NULL)
        return;

    //Declaring in initializing queue
    queue<pair<int, Node *>> q;
    q.push(mp(1, root));

    //This vector stores the final output
    vector<vector<int>> res;

    while (!q.empty())
    {

        //Extract node from queue
        pair<int, Node *> curr = q.front();
        q.pop();

        Node *node = curr.second;
        int height = curr.first;

        //Inserting nodes in queue is they exist
        if (node->left)
            q.push(mp(height + 1, node->left));
        if (node->right)
            q.push(mp(height + 1, node->right));

        //Adding empty vector to res when needed
        if (res.size() < height)
            res.push_back(vector<int>());

        //Inserting in res array
        if (height % 2 == 0)
            res[height - 1].push_back(node->data);
        else
            res[height - 1].insert(res[height - 1].begin(), node->data);
    }

    //Printing in spiral order
    for (int row = 0; row < res.size(); row++)
    {
        for (int col = 0; col < res[row].size(); col++)
        {
            cout << res[row][col] << " ";
        }
    }
}
