#include <iostream>
using namespace std;
void fibonacciSeries(int n)
{
    int num1=0;
    int num2=1;
    int temp;
    cout<<num1<<" "<<num2<<" ";
    while(num2<=n)
    {
        temp=num1+num2;
        num1=num2;
        num2=temp;
        cout<<num2<<" ";
    }
}
int main()
{
    fibonacciSeries(30);
    return 0;
}
