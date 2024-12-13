/***********************************************************************************************
7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 
Constraints:

-231 <= x <= 231 - 1
************************************************************************************************************/
class Solution {
public:
    int reverse(int x) {
 if (x == INT_MIN) return 0;
        int reverseNumber=0;
        bool flag=x<0;
        if(x > INT_MAX || x < INT_MIN )
        {
            return 0;
        }
        x=abs(x);
        while(x>0)
        {
            int digit=x%10;
             if (reverseNumber > INT_MAX / 10 || (reverseNumber == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return 0;  // Overflow case
            }
            reverseNumber=reverseNumber*10+digit;
            x/=10;
        }

        return flag==true ? -reverseNumber : reverseNumber;
        
    }
};
