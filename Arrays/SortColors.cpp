/* Sort Colors
Hint
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

//The Basic code for this problem
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int white=0,red=0,blue=0;
        int index=0;
        for(auto val : nums)
        {
            if(val==0) red++;
            if(val==1) white++;
            if(val==2) blue++;
        }
        while(red!=0)
        {
            nums[index]=0;
            red--;
            index++;
        }
        while(white!=0)
        {
            nums[index]=1;
            white--;
            index++;
        }
        while(blue!=0)
        {
            nums[index]=2;
            blue--;
            index++;
        }
        for(int val :nums)
        cout<<val<<",";
        
        
    }
};


//-------------------------------------------------------------------------------------------------------------------------------------------------
//this problem solve with Dutch Natinal flag problem(using two pointers)
//PREFERRED

#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, current = 0, high = nums.size() - 1;

    while (current <= high) {
        if (nums[current] == 0) {
            // Swap current element with the element at low
            swap(nums[current], nums[low]);
            low++;
            current++;
        } else if (nums[current] == 2) {
            // Swap current element with the element at high
            swap(nums[current], nums[high]);
            high--;
        } else {
            // If the element is 1, just move to the next
            current++;
        }
    }
}
int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Explanation of the Code:
Initialization:

low is initialized to 0 (boundary for 0s).
current is initialized to 0 (current index being processed).
high is initialized to nums.size() - 1 (boundary for 2s).
Loop Condition:

The loop continues until current surpasses high.
Handling Each Case:

If nums[current] == 0, swap it with the element at low and increment both low and current.
If nums[current] == 2, swap it with the element at high and decrement high (do not increment current immediately because the swapped element at current needs to be checked).
If nums[current] == 1, simply increment current.
Output:

After processing, the nums array will be sorted in-place with 0s, 1s, and 2s grouped together in order.

*/
