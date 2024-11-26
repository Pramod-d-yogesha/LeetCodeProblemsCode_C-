//find the kth largest element 

#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>> minHeap;
    vector<int> nums{10,40,70,60,90,80,30,20};
    int k=3;
    for(int var:nums)
    {
        minHeap.push(var);
        if(minHeap.size()>k)
            minHeap.pop();
    }
    cout<<"The largest "<<k<<"th element is - "<<minHeap.top()<<endl;
    return 0;
}
