/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

8 |         |                                             |                 
7 |         |+++++++++++++++++++++++++++++++++++++++++++++|+++++++++++++++ |       
6 |         |         |                                   |                |      
5 |         |         |                 |                 |                |      
4 |         |         |                 |        |        |                |       
3 |         |         |                 |        |        |        |       |       
2 |         |         |        |        |        |        |        |       |       
1 |   |     |         |        |        |        |        |        |       |       
0 +---------------------------------------------------------------------------
      0     1        2        3        4        5        6         7       8

Example 2:
Input: height = [1,1]
Output: 1
 
Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

Approach:
-------------
* Use two pointers, one at the beginning and one at the end of the array.
* Compute the area between these two pointers.

      1. L=min Height of left and right pointers
      2. B=width diff bw left and right pointers (for breadth = right-left )
          2.1. -**Note** use right first becuase right alwas greater than right so it avoid negative value as result Ex: left-right {2-5}=-3
      3. Area=(L * B)
      
* Move the pointer based on which pointer has min length = min(num[left],[num[right]);
* Keep track of the maximum area in any variable

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;
        int left=0,right=height.size()-1;
        while(left<right)
        {
            int area=min(height[left],height[right]) * (right-left);
            result=(result<area)? area : result;
            (height[left]<height[right])? left++ : right--;
        }
        return result;
    }
};


