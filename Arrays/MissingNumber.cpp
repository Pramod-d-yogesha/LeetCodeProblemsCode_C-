/*****************************************************************************************************************************************
268. Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.


Example 1:
Input: nums = [3,0,1]
Output: 2

Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2

Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8

Explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
=============================================
                APPROACH
=============================================
Optimal Solution: Using XOR
Key Insight:
Using the XOR operation, you can eliminate pairs of matching numbers, leaving only the missing number. This works because XOR is both commutative and associative, and any number XORed with itself results in 0.

Algorithm:
1. Initialize missing = n (because the missing number is in the range [0,n]).
2. XOR all indices [0,𝑛−1]  and all elements in the array.
3. The result is the missing number because all other pairs will cancel out.
------------------------------------------------------------------------
Alternative approach(Using Sum Formula)
---------------------------------------------------------------------------
Algorithm:
1. Calculate the expected sum using the formula:
   Expected Sum = n × (n + 1) / 2
2. Compute the actual sum of the array.
3. Subtract the actual sum from the expected sum to find the missing number.

*****************************************************************************************************************************************/
  class Solution {
public:
    int missingNumber(vector<int>& nums) {
      
  //Alternative approach(Using Sum Formula)
        int n=nums.size();
        int actualSum=n*(n+1)/2;
        int expected=0;
        for(int i : nums)
            expected+=i;
        return (actualSum-expected);

        
    //     Optimal Solution: Using XOR
    //     int missingNumber=nums.size();
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         missingNumber^=i^nums[i];
    //     }
    //     return missingNumber;
        
    }
};
