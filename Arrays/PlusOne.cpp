/**********************************
Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

*****************************************
              APPROACH
-----------------------------------------
1. start the loop from end to start
2. check if   ->  2.1 the element is 9 then replacce the value with zero; 
                  2.2 decrement j;
3. if the value is less than 9 then add +1 and return digits vector
4. repeat 2.1 and 2.2 step untill j reach -1;
5. loop came out of the loop mean all element is 9 then add new element with value one(1) at beginning, then return the vector
  *********************************/

#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j=digits.size()-1;
        while(j>=0)
        {
            if(digits[j] == 9)
            {
                digits[j]=0;
                j--;
            }
            else
            {
                digits[j]++;
                return digits;
            }
        }
            digits.emplace(digits.begin(),1);
            return digits;
    }
};

int main() {
    Solution s;
    std::vector<int> digits = {9, 9, 9};
    std::vector<int> result = s.plusOne(digits);
    
    std::cout << "Result: ";
    for (int digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}
