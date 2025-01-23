/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  APPROACH
=================
1. two pointers concept(left and right)
2. left point to beginning of the string 
3. right pointing ending of the string
4. increment  left pointer untill vowel found
5. decrement right pointer untill vowel fouond
6. swap both
7. increment left and decrement right(or else it will become infinite loop on that point)
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <iostream>
#include<atomic>
#include<vector>
#include<thread>
using namespace std;
bool checkVowel(char ch)
{
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
void reverseOvels(string& str)
{
    int left=0,right=str.length();
    while(left<right)
    {
        while(!checkVowel(tolower(str[left])))
        {
            left++;
        }
        while(!checkVowel(tolower(str[right])))
        {
            right--;
        }
        std::swap(str[left],str[right]);
        left++;
        right--;
    }
    cout<<str;
}
int main()
{
    string str="pramod";
    reverseOvels(str);
    return 0;
}
