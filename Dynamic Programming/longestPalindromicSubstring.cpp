/*
 * Author: Ashwin Goel
 */

/*
 Longest Palindrome in a String

 Solve the problem here:
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

To solve this problem we shall be using a Dynamic Programming approach.

Use a dp array: dp[start][end] which represents whether the substring of s(start to end) is a palindrome or not.

It is understood that all substrings of length 1 is a palindrome.

For substr of length two, if s[start] == s[end] then dp[start][end] = true.. Makes sense?

For lengths 3 and more, we check if s[start] == s[end]. But is that enough to say it's a palindrome? No. We need to check for the substring of s(start+1, end-1)

For eg. Consider s = aabbaa
start = 1 (a)
end = 4 (a)

Here s[start] == s[end]

But, we need to check the substring of s from start+1 to end-1 i.e. the substring "bb" which is a palindrome. Therefore, dp[start][end] = true;

Now, how do we know if substring from start+1 to end-1 is a palindrome? Haven't we solved this subproblem before? You can check it using dp[start+1][end-1]

Hope you get a roungh idea about the solution.

For better understanding check:
https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/


*/
#include <bits/stdc++.h>
using namespace std;

void findLongestPalnd(string s)
{
    int n = s.size();

    // dp[start][end] represents whether the substring of s from start to end is a palindrome or not.
    bool dp[n][n];
    //Initialize with false
    memset(dp, 0, sizeof(dp));

    //These values helps us track the length and indices of largest palindromic substring
    int maxStart = 0;
    int maxEnd = 0;
    int maxLen = 1;

    //For length one, all substr are palindromes
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }

    for (int len = 2; len <= n; len++)
    {
        for (int start = 0; start <= n - len; start++)
        {
            int end = start + len - 1;

            if (s[start] == s[end])
            {
                //For length 2 or if inner substring is palindrome.
                if (len == 2 || dp[start + 1][end - 1] == true)
                {
                    dp[start][end] = true;

                    if (len > maxLen)
                    {
                        maxStart = start;
                        maxEnd = end;
                        maxLen = len;
                    }
                }
            }
        }
    }
    cout << s.substr(maxStart, maxEnd - maxStart + 1);
}

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        string str;
        cin >> str;
        findLongestPalnd(str);
        cout << endl;
    }

    return 0;
}