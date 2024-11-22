#include <iostream>
#include<vector>
using namespace std;
void merge(vector<int>&v ,int left,int mid,int right)
{
    vector<int> leftArray(v.begin()+left,v.begin()+mid+1);
    vector<int> RightArray(v.begin()+mid+1,v.begin()+right+1);
    int a1=leftArray.size();
    int a2=RightArray.size();
    int i=0,j=0,k=left;
    while(i<a1 &&j<a2)
    {
        if(leftArray[i]<=RightArray[j])
        {
            v[k++]=leftArray[i++];
            
        }
        else
        {
            v[k++]=RightArray[j++];
        }
    }
    while(i<a1) v[k++]=leftArray[i++];
    while(j<a2) v[k++]=RightArray[j++];
}
void mergeSort(vector<int>& v ,int left,int right)
{
    int mid=0;
    if(left<right)
    {
        mid=(left+right)/2;
        mergeSort(v,left,mid);
        mergeSort(v,mid+1,right);
        merge(v,left,mid,right);
    }
}
int main()
{
    vector<int> nums{9,8,1,2,3,7,6,5,4};
    mergeSort(nums,0,nums.size()-1);
    for(int i : nums)
    {
        cout<<i<<endl;
    }

    return 0;
}
