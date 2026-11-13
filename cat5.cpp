// QUESTION: Calculate 2^10.
#include <iostream>

using namespace std;

long long power(long long b, int n) {
    // CHANGE FROM BASE: The base case returns 1 because any number to the power of 0 is 1.
    if (n == 0) return 1;
    
    // CHANGE FROM BASE: We only make ONE recursive call (dividing exponent by 2), 
    // then square the result (half * half) to merge.
    long long half = power(b, n / 2);
    long long ans = half * half;
    
    // CHANGE FROM BASE: If the original exponent was odd, we must multiply by the base one extra time.
    if (n % 2 == 1) ans *= b;
    
    return ans;
}

int main() {
    long long base = 2;
    int exponent = 10;
    
    long long result = power(base, exponent);
    cout << base << "^" << exponent << " = " << result << endl; 
    return 0;
}