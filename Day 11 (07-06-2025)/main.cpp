#include <iostream>
#include <climits>  // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int n = x % 10;      // Extract the last digit
            x = x / 10;          // Remove the last digit

            // Check for overflow/underflow before multiplying and adding
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return 0;
            }

            rev = rev * 10 + n;  // Append the digit
        }
        return rev;
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = sol.reverse(num);
    cout << "Reversed: " << result << endl;

    return 0;
}
