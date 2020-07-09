/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>
using namespace std;

// Keeping a heap of size K and always returning the minumum element

class KthLargest {
public:
  vector<int> nums;
  int k;
  KthLargest(int k, vector<int> &initial) {
    this->k = k;
    for (auto num : initial) {
      add(num);
    }
  }

  void min_heapify(vector<int> &heap, int pos) {
    int l = 2 * pos + 1;
    int r = 2 * pos + 2;
    int smallest = pos;
    if (l < heap.size() && heap[l] < heap[smallest]) {
      smallest = l;
    }
    if (r < heap.size() && heap[r] < heap[smallest]) {
      smallest = r;
    }
    if (smallest != pos) {
      swap(heap[pos], heap[smallest]);
      min_heapify(heap, smallest);
    }
  }

  void recAdd(int val, int pos) {
    int p = (pos - 1) / 2;
    if (p >= 0 && this->nums[p] > val) {
      swap(this->nums[p], this->nums[pos]);
      recAdd(val, p);
    }
  }

  int add(int val) {
    if (this->nums.size() < this->k) {
      this->nums.push_back(val);
      recAdd(val, this->nums.size() - 1);
    } else if (this->nums[0] < val) {
      nums[0] = val;
      min_heapify(this->nums, 0);
    }
    return this->nums[0];
  }
};