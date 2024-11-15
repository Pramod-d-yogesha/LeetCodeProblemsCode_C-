#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '{' || c == '[' || c == '(') {  
                st.push(c); 
            } else { 
                // Check if stack is empty before accessing st.top()
                if (st.empty()) return false;
                
                char tmp = st.top();
                if ((c == ')' && tmp == '(') || 
                    (c == '}' && tmp == '{') || 
                    (c == ']' && tmp == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    string test = "{[()]}";
    cout << (s.isValid(test) ? "Valid" : "Invalid") << endl;
}
