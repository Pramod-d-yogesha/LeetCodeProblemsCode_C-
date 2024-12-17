#include <iostream>
#include <unordered_map>
#include <string>

int romanToInt(const std::string &s) {
    // Map for Roman numerals and their integer values
    std::unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    int prevValue = 0;

    // Loop through each character in the string from the end
    for (int i = s.size() - 1; i >= 0; i--) {
        int currentValue = romanMap[s[i]];

        // If current value is less than the previous value, subtract it from total
        if (currentValue < prevValue) {
            total -= currentValue;
        }
        // Otherwise, add it to total
        else {
            total += currentValue;
        }

        // Update previous value
        prevValue = currentValue;
    }

    return total;
}

int main() {
    std::string romanNumeral;
    std::cout << "Enter a Roman numeral: ";
    std::cin >> romanNumeral;

    int integerValue = romanToInt(romanNumeral);
    std::cout << "The integer value is: " << integerValue << std::endl;

    return 0;
}
