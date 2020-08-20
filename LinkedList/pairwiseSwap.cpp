/*
 * Author: Ashwin Goel
 */

/*
Pairwise swap elements of a linked list

Practice the problem here:
https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1


This is a very simple problem with a very simple code.

We use a variable "itr" initialized to head for iterating in the LL

We follow the following steps:

1. Swap data of itr and itr->next
2. itr = itr->next->next

Continue these steps if both itr and itr->next is not NULL
*/

#include <bits/stdc++.h>
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

Node *pairWiseSwap(struct Node *head)
{

    Node *itr = head;
    while (itr && itr->next)
    {
        swap(itr->data, itr->next->data);
        itr = itr->next->next;
    }
    return head;
}