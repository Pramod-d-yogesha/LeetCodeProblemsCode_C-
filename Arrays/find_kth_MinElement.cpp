//find the kth smallest element is 


#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    priority_queue<int> MaxHeap;
    vector<int> nums{10,40,70,60,90,80,30,20};
    int k=3;
    for(int var:nums)
    {
        MaxHeap.push(var);
        if(MaxHeap.size()>k)
            MaxHeap.pop();
    }
    cout<<"The smallest "<<k<<"th element is - "<<MaxHeap.top()<<endl;
    return 0;
}
has context menu
