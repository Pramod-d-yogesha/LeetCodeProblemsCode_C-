/*********************************************************************************************************************
169. Majority Element

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 
Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 
Follow-up: Could you solve the problem in linear time and in O(1) space?

==========================================================================================================
                          APPROACH
==========================================================================================================

To solve the Majority Element problem efficiently in O(n) time and O(1) space, you can use the Boyer-Moore Voting Algorithm. Here's how it works:

Explanation of Boyer-Moore Voting Algorithm
Key Idea:

Maintain a candidate for the majority element and a count.
Traverse the array:
  If count is 0, update the candidate to the current element.
  If the current element is the same as the candidate, increment count.
  Otherwise, decrement count.

Why It Works:
If there is a majority element, it will survive the counting process because it appears more than half the time (⌊n/2⌋).
Algorithm Steps:

Initialize count = 0 and candidate = None.
Traverse the array:
If count == 0, set candidate = current_element.
If current_element == candidate, increment count.
Else, decrement count.
The candidate at the end is the majority element.

*********************************************************************************************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int count = 0;
        int candidate = 0;

        // First pass to find the candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
