
/*
 * Author: Ashwin Goel
 */

/*
 Remove Loop in linked list

 Practice the problem here:
https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

Before solving this problem, check out the problem: Detect Loop in a LL

This problem is just a small extension to that problem.

1 2
4 3


Continuing from the last problem, when both slow and fast pointers are equal,
we can say that there's a cycle. Now, if you really observe then the distance
between the head to the node where cycle starts and
the new fast pointer to where the cycle start is sam.

i.e consider:

1->2->3->4->5->6-|
   ^--------------

After iterations,

s
f
1->2->3->4->5->6-|
   ^--------------

   s  f
1->2->3->4->5->6-|
   ^--------------

      s     f
1->2->3->4->5->6-|
   ^--------------

   f     s
1->2->3->4->5->6-|
   ^--------------

         f  s
1->2->3->4->5->6-|
   ^--------------

              f
              s
1->2->3->4->5->6-|
   ^--------------

we will get:

               |->slow=fast
1->2->3->4->5->6-|
   ^--------------

The distance b/w head(1) and the cycle starting node(2)  = 1
 is equal to that of b/w fast=slow(6) and the cycle starting node(2)  = 1

 Therefore, we now find the cycle starting node

 1. slow = head
 2. while(slow != fast){slow = slow->next; fast = fast->next};
 3. Now, our slow and fast both point to the starting node.
 4. Move fast pointer to last node of cycle(6)
 while(fast->next != slow) fast = fast->next;

 5. Now simply make fast's next pointer as NULL to break the loop
 fast->next = NULL

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

//TODO: Complete the Code

void removeLoop(Node *head)
{
    if (!head || !head->next)
        return;

    Node *slow = head;
    Node *fast = head;

    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (slow != fast && (fast && fast->next));

    if (fast && fast->next)
    {
        // At this point, fast == slow pointer
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    return;
}