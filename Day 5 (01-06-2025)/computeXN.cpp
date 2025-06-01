#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && n % 2 == 0) return 1.0;
    if(x == -1 && n % 2 != 0) return -1.0;

    long binFrom = n;
    if (n < 0){
        x = 1/x;
        binFrom = -binFrom;
    }

    double ans = 1;
    while (binFrom > 0) {
        if (binFrom % 2 == 1) {
            ans *= x;
        }
        x *= x;
        binFrom /= 2;
    }
    return ans;
}

int main() {
    cout << myPow(2.0, 10) << endl;  // Output: 1024
    cout << myPow(2.0, -2) << endl;  // Output: 0.25
    return 0;
}
