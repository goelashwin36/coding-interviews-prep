/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
/*Cloning LL using extra space and in one pass.
  The code can be simplified further by using extra space and taking 2 pass
 */

  Node *copyRandomList(Node *head) {
    if (head == NULL)
      return NULL;

    Node *itr = head;

    //Intializing head of new LL with a random value
    Node *newHead = new Node(0);
    Node *newItr = newHead;

    unordered_map<Node *, Node *> mp;

    while (itr != NULL) {

      if (mp.find(itr) != mp.end()) {
        newItr->next = mp[itr];
      } else {
        Node *newNode = new Node(itr->val);
        mp.insert(make_pair(itr, newNode));
        newItr->next = newNode;
      }

      newItr = newItr->next;

      if (itr->random != NULL) {
        if (mp.find(itr->random) != mp.end()) {
          newItr->random = mp[itr->random];
        } else {
          Node *newRandom = new Node(itr->random->val);
          mp.insert(make_pair(itr->random, newRandom));
          newItr->random = newRandom;
        }
      }

      itr = itr->next;
    }
    newHead = newHead->next;
    return newHead;
  }
};