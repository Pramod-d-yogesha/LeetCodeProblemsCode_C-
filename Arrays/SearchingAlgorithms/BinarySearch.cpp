#include <iostream>
#include<vector>
using namespace std;
void binarySearch(vector<int>& v,int low,int high,int key)
{
    while(low<high)
    {
        int mid=(low+high)/2;
        if(v[mid] == key)
        {
            cout<<"Key found = v["<<mid<<"]"<<endl; 
            return;
        }
        else if(v[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<"Key Not Found"<<endl;
}
int main()
{
    vector<int> v{1,3,5,7,9,10};
    binarySearch(v,0,v.size(),10);
    //cout<<v.size();


    return 0;
}
