/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/design-linked-list/

#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
  node(int d) {
    data = d;
    next = NULL;
  }
};

class MyLinkedList {
public:
  /** Initialize your data structure here. */
  node *head;
  node *tail;
  int size;
  MyLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {

    if (index >= size || index < 0 || size == 0) {
      return -1;
    }

    node *itr = head;

    for (int i = 0; i < index; i++) {
      itr = itr->next;
    }
    return itr->data;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    node *newNode = new node(val);

    // If head is not initialized
    if (head == NULL) {
      head = newNode;
      tail = newNode;
      size = 1;
      return;
    }

    // Adding newNode to head
    newNode->next = head;
    head = newNode;
    size += 1;
    return;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    node *newNode = new node(val);

    // If head is not initialized
    if (head == NULL) {
      head = newNode;
      tail = newNode;
      size = 1;
      return;
    }

    // Adding newNode at tail
    tail->next = newNode;
    tail = newNode;
    size += 1;
    return;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    // If invalid index
    if (index > size) {
      return;
    }
    // Add at the end
    else if (index == size) {
      addAtTail(val);
    }
    // Add at the starting
    else if (index == 0) {
      addAtHead(val);
    }
    // Add somewhere in middle
    else {
      node *newNode = new node(val);

      node *itr = head;

      // Mode itr to one index before the place where new node needs to be
      // inserted
      for (int i = 0; i < index - 1; i++) {
        itr = itr->next;
      }
      newNode->next = itr->next;
      itr->next = newNode;
      size += 1;
    }
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {

    // If Invalid Index
    if (index >= size) {
      return;
    }
    // Deleted from head
    else if (index == 0) {
      // If only one element present
      if (size == 1) {
        head = tail = NULL;
        size = 0;
      } else {
        // Simply move head to next
        head = head->next;
        size -= 1;
      }
    } else {
      node *itr = head;

      // Move itr to one node before the node to be deleted
      for (int i = 0; i < index - 1; i++) {
        itr = itr->next;
      }

      itr->next = itr->next->next;

      if (itr->next == NULL) {
        tail = itr;
      }
      size -= 1;
    }
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
