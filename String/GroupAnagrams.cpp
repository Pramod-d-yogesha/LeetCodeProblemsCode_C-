/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.


Approach:
-------------------
* Use an unordered_map where the key is the sorted version of each string.
* Iterate over the input strings:
* Sort the string and use it as a key.
* Store the original string in a vector corresponding to the key.
* Collect all grouped anagrams into the result.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagramGroup;
        vector<vector<string>> result;
        if(strs.empty()) return result;
        for(auto it : strs)
        {
            string tempStr=it;
            sort(tempStr.begin(),tempStr.end());
            anagramGroup[tempStr].push_back(it);
        }
        for(auto&[key,value] : anagramGroup)
        {
            result.push_back(value);
        }
        return result;
    }
};

