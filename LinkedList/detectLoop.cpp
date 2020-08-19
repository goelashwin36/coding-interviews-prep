
/*
 * Author: Ashwin Goel
 */

/*
 Detect Loop in linked list

 Practice the problem here:
 https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
 or
 https://leetcode.com/problems/linked-list-cycle/

3 4 5 6 7 8
      7   9
      8 9 10

This question can be solved using two approaches:
1. Using Hashing: Iterate in the LinkedList and keep storing nodes in a Set.
    If we encounter a NULL node => there's no cycle.
    If we encounter a node already present in the set => there's a cycle

2. Using two pointers.

Imagine two racers running on a circular track with different speeds.
Since the speeds are different therefore, they will definitely cross each other later


The same approach we use here. Use two pointers: slow and fast

Slow pointer moves 1 node at a time
Fast pointer moves 2 nodes at a time

Finally, if the LL has any loop, then both the pointers will be equal later while iterating.

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

bool detectLoop(Node *head)
{
    // Checking for boundary conditions
    if (!head || !head->next)
        return false;

    Node *slow = head;
    Node *fast = head;

    //Iterate till either slow and fast becomes equal or a NULL node is found
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (slow != fast && (fast && fast->next));

    //If loop broke because of slow == fast -> there's a loop
    if (fast && fast->next)
    {
        return true;
    }

    return false;
}
