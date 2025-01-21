/*********************************************************************************************************
53. Maximum Subarray

Given an integer array nums, find the 
subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 
Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
-----------------------------------------------
          APPROACH
------------------------------------------------
Kadane's Algorithm (O(n))
Key Insight: Iterate through the array while keeping track of the maximum sum of subarrays ending at the current position. Update the global maximum as you go.

Algorithm:

1. Initialize two variables:
  * current_sum = 0 (to store the sum of the current subarray).
  * max_sum = nums[0] (to store the global maximum sum).
2. Traverse the array:
  * Add the current element to current_sum.
  * If current_sum becomes greater than max_sum, update max_sum.
  * If current_sum becomes negative, reset it to 0 (start a new subarray).
3. Return max_sum.

********************************************************************************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum=0;
        int maxSum=nums[0];
        for(int val:nums)
        {
            currentSum+=val;
            maxSum=(maxSum<currentSum) ? currentSum :maxSum;
            currentSum=(currentSum<0)? 0 :currentSum;
        }
        return maxSum;
    }
};
