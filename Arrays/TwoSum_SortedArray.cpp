/******************************************************************************************************************************
  
If the array is sorted, you can solve the Two Sum problem efficiently using the two-pointer technique. This approach works in 𝑂(𝑛)
O(n) time and does not require extra space.
  
Approach: Two Pointers
        Use two pointers: one starting from the beginning (left) and one from the end (right) of the array.
        Check the sum of the numbers at the two pointers:
        If the sum equals the target, return the indices (or the numbers).
        If the sum is less than the target, move the left pointer forward to increase the sum.
        If the sum is greater than the target, move the right pointer backward to decrease the sum.
        Repeat until the two pointers meet.

***********************************************************************************************************************************/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    vector<int> nums{2,5,7,11,13,20};
    int target=20;
    int left=0,right=nums.size()-1;
    while(left<right)
    {
        int sum=nums[left]+nums[right];
        if(sum == target)
        {
            cout<<"{"<<left<<","<<right<<"}"<<endl;
            return 0;
        }
        else if(sum<target)
        {
            left++;
        }
        else
        {
            right--;
        }
        
    }
    cout<<"Pair is not found"<<endl;
    return 0;
}
