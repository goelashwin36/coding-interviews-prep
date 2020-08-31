/*
 * Author: Ashwin Goel
 */

/*
Equal Sum Partition Problem

Practice the problem here:
https://practice.geeksforgeeks.org/problems/subset-sum-problem/0


This problem is just a variation of 0-1 Knapsack problem.
*/

#include <bits/stdc++.h>
using namespace std;

int dp[110][100010];

bool isPossibleSubsetSum(int &N, int arr[], int idx, int sum)
{
    if (sum == 0)
        return true;
    if (sum < 0 || idx >= N)
        return false;

    //If subproblem already solved
    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    //Two cases take or don't take
    if (arr[idx] <= sum)
    {
        return dp[idx][sum] = isPossibleSubsetSum(N, arr, idx + 1, sum - arr[idx]) || isPossibleSubsetSum(N, arr, idx + 1, sum);
    }
    //Don't take the element
    else
    {
        return dp[idx][sum] = isPossibleSubsetSum(N, arr, idx + 1, sum);
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N; //Number of elements in the set
        cin >> N;

        int sum = 0;

        //Taking input in array
        int arr[N];
        for (int idx = 0; idx < N; idx++)
        {
            cin >> arr[idx];
            sum += arr[idx];
        }

        //If sum is odd then we can't divide the set into two partitions with equal sum. Why?
        if (sum % 2 != 0)
        {
            cout << "NO";
        }
        else
        {
            memset(dp, -1, sizeof(dp));
            bool ans = isPossibleSubsetSum(N, arr, 0, sum / 2);
            if (ans)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }

    return 0;
}