/*******************************
Search Insert Position(Topicn : binary search)
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 
Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

*******************************
APPROACH
low<=high(add equal ) and return low if element is not found so low position will be the result there element can be inserted

*/
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low=0,high=nums.size()-1;
        int mid=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if (nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};
int main() {
    Solution s;
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = s.searchInsert(nums, target);
    std::cout << "The index is: " << result << std::endl;

    return 0;
}
