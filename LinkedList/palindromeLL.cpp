/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/palindrome-linked-list/

This problem can be thought as a combination of two standard problems of LL.
1. Finding middle element of LL
2. Reversing a LL

You might have got a hint now.

First we find the middle element of the LL
The reverse the LL from the middle element
Now we iterate from the starting to middle and middle to end of reversed LL
We can simply check if corresponding values are same or not
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  // Reverse the linkedlist from the middle and check again
  ListNode *reverse(ListNode *head) {

    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode *prev = head;
    ListNode *curr = head->next;
    ListNode *forw = head->next->next;

    while (curr != NULL) {
      curr->next = prev;
      if (prev == head) {
        prev->next = NULL;
      }
      prev = curr;
      curr = forw;
      if (curr == NULL) {
        break;
      }
      forw = forw->next;
    }
    head = prev;
    return prev;
  }

  bool isPalindrome(ListNode *head) {

    if (head == NULL || head->next == NULL) {
      return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      if (fast && fast->next) {
        slow = slow->next;
      }
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    fast = slow;

    ListNode *itr = head;

    if (itr->next == slow) {
      if (itr->val == slow->val) {
        return true;
      } else {
        return false;
      }
    }

    while (itr != slow) {
      if (itr->val != fast->val) {
        return false;
      }
      itr = itr->next;
      fast = fast->next;
    }
    return true;
  }
};