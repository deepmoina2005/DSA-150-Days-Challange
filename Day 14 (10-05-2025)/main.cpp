#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c*
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // zero occurrence
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // one or more occurrences
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;
    
    // Example test cases
    string s1 = "aa", p1 = "a";
    cout << "isMatch(\"" << s1 << "\", \"" << p1 << "\") = " << (solution.isMatch(s1, p1) ? "true" : "false") << endl;

    string s2 = "aa", p2 = "a*";
    cout << "isMatch(\"" << s2 << "\", \"" << p2 << "\") = " << (solution.isMatch(s2, p2) ? "true" : "false") << endl;

    string s3 = "ab", p3 = ".*";
    cout << "isMatch(\"" << s3 << "\", \"" << p3 << "\") = " << (solution.isMatch(s3, p3) ? "true" : "false") << endl;

    string s4 = "mississippi", p4 = "mis*is*p*.";
    cout << "isMatch(\"" << s4 << "\", \"" << p4 << "\") = " << (solution.isMatch(s4, p4) ? "true" : "false") << endl;

    return 0;
}
