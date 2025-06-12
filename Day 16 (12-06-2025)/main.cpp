#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                total += roman[s[i]];
            }
        }

        return total;
    }
};

int main() {
    Solution sol;

    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";

    cout << "Input: " << s1 << " -> Output: " << sol.romanToInt(s1) << endl;      // 3
    cout << "Input: " << s2 << " -> Output: " << sol.romanToInt(s2) << endl;      // 58
    cout << "Input: " << s3 << " -> Output: " << sol.romanToInt(s3) << endl;      // 1994

    return 0;
}
