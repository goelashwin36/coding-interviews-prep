/*
 * Author: Ashwin Goel
 */

// Quick Sort

/*
https://leetcode.com/problems/sort-an-array/

Please refer this article mentioned below before following this solution.
https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/tutorial/*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int quickSortHelper(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int partIdx = low + 1;
    int idx;
    for (idx = low + 1; idx <= high; idx++) {
      if (arr[idx] < pivot) {
        swap(arr[partIdx], arr[idx]);
        partIdx++;
      }
    }
    // At the end swap pivot with element at partIdx
    swap(arr[low], arr[partIdx - 1]);
    return partIdx - 1;
  }

  void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
      int sortedIdx = quickSortHelper(arr, low, high);
      quickSort(arr, low, sortedIdx - 1);
      quickSort(arr, sortedIdx + 1, high);
    }
  }

  vector<int> sortArray(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }
};