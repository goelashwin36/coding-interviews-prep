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

int findMaxProfit(int w, int idx, int wt[], int v[])
{
    if (idx >= N)
        return 0;

    if (dp[idx][w] != -1)
        return dp[idx][w];

    if (wt[idx] <= w)
        //Two options: Take or don't take
        return dp[idx][w] = max(findMaxProfit(w, idx + 1, wt, v), v[idx] + findMaxProfit(w - wt[idx], idx + 1, wt, v));
    else
        //Don't take
        return dp[idx][w] = findMaxProfit(w, idx + 1, wt, v);
}

int main()
{
    cin >> T;

    while (T--)
    {
        memset(dp, -1, sizeof(dp));
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
        cout << findMaxProfit(W, 0, wt, v) << endl;
    }
    return 0;
}