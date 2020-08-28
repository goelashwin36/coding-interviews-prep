/*
 * Author: Ashwin Goel
 */

/*
0 - 1 Knapsack Problem

Practice the problem here:
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0


*/

#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int T, N, W;

//Recursive Method
int findMaxProfitRecursive(int w, int idx, int wt[], int v[])
{
    if (idx >= N)
        return 0;

    if (dp[idx][w] != -1)
        return dp[idx][w];

    if (wt[idx] <= w)
        //Two options: Take or don't take
        return dp[idx][w] = max(findMaxProfitRecursive(w, idx + 1, wt, v), v[idx] + findMaxProfitRecursive(w - wt[idx], idx + 1, wt, v));
    else
        //Don't take
        return dp[idx][w] = findMaxProfitRecursive(w, idx + 1, wt, v);
}

int findMaxProfitIterative(int W, int N, int wt[], int v[])
{
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w - wt[i - 1]] + v[i - 1], dp[i - 1][w]);
            }
        }
    }

    return dp[N][W];
}

int main()
{
    cin >> T;

    while (T--)
    {

        cin >> N >> W;
        int wt[N], v[N];

        for (int idx = 0; idx < N; idx++)
        {
            cin >> v[idx];
        }
        for (int idx = 0; idx < N; idx++)
        {
            cin >> wt[idx];
        }

        memset(dp, -1, sizeof(dp));
        //Calculating Recursive way
        cout << findMaxProfitRecursive(W, 0, wt, v) << endl;

        //Calculating Iterative Way
        cout << findMaxProfitIterative(W, N, wt, v) << endl;
    }
    return 0;
}