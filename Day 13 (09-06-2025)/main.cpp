#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (but not 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse only the second half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // If number is even-length, x == reversedHalf
        // If odd-length, the middle digit doesn't matter, so we do reversedHalf / 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int main() {
    Solution sol;
    
    // Example test cases
    cout << boolalpha; // to print true/false instead of 1/0
    cout << "Is 121 a palindrome? " << sol.isPalindrome(121) << endl;   // true
    cout << "Is -121 a palindrome? " << sol.isPalindrome(-121) << endl; // false
    cout << "Is 10 a palindrome? " << sol.isPalindrome(10) << endl;     // false
    cout << "Is 1221 a palindrome? " << sol.isPalindrome(1221) << endl; // true

    return 0;
}
