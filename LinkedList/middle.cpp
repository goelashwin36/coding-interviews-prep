/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/middle-of-the-linked-list/

The basic idea is that there are two pointers `slow`, `fast`

`slow` moves 1 step at a time
`fast` moves 2 steps at a time

Therefore, when `fast` is at the end of the LL, then `slow` will be in the
middle since `fast` moves twice the steps of `slow`

#########
1 2 3 4 5
s
f

1 2 3 4 5
  s f

1 2 3 4 5
    s   f

Return slow pointer since fast has reached the end

#########
1 2 3 4 5 6
s
f

1 2 3 4 5 6
  s f

1 2 3 4 5 6
    s   f

1 2 3 4 5 6 NULL
      s     f

Return slow pointer since fast has reached the end
*/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    // Return head if length of LL is 0 or 1
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};
