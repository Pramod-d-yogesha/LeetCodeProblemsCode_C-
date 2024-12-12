
/****************************************

Approach 1: Reverse the Number

            Reverse the digits of the number.
            Compare the original number with the reversed number.
            If they are the same, the number is a palindrome.

***********************************************/

#include <iostream>
#include<vector>
using namespace std;
bool checkNumberIsPalindrome(int& num)
{
    int dupNumber=num;
    int reverseNumber=0;
    while(dupNumber>0)
    {
        int digit=dupNumber%10;
        reverseNumber=reverseNumber*10+digit;
        dupNumber/=10;
    }
    return num == reverseNumber;
}
int main()
{
   int number;
   cout<<"Enter the number :"<<endl;
   cin>>number;
   if(checkNumberIsPalindrome(number))
   {
       cout<<"Number = "<<number<<" is palindrome"<<endl;
   }
   else
   {
       cout<<"the given Number = "<<number<<"is not a palindrome"<<endl;
   }
    return 0;
}
