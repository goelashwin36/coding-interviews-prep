/*
 * Author: Ashwin Goel
 */

// Merge Sort

/*
https://leetcode.com/problems/sort-an-array/

Please refer this article mentioned below before following this solution.
https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Using Merge sort

  void merge(vector<int> &arr, int start, int mid, int end) {
    // Merge the two arrays: From start to mid and mid+1 to end

    int mergedArr[end - start + 1];
    int p = start, q = mid + 1;
    int newArrIndex = 0;

    while (p <= mid || q <= end) {
      if (p <= mid && q <= end) {
        if (arr[p] < arr[q]) {
          mergedArr[newArrIndex++] = arr[p++];
        } else if (arr[p] > arr[q]) {
          mergedArr[newArrIndex++] = arr[q++];
        } else {
          mergedArr[newArrIndex++] = arr[p++];
          mergedArr[newArrIndex++] = arr[q++];
        }
      } else if (p <= mid) {
        mergedArr[newArrIndex++] = arr[p++];
      } else if (q <= end) {
        mergedArr[newArrIndex++] = arr[q++];
      }
    }

    for (int index = start; index <= end; index++) {
      arr[index] = mergedArr[index - start];
    }

    return;
  }

  void mergeSort(vector<int> &arr, int start, int end) {

    if (start >= end)
      return;

    int mid = (start + end) / 2;

    // Keep on dividing the array into two halves
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // Now start merging the arrays
    merge(arr, start, mid, end);
  }

  vector<int> sortArray(vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }
};