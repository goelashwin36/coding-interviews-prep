#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static int __ = []() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == NULL || head->next == NULL || n == 0) {
      return NULL;
    }

    /*
        The basic idea is to use two pointers slow and fast.
        In the starting we'll move fast pointer to make it `n` nodes ahead of
       slow pointer After that we move both slow and fast pointers till fast
       reaches the end
    */
    ListNode *slow = head;
    ListNode *fast = head;

    // Move fast pointer n nodes ahead of slow
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }

    // Move both the pointers till fast reaches the end
    while (fast != NULL && fast->next != NULL) {
      fast = fast->next;
      slow = slow->next;
    }

    // This is the cast when head needs to removed
    if (fast == NULL) {
      head = head->next;
      return head;
    }

    fast = slow->next;
    slow->next = slow->next->next;
    delete (fast);

    return head;
  }
};