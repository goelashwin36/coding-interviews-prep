/*
 * Author: Ashwin Goel
 */

/*
Stock buy and sell

Practice the problem here:
https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0

The best way to visualize this problem is to plot the prices on a graph.
Here in the graph, we can see increasing and decreasing slopes.

In this question we basically need to print the starting and ending indices of
all the positive slopes.

For eg consider the below graph

         /
    /\  /
   /  \/
  /
 /
 012345678

   Here, the slope increases for the index 0 to 3 then
   goes down for 4 and 5 then again goes up for 6 to 8

   Therefore, our output will be (0 3) (6 8)


 To solve this problem, we take two pointes start and end.
 Initialize both with 0.

 Start iterating in the prices array from index 1

 If: prices[idx] > prices[idx - 1] which means there is a positive slope
 Then make end = idx

 Else(decreasing slope)
 check if start != end which means there has been a positive slope before
 then print (start end)
 and reinitialize: start = end = idx

 Consider the above example

 start = end = 0

 Idx
 1 prices[idx] > prices[idx - 1] => end = 1
 2 prices[idx] > prices[idx - 1] => end = 2
 3 prices[idx] > prices[idx - 1] => end = 3
 4 prices[idx] <= prices[idx - 1] Also, start != end => print (0 3) and start = end = 4
 5 prices[idx] <= prices[idx - 1] Also, start == enn => start = end = 5
 6 prices[idx] <= prices[idx - 1] Also, start == enn => start = end = 6
 7 prices[idx] > prices[idx - 1] => end = 7
 8 prices[idx] > prices[idx - 1] => end = 8

 At the end start != end => print (6 8)

 We use the variable profitExists to keep a tract of whether we've got any profit or not.

*/

#include <iostream>
using namespace std;

void stocksBuyandSell(int N, int prices[])
{
    // We need to consider every strictly increasing slope
    // and print its index of local minima and local maxima

    int start = 0, end = 0;
    bool profitExists = false;

    for (int idx = 1; idx < N; idx++)
    {
        if (prices[idx] > prices[idx - 1])
        {
            end = idx;
        }
        else
        {
            if (start != end)
            {
                cout << "(" << start << " " << end << ") ";
                profitExists = true;
            }
            end = idx;
            start = idx;
        }
    }

    if (start != end)
    {
        cout << "(" << start << " " << end << ") ";
        profitExists = true;
    }

    if (profitExists == false)
        cout << "No Profit";

    return;
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int prices[N];

        for (int idx = 0; idx < N; idx++)
            cin >> prices[idx];

        stocksBuyandSell(N, prices);
        cout << endl;
    }
    return 0;
}