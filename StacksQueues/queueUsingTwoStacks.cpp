/*
 * Author: Ashwin Goel
 */

/*
 Queue using two Stacks

Practice the problem here:
https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

This is a very standard and important problem on Stacks and Queues.

For this question, we will use 2 stacks(s1 and s2) to implement a queue.

s1 will be our main stack from where we will simply pop items and return
s2 will be our intermediate stack that helps us.

Algorithm
1. Every element is pushed in the stack s2.
2. Every element is popped from the stack s1 if it is not empty.
3. If there are no elements in s1, then we pop all items in s2 and push it to s1. (Why we did this?)
After this we just pop last element from s1 and return.

Try to visualize this algorithm on your own.

We do the third step because, in the process of poppint all elements from s2 and pushing to s1, then s1 essentially becomes reverse of s2.
(Isn't this what we needed? Doesn't s1 store the elements exactly how a queue might have stored?)
*/

#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    int pop();
};

/* The method push to push element into the queue */
void StackQueue ::push(int x)
{
    s2.push(x);
}

/*The method pop which return the element poped out of the queue*/
int StackQueue ::pop()
{
    if (s1.empty())
    { //If both s1 and s2 are empty => Underflow
        if (s2.empty())
            return -1;

        //Pop all elements from s2 and push to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    //Simply pop an item from s1 and return
    int num = s1.top();
    s1.pop();
    return num;
}
