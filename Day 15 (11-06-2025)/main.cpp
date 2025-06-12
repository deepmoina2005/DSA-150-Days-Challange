#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"}
        };

        string result;
        for (const auto& pair : roman) {
            int value = pair.first;
            const string& symbol = pair.second;
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Test cases
    int num1 = 3749;
    int num2 = 58;
    int num3 = 1994;

    cout << "Input: " << num1 << " -> Roman: " << solution.intToRoman(num1) << endl;
    cout << "Input: " << num2 << " -> Roman: " << solution.intToRoman(num2) << endl;
    cout << "Input: " << num3 << " -> Roman: " << solution.intToRoman(num3) << endl;

    return 0;
}
