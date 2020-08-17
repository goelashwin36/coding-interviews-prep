/*
 * Author: Ashwin Goel
 */

 /*
 Kadane's Algorithm

 Solve the problem here:
 https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

 Kadane's algorithm is  one of the most popular algorithms and we all
 should be familiar with it.

 This algo is used to find Largest Sum Contiguous Subarray.

 The idea is simple:
 1. Use two variables tempSum and maxSum
 2. While iterating in the array, add the element to tempSum
 3. if it is greater than maxSum then maxSum = tempSum
 4. There might be a case when tempSum becomes zero. We don't want to look for
 such cases because our aim is to maximise the sum.

 For better understanding follow:
 https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll findMaxSumSubarray(int N, ll arr[]) {

    ll num;
    ll tempSum = 0; //To store the running sum
    ll maxSum = -10000005; //To store the max contg. subarray sum

    for (int idx = 0; idx < N; idx++) {
        num = arr[idx];
        tempSum += num;
        maxSum = max(maxSum, tempSum);
        if (tempSum < 0) {
            tempSum = 0;
        }
    }
    return maxSum;
}

int main() {

    // T: Number of test cases
    int T;
    cin >> T;
    while (T--) {
        // N: Number of integers in the array
        int N;
        cin >> N;
        ll arr[N];
        // Taking array input
        for (int idx = 0; idx < N; idx++) {
            cin >> arr[idx];
        }
        cout << findMaxSumSubarray(N, arr) << endl;
    }
    return 0;
}