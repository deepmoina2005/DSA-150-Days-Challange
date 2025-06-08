#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // If there's only one row or fewer characters than rows, no conversion is needed
        if (numRows == 1 || s.size() <= numRows)
            return s;

        string result = "";
        int jumps = (numRows - 1) * 2;  // Full cycle jump (zig-zag and back)

        // Iterate over each row
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.size(); j += jumps) {
                result += s[j];  // Add character from the current vertical column

                // Add character from the diagonal (only for middle rows)
                int secondIndex = j + jumps - 2 * i;
                if (i > 0 && i < numRows - 1 && secondIndex < s.size()) {
                    result += s[secondIndex];
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string input = "PAYPALISHIRING";
    int rows = 3;

    string output = sol.convert(input, rows);
    cout << "Converted Zigzag: " << output << endl;  // Expected: "PAHNAPLSIIGYIR"

    return 0;
}
