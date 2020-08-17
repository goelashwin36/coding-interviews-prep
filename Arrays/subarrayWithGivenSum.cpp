/*
 * Author: Ashwin Goel
 */

/*
Subarray with given sum

Solve the problem here:
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

The basic idea behind the solution is to use a window(or two pointers).
Always store the sum of all the values between the two pointers(start and end).

Now, if the sum is less than S then we obviously need to move forward therefore
    end+=1
    sum+=arr[end]

Similarly, if the sum is greater than S then we need to decrease the window size
therefore, sum-=arr[start] start+=1

Can you identify any problem in the above logic?

So if at some point your start == end and also sum < S then after above
condition start becomes greater than end Therefore, we need to check this
condition


Finally, if sum == S then print the start and end of the window.(Note that
one-based-indexing is used in the question)

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
  ll N, S;
  cin >> N >> S;
  ll arr[N];

  for (ll i = 0; i < N; i++) {
    cin >> arr[i];
  }

  // Using two pointer approach
  ll start = 0, end = 0;
  ll sum = arr[0];

  if (sum == S) {
    cout << "1 1" << endl;
    return;
  }

  while (end < N && start < N) {

    if (sum < S) {
      end += 1;
      if (end < N)
        sum += arr[end];
      else
        break;
    }
    if (sum > S) {
      sum -= arr[start];
      start += 1;
    }
    if (start > end && start < N) {
      end = start;
      sum = arr[start];
    }
    if (sum == S) {
      cout << start + 1 << " " << end + 1 << endl;
      return;
    }
  }
  cout << "-1" << endl;
  return;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

/*
Set based approach

Keep calculating cumulative sum and add it to a set
Now find S-cumSum is either 0 or else present in the set or not
*/