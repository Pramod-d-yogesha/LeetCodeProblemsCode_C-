/************************************************************************
125. Valid Palindrome
A phrase is a palindrome if, 
after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*****************************************************************/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        for (int i = 0; i < s.length();) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);  
                i++; 
            }
            else if (!isalnum(s[i])) {
                s.erase(i,1); 
            }
            else {
                i++;  
            }
        }
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
