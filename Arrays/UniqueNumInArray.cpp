/*************************************************************************************************************
136. Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 
Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

---------------------
      APPROACH
----------------------
XOR operation on all numbers

Key Properties of XOR
1. x ⊕ x = 0: A number XORed with itself is 0.
2. x ⊕ 0 = x: A number XORed with 0 remains unchanged.
3. XOR is commutative and associative:
   - a ⊕ b = b ⊕ a
   - (a ⊕ b) ⊕ c = a ⊕ (b ⊕ c)

These properties allow us to cancel out pairs of the same number regardless of their order.

How XOR Solves the Problem
Let’s take your example: [4, 1, 2, 1, 2].

1. Initialize a variable result = 0.
2. XOR each number in the array with result. After each step:
   result = result ⊕ num
   If the number appears twice, it cancels out, leaving only the single number.

Step-by-Step Walkthrough
Let’s go through the array:

Start with result = 0.

Process the first number 4:
result = 0 ⊕ 4 = 4

Process the second number 1:
result = 4 ⊕ 1 = 5 (since 4 = 100, 1 = 001 in binary, XOR gives 101 = 5)

Process the third number 2:
result = 5 ⊕ 2 = 7 (since 5 = 101, 2 = 010, XOR gives 111 = 7)

Process the fourth number 1:
result = 7 ⊕ 1 = 6 (since 7 = 111, 1 = 001, XOR gives 110 = 6)

Process the fifth number 2:
result = 6 ⊕ 2 = 4 (since 6 = 110, 2 = 010, XOR gives 100 = 4)

Final Result
After processing all numbers, result = 4, which is the single number.

Why It Works
- Pairs cancel out: When you XOR a number with itself, it becomes 0. For example:
  1 ⊕ 1 = 0, 2 ⊕ 2 = 0
- Order doesn’t matter: Because XOR is commutative and associative, the order in which you process numbers doesn’t affect the result.
- Only the unique number remains: Since every duplicate is canceled out, the result is the number that appears only once.


****************************************************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // XOR all elements
        }
        return result; // The remaining number is the single one
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 2, 1};
    vector<int> nums2 = {4, 1, 2, 1, 2};
    vector<int> nums3 = {1};

    cout << "Single number in nums1: " << solution.singleNumber(nums1) << endl; // Output: 1
    cout << "Single number in nums2: " << solution.singleNumber(nums2) << endl; // Output: 4
    cout << "Single number in nums3: " << solution.singleNumber(nums3) << endl; // Output: 1

    return 0;
}
