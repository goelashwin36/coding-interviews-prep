
/*
 * Author: Ashwin Goel
 */

// Find GCD of two numbers using Euclidean algorithm

#include <bits/stdc++.h>
using namespace std;

int GCD(int A, int B) {
  if (B == 0)
    return A;

  return GCD(B, A % B);
}

int main() {
  int A = 7;
  int B = 21;

  int gcd = GCD(A, B);
  cout << gcd << endl;

  return 0;
}