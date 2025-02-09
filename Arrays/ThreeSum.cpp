/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

     Three sum
-----------------------

* Optimized Approach (Two Pointers - O(n²))
* Sort the array to make handling duplicates easier.
* Fix one element and use two pointers to find the remaining two elements.
* Skip duplicates to avoid redundant triplets.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates
        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;  // Skip duplicates
                while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                left++; right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    for (auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
    return 0;
}
