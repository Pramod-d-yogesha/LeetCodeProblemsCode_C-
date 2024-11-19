#include <iostream>
#include<vector>
using namespace std;
vector<int>v{4,2,3,1,5,9,8,7,6};
int partition(int l,int h)
{
    int i=l,j=h;
    int pivot=v[i];
    while(i<j)
    {
        do{
            i++;
        }while(v[i]<=pivot);
        do{
            j--;
        }while(v[j]>pivot);
        if(i<j)
        {
            swap(v[i],v[j]);
        }
    }
    swap(v[j],v[l]);
    return j;
}
void quickSort(int l,int h)
{
    if(l<h)
    {
        int pivotIndex=partition(l,h);
        quickSort(l,pivotIndex);
        quickSort(pivotIndex+1,h);
    }
}
int main()
{
    quickSort(0,v.size());
    cout<<"The elements are ="<<endl;
    for(int i : v)
    {
        cout<<i<<endl;
    }
    return 0;
}
