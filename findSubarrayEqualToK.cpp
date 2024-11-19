//Problem Example Find a subarray whose sum is equal to a given target using the dynamic sliding window technique



#include <iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v{2,5,1,7,10};
    int target=18;
    int left=0,right=0;
    int sum=0;
    for(right=0;right<v.size();++right)
    {
        sum+=v[right];
        while(sum>target && left<=right)
        {
            sum-=v[left];
            ++left;
        }
         if(sum==target) {
            cout<<"array found"<<endl;
            cout<<"The elements are \n[ ";
            for(int i=left;i<=right;i++)
                cout<<v[i]<<" ";
            cout<<"]"<<endl;
            return 0;
        }
    }
    cout<<"Sub array not found"<<endl;
    return 0;
}
