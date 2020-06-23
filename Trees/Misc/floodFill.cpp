/*
 * Author: Ashwin Goel
 */

/*
https://leetcode.com/problems/flood-fill/

This question is really simple.

Given
1. 2D matrix representing an image
2. Starting point(sr, sc)
3. newColor

Any pixel is said to be connected to another pixel if it lies either to
immediate top,left,bottom,top of another pixel.

For eg.

1 2 3
4 5 6
7 8 9

5 is connected to 2,3,8,6

Note that here, we need to consider 4-directionally connected points having same
color.

For Eg.

1# 2 3
1# 4* 4*
2  4* 5

Pixels marked with same character are connected.

Now the question is:

We need to start from the starting point, move along all the connected edges and
if it's color = original color then change it to newColor

For eg.

1 1 1
1 1 0
1 0 1

sr, sc = 1,1
newColor = 2

Gives

2 2 2
2 2 0
2 0 1

What we do is:

Do a simple DFS from the starting point and keep converting color of all the
connected pixels(4-directionally connected and having same color as original
color) to newColor.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void dfs(vector<vector<int>> &image, int row, int col, int &newColor,
           int &originalColor) {
    // Condition to check if a cell is connected
    if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() ||
        image[row][col] != originalColor)
      return;

    // Change the color to newColor
    image[row][col] = newColor;

    // Move Down, Up, Right, Left
    dfs(image, row + 1, col, newColor, originalColor);
    dfs(image, row - 1, col, newColor, originalColor);
    dfs(image, row, col + 1, newColor, originalColor);
    dfs(image, row, col - 1, newColor, originalColor);
    return;
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    // originalColor is the color of the given starting point
    int originalColor = image[sr][sc];
    if (originalColor != newColor) {
      dfs(image, sr, sc, newColor, originalColor);
    }
    return image;
  }
};