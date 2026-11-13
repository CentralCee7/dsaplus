// QUESTION 5.4: Calculate (-2)^6.
#include <iostream>
using namespace std;

long long power(long long b, int n) {
    if (n == 0) return 1;
    long long half = power(b, n / 2);
    long long ans = half * half;
    // CHANGE FROM BASE: The same function naturally handles a negative base.
    if (n % 2 == 1) ans *= b;
    return ans;
}

int main() {
    cout << power(-2, 6) << endl; 
    return 0;
}