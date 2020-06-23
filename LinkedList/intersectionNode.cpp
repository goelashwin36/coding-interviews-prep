/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/intersection-of-two-linked-lists/

LL1 =    4->1-\
               8->4->5
LL2 = 5->0->1-/

Answer: Node with value=8

There can be several methods to solve this question
1. Store node of first LL in a set and while iterating in the second LL check if
node is already present in the set or not. If yes then it is the intersection
point.

>>>>
Set after iterating in LL1: 4,1,8,4,5
Now iterating in LL2. When 8 comes we see then node is already present in set
Therefore, node with val 8 is intersection point

NOTE: We are storing nodes in the set and not the data of the node.

2. We may iterate in both the LL and use 2 sets to add the respective nodes.
Now keep popping from both the stacks.
Since both the LL intersect at the end therefore some elements from top of both
the stack will be same. The last node which is same in both the stacks become
the intersection point.

St1:   4 1 8 4 5
St2: 5 0 1 8 4 5

Keep popping: 5,5 (Nodes are same)
              4,4 (Nodes are same)
              8,8 (Nodes are same)
              1,1 (Nodes are not same)

Therefore, node with val 8 is the intersection point

NOTE: We are storing nodes in the set and not the data of the node.


3. Count lengths of both the LL
Now calculate the difference say 'd'
Move the iterator to the bigger LL ahead by d nodes
Now keep iterating in both the LL until same node is found

Length LL1 = 5, Length LL2 = 6, d = 6-5 = 1

        itr1
         |
LL1 =    4->1-\
               8->4->5
LL2 = 5->0->1-/
      |
     itr2

Moving itr2 d(1) nodes ahead

        itr1
         |
LL1 =    4->1-\
               8->4->5
LL2 = 5->0->1-/
         |
        itr2
Now simply iterate in both the LL and see intersection point
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
  ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {

    /*
    The basic idea is to insert all the nodes of the first LL
    And then while iterating in the second LL check if any node is already
    present in the set. If found then it will be the intersection point
    */

    unordered_set<ListNode *> st;

    // Iterating in first LL
    ListNode *itr = headA;

    while (itr != NULL) {

      // Inserting nodes of first LL in a set
      st.insert(itr);
      itr = itr->next;
    }

    // Iterating in second LL
    itr = headB;

    while (itr != NULL) {

      // Check if node is already present in the set i.e first LL
      if (st.find(itr) != st.end()) {
        return itr;
      }
      itr = itr->next;
    }
    return NULL;
  }
};