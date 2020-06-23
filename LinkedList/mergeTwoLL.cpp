/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

    // We can either create a new list or merge either l1 in l2 or l2 in l1

    // Let's create new list l3 and merge two other lists

    // If any of the list is empty then return pointer to the other
    if (l1 == NULL) {
      return l2;
    }

    if (l2 == NULL) {
      return l1;
    }

    // Initializing l3 with a random value
    ListNode *l3 = new ListNode(0);

    // These pointers will be used to iterate in the linked lists
    ListNode *itr1 = l1;
    ListNode *itr2 = l2;
    ListNode *itr3 = l3;

    // While loop rus till both lists are fully iterated i.e. itr1 and itr2 both
    // becomes NULL
    while (itr1 != NULL || itr2 != NULL) {

      // If both lists are not fully iterated
      if (itr1 != NULL && itr2 != NULL) {
        // Select the lesser value since l3 needs to be sorted
        if (itr1->val < itr2->val) {
          ListNode *newNode = new ListNode(itr1->val);
          itr3->next = newNode;
          itr3 = newNode;
          itr1 = itr1->next;
        } else {
          ListNode *newNode = new ListNode(itr2->val);
          itr3->next = newNode;
          itr3 = newNode;
          itr2 = itr2->next;
        }
      }
      // If l1 is fully traversed and l2 is not
      else if (itr1 == NULL && itr2 != NULL) {
        ListNode *newNode = new ListNode(itr2->val);
        itr3->next = newNode;
        itr3 = newNode;
        itr2 = itr2->next;
      }
      // If l2 is fully traversed and l1 is not
      else if (itr1 != NULL && itr2 == NULL) {
        ListNode *newNode = new ListNode(itr1->val);
        itr3->next = newNode;
        itr3 = newNode;
        itr1 = itr1->next;
      }
    }

    // Since we initialized l3 with a random pointer
    l3 = l3->next;
    return l3;
  }
};