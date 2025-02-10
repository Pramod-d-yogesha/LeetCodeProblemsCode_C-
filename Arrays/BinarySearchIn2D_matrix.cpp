/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

+----+----+----+----+
|  1 |  3 |  5 |  7 |
+----+----+----+----+
| 10 | 11 | 16 | 20 |
+----+----+----+----+
| 23 | 30 | 34 | 60 |
+----+----+----+----+

the best approach is = 2. Search in a Row-wise and Column-wise Sorted Matrix
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

1. Search in a Sorted 2D Matrix (Row-wise and Column-wise Sorted)
💡 Idea: Treat the 2D matrix as a flattened 1D array and apply binary search.

  Time Complexity:
Binary search on m * n elements → O(log(m * n)).

=============================================================================================
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];

        if (midValue == target) return true;
        else if (midValue < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    
    cout << (searchMatrix(matrix, target) ? "Found" : "Not Found") << endl; // Output: Found

    return 0;
}
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

2. Search in a Row-wise and Column-wise Sorted Matrix
💡 Idea: Start from the top-right or bottom-left corner.
         Move left if the value is too large, move down if it's too small.

Time Complexity:
At most m + n moves → O(m + n).
=============================================================================================

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    
    int m = matrix.size(), n = matrix[0].size();
    int row = 0, col = n - 1;

    while (row < m && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;  // Move down
        else col--;  // Move left
    }
    return false;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 5;
    cout << (searchMatrix(matrix, target) ? "Found" : "Not Found") << endl; // Output: Found
    return 0;
}

  
