#include <iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int>& nums)
   {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size()-i-1;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }
int main() {
	vector<int> v{8,7,6,5,4,3,2,1};
	BubbleSort(v);
	 cout<<"The sorted elements are :"<<endl;
	 for(int i :v)
	     cout<<i<<"  ";
	return 0;
}
