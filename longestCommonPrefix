/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


*/



#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string result = "";
        for (int i = 0; i < strs[0].length(); i++) {
            char currentChar = strs[0][i]; // Current character to check in all strings

            // Check if this character is the same in all other strings
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != currentChar) {
                    return result; // Return the result if a mismatch is found
                }
            }
            result += currentChar; // Append character to result if matched across all strings
        }
        return result;
    }
};
int main()
{
    Solution s;
    //vector<string> v{"flower","flow","flight"};
    vector<string> v{"a"};
    cout<<s.longestCommonPrefix(v)<<endl;
}
