/********************************************************************************************************************************
242. Valid Anagram
Given two strings s and t, return true if t is an 
anagram  of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
-------------------------------------------------------------------------------------------------------------------------------------
           Approach
======================================
1. Count Characters:
Use a frequency counter (like an array or map) to count how many times each character appears in both strings.
    * string s -  character increase the count in map
    * string t -  character decrease the count in map

2. Edge Cases:
    if all values in map is zero then it will be a anagram else any one character has more than zero than its is not a anagram
-------------------------------------------------------------------------------------------------------------------------------------
Follow-up for Unicode:

If the strings contain Unicode characters, use a hash map (unordered_map in C++ or HashMap in Java) instead of a fixed-size array,
as Unicode has a much larger character set.

********************************************************************************************************************************/
class Solution {
public:
    bool isAnagram(string s, string t) {
      unordered_map<char,int> umap;
        for(int i=0;i<s.length();i++)
        {
            umap[s[i]]++;
        }
        for(int j=0;j<t.length();j++)
        {
            umap[t[j]]--;
        }
        for(auto[key,value] : umap)
        {
            if(value!=0)
            {
                return false;
            }
        }
        return true;  
    }
};
