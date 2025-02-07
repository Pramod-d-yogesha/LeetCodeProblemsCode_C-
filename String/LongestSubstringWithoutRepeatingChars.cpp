/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
3. Longest Substring Without Repeating Characters

Medium

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

            APPROACH
------------------------------------------------
Efficient Approach: Sliding Window + Hash Map (O(n))

* Use Two Pointers (Left & Right):
    - The left pointer keeps track of the start of the valid window.
    - The right pointer expands the window by moving forward one character at a time.

* Use a Hash Map (unordered_map in C++):
    - Store each character along with its last seen index.

* Expand the Window:
    - Move the right pointer and check if the current character is already in the hash map.
    - If it is not repeated, add/update its index in the hash map.

* Handle Repeating Characters:
    - If the character is already present, check its last recorded index.
    - If its index is greater than or equal to left, update left = last index + 1.
    - Otherwise, just update the character’s index without moving left.

* Update the Maximum Length:
    - Keep track of the maximum length using the formula:
      maxLength = max(maxLength, right - left + 1)


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        int left=0;
        int right=0;
        int maxLength=0;
        if(s.empty()) return maxLength;
        if(s.length()==1) return (maxLength+1);
        for(right=0;right<s.length();right++)
        {
            if(umap.find(s[right])!=umap.end())
            {
                left=max(left,umap[s[right]]+1);
                
            }
            umap[s[right]]=right;
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};
