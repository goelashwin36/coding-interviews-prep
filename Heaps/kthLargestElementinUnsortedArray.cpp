/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void max_heapify(vector<int> &heap, int pos, int N) {
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;
    int largest = pos;
    if (l < N && heap[l] > heap[largest]) {
      largest = l;
    }
    if (r < N && heap[r] > heap[largest]) {
      largest = r;
    }
    if (largest != pos) {
      swap(heap[pos], heap[largest]);
      max_heapify(heap, largest, N);
    }
  }

  void buildMaxHeap(vector<int> &heap) {
    int N = heap.size();

    for (int i = N / 2 - 1; i >= 0; i--) {
      max_heapify(heap, i, N);
    }
  }

  int findKthLargest(vector<int> &nums, int k) {
    int N = nums.size();
    buildMaxHeap(nums);
    for (int i = 0; i < k; i++) {
      max_heapify(nums, 0, N);
      swap(nums[0], nums[N - 1]);
      N--;
    }

    return nums[N];
  }
};