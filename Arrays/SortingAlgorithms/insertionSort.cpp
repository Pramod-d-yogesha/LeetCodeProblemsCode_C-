//insertion sort

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v{7,6,1,2,4,3,5};
    int minIndex=0;
    
    for(int i=1;i<v.size();i++)
    {
        int key=v[i];
        int j=i-1;
        while(j>=0 &&v[j]>key)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }
    for(int it :v)
    {
        cout<<it<<endl;
    }
    return 0;
}
