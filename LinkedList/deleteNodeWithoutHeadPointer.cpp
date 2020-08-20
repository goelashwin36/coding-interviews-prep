
/*
 * Author: Ashwin Goel
 */

/*
 Delete without head pointer

 Practice the problem here:
https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1

The question is simple. We are given a reference to a node in a LL which needs to be deleted.

For eg:

Consider LL = 1->2->3->4
And we need to delete node = 3
Post deletion, the LL will become 1->2->4

We know that we can't access the previous node. But, we can always access the next nodes.

What if we just copy the data of the next node to the current node and delete the next node?

Makes sense?

LL = 1->2->3->4
Delete node=3

1. Copy data of next node to current node

LL = 1->2->4->4

2. Delete next node

1->2->4

And we got the required output.
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{

    if (!node || !node->next)
        node == NULL;
    else
    {
        //Copy data from next node to current node
        node->data = node->next->data;
        //Store next node
        Node *temp = node->next;
        //Connect current node with 2nd next node
        node->next = node->next->next;
        //Dete the next node
        delete temp;
    }
}
