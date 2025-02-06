/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
5. Longest Palindromic Substring

Given a string s, return the longest  palindromic substring  in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.

Approach 1: Expand Around Center (O(n²))
---------------------------------------------------------------------
* use the two pointers (left and right)
* frome each character check the both case odd and even
* odd case : left and right point to the ith character
* even case left point to ith point and right point next to ith place

compare both move if both are equal else stop there and taake the sub string       (left,right)
compare the length of substring of both case(odd and even) with result string and store the max length string  (string[left==string[right])
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

class Solution {
public:
    string longestPalindrome(string s) {
        if( s.empty() || s.length() == 1) return s;
        string LPS="";
        string odd="";
        string even="";
        auto compareChar=[s](int left,int right)
        {
                while(left>=0 && right<s.length() && s[left] == s[right])
                {
                    left--;
                    right++;
                }
                return s.substr(left+1,right-left-1);
        };
        for(int i=0;i<s.length();i++)
        {
                
                even=compareChar(i,i+1);
                if(odd.length()>LPS.length()) LPS=odd;
                odd=compareChar(i,i);
                if(even.length()>LPS.length()) LPS=even;
        }
       return LPS; 
    }
};
