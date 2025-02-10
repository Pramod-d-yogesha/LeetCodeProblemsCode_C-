/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
16. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Approach (Sorting + Two Pointers - O(n²))
-------------------------------------------------------------
* Sort the array to use the two-pointer technique efficiently.
* Fix one element and use two pointers to find the remaining two elements.
* Update the closest sum whenever we find a sum that is nearer to the target.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
  #include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closestSum = INT_MAX, minDiff = INT_MAX;

    for (int i = 0; i < nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(target - sum);

            if (diff < minDiff) {  // Update closest sum
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target) left++;     // Increase sum
            else if (sum > target) right--; // Decrease sum
            else return sum;  // Exact match found
        }
    }
    return closestSum;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << "Closest Sum: " << threeSumClosest(nums, target) << endl;
    return 0;
}
