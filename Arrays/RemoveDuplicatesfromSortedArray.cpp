/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.


********************************************
Algorithm:
Use a slow pointer (i) to mark the position of the last unique element in the modified array.
Use a fast pointer (j) to iterate through the array.
Whenever a new unique element is encountered (i.e., nums[j] != nums[i]), increment the slow pointer (i) and update nums[i] with the unique element.
At the end of the loop, the first k = i + 1 elements will contain the unique elements in sorted order.


==================*/
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0; // Edge case: empty array
    
    int i = 0; // Slow pointer for unique elements
    for (int j = 1; j < nums.size(); ++j) { // Fast pointer for iteration
        if (nums[j] != nums[i]) { // Found a new unique element
            nums[++i] = nums[j]; // Update the position with the unique element
        }
    }
    return i + 1; // The number of unique elements
}

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    int k = removeDuplicates(nums); // Remove duplicates and get the count of unique elements
    
    std::cout << "Number of unique elements: " << k << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
