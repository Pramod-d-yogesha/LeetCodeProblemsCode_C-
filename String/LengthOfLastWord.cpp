/*********************
Length of Last Word(Topic : string)
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
consisting of non-space characters only.
Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 
Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

******************************
    APPROACH:
  ----------------
extrach word by word using stringsteam cocept (by default delimiter is seperated space so no need to specify delimiter explicitly )
 once reach end of the word then return the length of the word using length() function

*********************************/

#include<string>
#include <iostream>
#include<sstream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream stream(s);
        string word;
        while(stream >> word);
        return word.length();
    }
};
int main() {
    Solution s;
    std::string s1 = "Hello World";
    std::string s2 = "   fly me   to   the moon  ";
    std::string s3 = "luffy is still joyboy";

    std::cout << "Input: \"" << s1 << "\"\nOutput: " <<s.lengthOfLastWord(s1) << "\n";
    std::cout << "Input: \"" << s2 << "\"\nOutput: " <<s.lengthOfLastWord(s2) << "\n";
    std::cout << "Input: \"" << s3 << "\"\nOutput: " <<s.lengthOfLastWord(s3) << "\n";

    return 0;
}
