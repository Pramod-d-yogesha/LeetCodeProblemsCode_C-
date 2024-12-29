/***********************************************************************************************************
287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 
Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

------------------------------
         APPROACH
------------------------------
1. Cycle Detection:
    The slow and fast pointers traverse the "linked list" formed by the indices.
    When they meet, a cycle exists due to the duplicate number.
    
2. Finding the Duplicate:
    Reset one pointer to the start of the list.
    Move both pointers one step at a time until they meet again.
    The meeting point is the duplicate number.
    
********************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find the duplicate
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate Number: " << solution.findDuplicate(nums) << endl;
    return 0;
}
