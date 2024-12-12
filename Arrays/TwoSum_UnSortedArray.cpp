/*************************************************************************
Approach: Using std::unordered_map
  Iterate through the array.
  For each element:
  Calculate its complement (target - arr[i]).
  Check if the complement exists in the hash table (map).
  If it exists, you've found the pair.
  Otherwise, insert the current element into the hash table.

  ************************************************************************/
#include <iostream>
#include <unordered_map>
#include <vector>

std::pair<int, int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap; // To store the number and its index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // Check if the complement is already in the map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // Return indices of the two numbers
        }

        // Add the current number to the map
        numMap[nums[i]] = i;
    }

    return {-1, -1}; // Return invalid indices if no solution is found
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto result = twoSum(nums, target);

    if (result.first != -1) {
        std::cout << "Indices: " << result.first << ", " << result.second << "\n";
        std::cout << "Numbers: " << nums[result.first] << ", " << nums[result.second] << "\n";
    } else {
        std::cout << "No two numbers add up to the target.\n";
    }

    return 0;
}

/************************************************
Complexity:
          Time Complexity: 
          𝑂(𝑛)
          Space Complexity: 
          𝑂(𝑛)

For the input nums = {2, 7, 11, 15} and target = 9:
OUTPUT: 
      Indices: 0, 1
      Numbers: 2, 7
*********************************************************/
  
