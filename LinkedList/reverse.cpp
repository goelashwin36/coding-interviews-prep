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
  // Using recursion
  ListNode *reverseListRecurse(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    // This always points to the last node of the initial list
    ListNode *node = reverseListRecurse(head->next);

    // At every node we reverse it's next pointer
    head->next->next = head;
    // The last element of reversed LL should have next as NULL
    head->next = NULL;
    return node;
  }

  ListNode *reverseList(ListNode *head) {
    // Simply return head if LL is of length 0 or 1
    if (head == NULL || head->next == NULL) {
      return head;
    }

    /*
    mid is used to store the current node whose next pointer will be reversed
    fi stored the previous node where mid will point to after reversing
    th stores the next elements so that we can move ahead

    Intially

    1 <- 2 -> 3 -> 4
         fi  mid   th

    After reversing
    1 <- 2 <- 3 -> 4
         fi  mid   th

    Moving Pointers

    1 <- 2 <- 3 -> 4   NULL
              fi  mid  th
    */

    ListNode *fi = NULL;
    ListNode *mid = head;
    ListNode *th = head;

    while (mid != NULL) {
      th = th->next;
      mid->next = fi;
      fi = mid;
      mid = th;
    }

    return fi;
  }
};