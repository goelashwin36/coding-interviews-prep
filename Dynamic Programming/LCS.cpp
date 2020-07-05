/*
 * Author: Ashwin Goel
 */

// Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence

// TODO: Add explanation

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
      int longestCommonSubsequenceIterative(string text1, string text2) {

          //Using Bottom Up Approach

          int n = text1.length();
          int m = text2.length();

          if(n == 0 || m == 0){
              return 0;
          }

          //Let dp[i][j] be longest increasing subsequence between text1[0:i] and text2[0:j] both i and j inclusive

          vector<vector<int> > dp(n+1, vector<int> (m+1, 0));

          for(int i=1; i<n+1; i++){
              for(int j=1; j<m+1; j++){
                  if(text1[i-1] == text2[j-1]){
                      dp[i][j] = dp[i-1][j-1] + 1;
                  }
                  else{
                      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                  }
              }
          }
      return dp[n][m];
      }

  int helper(vector<vector<int>> &dp, int i, int j, string &text1,
             string &text2) {

    if (i >= text1.size() || j >= text2.size()) {
      return 0;
    }

    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    if (text1[i] == text2[j]) {
      dp[i][j] = 1 + helper(dp, i + 1, j + 1, text1, text2);
    } else {
      dp[i][j] = max(helper(dp, i, j + 1, text1, text2),
                     helper(dp, i + 1, j, text1, text2));
    }

    return dp[i][j];
  }

  int longestCommonSubsequence(string text1, string text2) {
    // Top to bottom approach

    int n = text1.size();
    int m = text2.size();

    if (n == 0 || m == 0) {
      return 0;
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));

    helper(dp, 0, 0, text1, text2);
    return dp[0][0];
  }
};