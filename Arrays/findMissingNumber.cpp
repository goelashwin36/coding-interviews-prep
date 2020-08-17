/*
 * Author: Ashwin Goel
 */

 /*
 Missing number in array

 Solve the problem here:
 https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

We shall be using a simple idea to solve the problem.
1. Calculate summ of all numbers from 1 to N = totalSum
2. Now calculate the sum of the given array = arrSum
3. We know that array has a missing number.
So, if we do (totalSum - arrSum) won't we get the missing number?
 */

#include <iostream>
using namespace std;

#define ll long long int

int findMissingNumber(int N, int numArr[]) {
    //Sum of numbers from 1 to N
    ll totalSum = ((ll)N*(ll)(N+1))/2;

    ll arrSum = 0;

    //Sum of numbers from 1 to N with one number missing
    for (int idx = 0; idx < N-1; idx++) {
        arrSum += (ll)numArr[idx];
    }

    //Subtracting both gives us the missing number
    return totalSum-arrSum;
}
int main() {

    //T: Number of test cases
    int T;
    cin>>T;

    while (T--) {
        //N i.e numbers from 1 to N
        int N;
        cin>>N;

        //Taking array input
        int numArr[N-1];
        for (int idx = 0; idx < N-1; idx++) {
            cin>>numArr[idx];
        }

        cout<< findMissingNumber(N, numArr)<<endl;
    }
    return 0;
}