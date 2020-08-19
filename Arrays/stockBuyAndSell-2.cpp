/*
 * Author: Ashwin Goel
 */

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int Profit = 0;
    for (int i = 1; i < n; i++)
    {
      if (prices[i] > prices[i - 1])
      {
        Profit += prices[i] - prices[i - 1];
      }
    }
    return Profit;
  }
};