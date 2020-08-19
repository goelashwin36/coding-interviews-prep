
/*
 * Author: Ashwin Goel
 */

/*
 Rotate a Linked List

 Practice the problem here:
 https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

Suppose,

LL = 1->2->3->4->5->6->7->8

K = 4

Therefore, final LL = 5->6->7->8->1->2->3->4

Here you can see that since K = 4 therefore, the first 4 nodes are placed at the end.

So, here's what we're going to do.

Use pointer "itr" to iterate

1. Make "itr" point to k-1th node.
2. Use pointer "last" to point to the last node
3.  last->next = head;

head     itr         last
|        |           |
1->2->3->4->5->6->7->8-|
^----------------------|

4.  head = itr->next;

        itr head    last
         |  |        |
1->2->3->4->5->6->7->8-|
^----------------------|

5.  itr->next = NULL;

        itr head    last
         |  |        |
1->2->3->4  5->6->7->8-|
^----------------------|

OR
head
|
5->6->7->8->1->2->3->4


Return head

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

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node *rotate(Node *head, int k)
{
    // Your code here
    Node *itr = head;

    while (itr->next && k != 1)
    {
        itr = itr->next;
        k--;
    }

    //If itr is not the last node
    if (itr->next)
    {
        Node *last = itr;
        //Make "last" point to the last node
        while (last->next)
            last = last->next;

        last->next = head;
        head = itr->next;
        itr->next = NULL;
    }

    return head;
}
