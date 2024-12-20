/*********************
Number =3654
target = 6
output = 354
********************/

//CASE -1 : using while loop
#include <iostream>
using namespace std;

int removeDigit(int number, int target) {
    int result = 0, place = 1;
    while (number > 0) {
        int digit = number % 10;
        if (digit != target) {
            result += digit * place;
            place *= 10;
        }
        number /= 10;
    }
    return result;
}

int main() {
    int number = 3654, target = 6;
    cout << "Result: " << removeDigit(number, target) << endl;
    return 0;
}


//CASE 2 : for loop

#include <iostream>
#include<climits>
using namespace std;
int main()
{
    int num;
    int target;
    int result=0;
    int place=1;
    cout<<"Enter the Numebr "<<endl;
    cin>>num;
    cout<<"Enter the target digit you whant to remove"<<endl;
    cin>>target;
    for(;num>0;num/=10)
    {
        int digit=num%10;
        if( digit != target)
        {
            result+=digit * place;
            place*=10;
        }
    }
    cout<<"Number after removing = "<<result<<endl;
    cout<<INT_MAX<<endl;

    return 0;
}
