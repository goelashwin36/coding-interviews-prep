/*
 * Author: Ashwin Goel
 */

/*
 Stack using two queues

Practice the problem here:
https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

This is a very standard and important problem on Stacks and Queues.
*/

#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

/* The method push to push element into the stack */
void QueueStack ::push(int x)
{
    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack ::pop()
{
    if (q1.empty())
        return -1;

    int num = q1.front();
    q1.pop();
    return num;
}
