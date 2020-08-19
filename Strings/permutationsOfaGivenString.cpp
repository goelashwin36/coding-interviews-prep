/*
 * Author: Ashwin Goel
 */

/*
 Permutations of a given string

 Solve the problem here:
https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

The question can have two variations. One is to just print all the
permutations and another could be to print in lexicographically sorted order.

I couldn't find a better solution to the 2nd part. Right now just sorted all the
permutations found.

The idea of finding all the permutations is to recursively swap different string indices and then print
We take two pointers start and end to swap indices.

Refer this for better understanding
https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

#include <bits/stdc++.h>
using namespace std;

void printAllPerms(vector<string> &res, string str, int start, int end)
{
    if (start == end)
    {
        // cout<<str<<" ";
        res.push_back(str);
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(str[start], str[i]);
            printAllPerms(res, str, start + 1, end);
            swap(str[start], str[i]);
        }
    }
}

int main()
{
    //code
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        vector<string> res;

        cin >> str;
        printAllPerms(res, str, 0, str.size() - 1);
        //Sort the vector(res) having all permutations
        sort(res.begin(), res.end());
        //Print all the permutations
        for (auto s : res)
            cout << s << " ";
        cout << endl;
    }

    return 0;
}