/* 
168. Excel Sheet Column Title
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
 

Constraints:

1 <= columnNumber <= 231 - 1

----------------------------------------------------
Step-by-Step Conversion to Excel Column Name (ABC)
----------------------------------------------------

1. Base-26 Calculation:
   Subtract 1 from the number to align with 0-based indexing 
   (because A=1, B=2, ..., Z=26).

   Example:
   N = 731
   N' = N - 1 = 730

2. Repeated Division by 26:
   Divide N' by 26 to find the "letters" of the column name, 
   starting from the rightmost letter:

   - First Division:
     730 ÷ 26 = 28 remainder 2 (this corresponds to 'C').
   - Second Division:
     28 ÷ 26 = 1 remainder 2 (this corresponds to 'B').
   - Third Division:
     1 ÷ 26 = 0 remainder 1 (this corresponds to 'A').

3. Construct the Column Name:
   The remainders, read from last to first, correspond to the 
   column name: 
   1 = 'A', 2 = 'B', 3 = 'C'.

   Final Result: ABC

----------------------------------------------------
General Algorithm:
----------------------------------------------------

To convert a column number N into a name:
1. Subtract 1 from N to make it 0-based.
2. Repeatedly divide N by 26, recording the remainders.
3. Map the remainders (0-based) to letters (A=1, ..., Z=26).
4. Combine the letters in reverse order of calculation.


*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result="";
        while(columnNumber>0)
        {
            columnNumber--;
            char c='A'+columnNumber%26;
            result=c+result;
            columnNumber/=26;
        }
        return result;
        
    }
};