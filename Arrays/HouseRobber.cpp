/*
198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses werebroken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

=================================================================================================================================================================
Algorithm: House Robber Problem

1. Problem Description:
   - Input: An array `nums` representing the money in each house.
   - Constraint: You cannot rob two adjacent houses.
   - Output: The maximum amount of money that can be robbed without triggering alarms.

2. Define the DP State:
   - Let `dp[i]` represent the maximum amount of money that can be robbed from the first `i` houses.

3. State Transition:
   - For each house `i`, there are two choices:
     a) Skip house `i`: Maximum money remains `dp[i - 1]`.
     b) Rob house `i`: Add the money from house `i` to `dp[i - 2]` (as `i-1` cannot be robbed).
   - Formula: `dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])`.

4. Base Cases:
   - If there are no houses (`nums` is empty): Return `0`.
   - If there is only one house: Return `nums[0]`.

5. Implementation:
   a) Initialize `dp[0] = nums[0]`.
   b) Initialize `dp[1] = max(nums[0], nums[1])` (if `nums` has more than 1 element).
   c) Iterate from house `2` to `n-1` and apply the state transition.

6. Optimization:
   - To reduce space complexity to `O(1)`, use two variables to track `dp[i-1]` and `dp[i-2]` instead of an entire array.

7. Final Step:
   - Return `dp[n-1]` or the equivalent value stored in the optimized variables.

8. Complexity Analysis:
   - Time Complexity: `O(n)` because we iterate through the array once.
   - Space Complexity: `O(1)` with space optimization (using two variables).
=================================================================================================================================================================*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = 0; // dp[i - 2]
    int prev1 = nums[0]; // dp[i - 1]
    
    for (int i = 1; i < n; ++i) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1; // The maximum money that can be robbed
    }
};
