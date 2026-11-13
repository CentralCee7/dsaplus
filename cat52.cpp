// QUESTION 5.2: Calculate 3^5.
#include <iostream>
using namespace std;

long long power(long long b, int n) {
    if (n == 0) return 1;
    long long half = power(b, n / 2);
    long long ans = half * half;
    // CHANGE FROM BASE: When n is odd, multiply the squared half-result by b.
    if (n % 2 == 1) ans *= b;
    return ans;
}

int main() {
    cout << power(3, 5) << endl; 
    return 0;
}