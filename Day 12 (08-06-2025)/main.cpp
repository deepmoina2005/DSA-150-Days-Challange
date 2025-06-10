#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long result = 0;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Handle overflow/underflow
            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return static_cast<int>(result * sign);
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << sol.myAtoi("42") << endl;               // Output: 42
    cout << sol.myAtoi("   -042") << endl;          // Output: -42
    cout << sol.myAtoi("1337c0d3") << endl;         // Output: 1337
    cout << sol.myAtoi("0-1") << endl;              // Output: 0
    cout << sol.myAtoi("words and 987") << endl;    // Output: 0
    cout << sol.myAtoi("-91283472332") << endl;     // Output: -2147483648 (INT_MIN)
    cout << sol.myAtoi("91283472332") << endl;      // Output: 2147483647 (INT_MAX)

    return 0;
}
