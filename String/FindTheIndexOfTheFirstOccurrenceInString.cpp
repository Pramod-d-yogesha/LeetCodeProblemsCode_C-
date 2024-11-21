/***********************
Find the Index of the First Occurrence in a String
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 
Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.


********************/
//Easy Solution
/***********************/

#include<string>
#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string& haystack, const string& needle) {

        int result=haystack.find(needle);
        if(result< haystack.length())
            return result;
        else
            return -1;  
                  
    }
};
int main()
{
    Solution s;
    string str="pramod";
    cout<<"The string  'od'  at = "<<s.strStr(str,"od")<<endl;
    cout<<"The string  'oda' at = "<<s.strStr(str,"oda")<<endl;

    return 0;
}

/*********************************************
          Without pre-defined function
***********************************************/

#include <iostream>
#include <string>

int strStr(const std::string& haystack, const std::string& needle) {
    int n = haystack.length();
    int m = needle.length();

    // Edge case: if needle is empty, return 0
    if (m == 0) return 0;

    // Iterate through haystack to find the first occurrence of needle
    for (int i = 0; i <= n - m; ++i) {
        // Check if the substring matches the needle
        if (haystack.substr(i, m) == needle) {
            return i; // Return the index of the first occurrence
        }
    }

    return -1; // If no match is found, return -1
}

int main() {
    std::string haystack = "sadbutsad";
    std::string needle = "sad";

    int result = strStr(haystack, needle);
    std::cout << "The first occurrence is at index: " << result << std::endl;

    return 0;
}
