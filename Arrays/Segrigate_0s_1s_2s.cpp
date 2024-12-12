/***************************************
  Approach
  ------------
  left=0;
  current=0
  right=end of the vector

there are three cases to check and do :
case 1 : if current == 0 : swap with left and increment both current and leftby one;
case 2 : if current == 1 : just increment current by one
case 3 : if current == 2 : swap current and right and you have tpo decrement only right and do not increment current(because after swap the 
  right value would be 2 so for that case we have to re check oncecurrent value ) incase of swaping with left no need to check
************************************************************************************************/
#include <iostream>
#include<vector>
using namespace std;
void segrigateElement(vector<int>& nums)
{
    int left=0,current=0,right=nums.size()-1;
    for(int i=0;i<nums.size() && current<right;i++)
    {
        if(nums[current]==0)
        {
            swap(nums[left++],nums[current++]);
        }
        else if(nums[current]==2)
        {
            swap(nums[current],nums[right--]);
        }
        else
        {
            current++;
        }
    }
}
int main()
{
    
    vector<int> nums{2,0,0,1,1,1,1,2,0,2,1,0,1,1,2,2,0,0,0,1};
    cout<<"Size of the vector is = "<<nums.size()<<endl;
    segrigateElement(nums);
    for(int var : nums)
        cout<<var<<" ";
    cout<<"\nSize of the vector is = "<<nums.size()<<endl;
    return 0;
}
