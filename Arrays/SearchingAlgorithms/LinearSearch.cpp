#include <iostream>
#include<vector>
using namespace std;
void linearSearch(vector<int>& v,int key)
{
    for( int i=0;i<v.size();i++)
    {
        if(v[i] == key)
        {
            cout<<"Key found at = v["<<i<<"]"<<endl;
            return;
        }
    }
    cout<<"The Element is not found"<<endl;
}
int main()
{
    vector<int> v{1,3,5,7,9,10};
    linearSearch(v,10);


    return 0;
}
