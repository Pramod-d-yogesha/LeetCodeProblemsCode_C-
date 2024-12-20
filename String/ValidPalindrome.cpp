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
    int left = 0, right = s.length() - 1;
        
    while (left < right) {
        
        // Skip left if not alphanumeric
        if (!isalnum(s[left])) {
            left++;
        }
            
        // Skip right if not alphanumeric
        else if (!isalnum(s[right])) {
            right--;
        }
            
        // Convert to lowercase and compare
        else if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
            
        // Move both pointers
        else {
            left++;
            right--;
        }
    }
    return true;
}
};
