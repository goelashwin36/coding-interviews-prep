/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/sort-an-array

Before reading this solution, it is recommended to have a basic knowledge of
heaps and the working of standard methods like maxHeapify(), buildMaxHeap()

This solution is a very simple implementation of Heaps.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void maxHeapify(vector<int> &heap, int root, int end) {
    int lchild = 2 * root + 1;
    int rchild = 2 * root + 2;

    int maximum = root;

    if (lchild <= end && heap[lchild] > heap[maximum]) {
      maximum = lchild;
    }

    if (rchild <= end && heap[rchild] > heap[maximum]) {
      maximum = rchild;
    }
    if (maximum != root) {
      swap(heap[root], heap[maximum]);

      maxHeapify(heap, maximum, end);
    }
  }

  void buildMaxHeap(vector<int> &heap, int end) {
    for (int root = end / 2; root >= 0; root--) {
      maxHeapify(heap, root, end);
    }
  }

  vector<int> sortArray(vector<int> &heap) {
    int n = heap.size();
    buildMaxHeap(heap, n - 1);

    for (int i = 0; i < n; i++) {
      maxHeapify(heap, 0, n - i - 1);
      swap(heap[0], heap[n - i - 1]);
    }

    return heap;
  }
};