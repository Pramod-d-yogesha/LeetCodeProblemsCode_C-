/*******************************
Q1. Zigzag Grid Traversal With Skip

You are given an m x n 2D array grid of positive integers.
Your task is to traverse grid in a zigzag pattern while skipping every alternate cell.
Zigzag pattern traversal is defined as following the below actions:

Start at the top-left cell (0, 0).
Move right within a row until the end of the row is reached.
Drop down to the next row, then traverse left until the beginning of the row is reached.
Continue alternating between right and left traversal until every row has been traversed.
Note that you must skip every alternate cell during the traversal.

Return an array of integers result containing, in order, the value of the cells visited during the zigzag traversal with skips.

Example 1:
Input: grid = [[1,2],[3,4]]
Output: [1,4]

Example 2:

Input: grid = [[2,1],[2,1],[2,1]]

Output: [2,1,2]

Example 3:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]]

Output: [1,3,5,7,9]

Constraints:

2 <= n == grid.length <= 50
2 <= m == grid[i].length <= 50
1 <= grid[i][j] <= 2500


----------------------------

Here’s how we can solve the Zigzag Grid Traversal With Skip problem step by step:

Problem Breakdown
=============
Zigzag Traversal:

Start at (0, 0) and move:
Right: Traverse the row from left to right.
Left: Traverse the next row from right to left.
Alternate between these directions for all rows.
Skip Alternate Cells:

While traversing, skip every alternate cell.
Keep track of whether a cell should be skipped using a counter or a boolean flag.

Solution Approach
===================
Traverse the grid row by row.
Depending on the row:
If it's a left-to-right traversal, process the cells in increasing column order.
If it's a right-to-left traversal, process the cells in decreasing column order.
Use a flag or counter to skip every alternate cell.

***************************************/
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
    int m = grid.size(); // Number of rows
    if (m == 0) return result;
    int n = grid[0].size(); // Number of columns

    bool skip = false; // To track alternate skips

    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) {
            // Left-to-right traversal
            for (int j = 0; j < n; ++j) {
                if (!skip) {
                    result.push_back(grid[i][j]);
                }
                skip = !skip;
            }
        } else {
            // Right-to-left traversal
            for (int j = n - 1; j >= 0; --j) {
                if (!skip) {
                    result.push_back(grid[i][j]);
                }
                skip = !skip;
            }
        }
    }

    return result;
    }
};
