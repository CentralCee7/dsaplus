// QUESTION 5.3: Calculate 7^0.
#include <iostream>
using namespace std;

long long power(long long b, int n) {
    // CHANGE FROM BASE: The base case handles 0 gracefully.
    if (n == 0) return 1;
    long long half = power(b, n / 2);
    long long ans = half * half;
    if (n % 2 == 1) ans *= b;
    return ans;
}

int main() {
    cout << power(7, 0) << endl; 
    return 0;
}