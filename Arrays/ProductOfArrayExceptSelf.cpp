/******************************************************************************************************************************************************************
238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
==============================================================
            Algorithm:
==============================================================
Use prefix and suffix products:
1. compute suffix and prefix for each elements
  *) Prefix Pass:
        Start with prefix = 1.
        For each element, store prefix in the result array, then update prefix by multiplying it with the current element.
        
  *) Suffix Pass:
        Start with suffix = 1.
        Traverse the array in reverse. Multiply each element in the result array with suffix, then update suffix by multiplying it with the current element.
        
2. the product of each index can then be result[i]=prefix[i-1]*suffix[i+1]

Note: have to use two for loop 
  * One for suffix calculation and store(
  * second one for prefix calculation and store

******************************************************************************************************************************************************************/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
       int n=nums.size();
       vector<int> result(n,1);
       int prefix=1;
       for(int i=0;i<n;i++)
       {
            result[i]=prefix;
            prefix*=nums[i];
       } 
       int suffix=1;
       for(int j=n-1;j>=0;j--)
       {
        result[j]*=suffix;
        suffix*=nums[j];
       }
       return result;
    }
};
