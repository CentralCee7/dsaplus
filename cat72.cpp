// QUESTION 7.2: Find the minimum consecutive sum in {4, -7, 2, -3, 5}.
#include <iostream>
#include <algorithm>
using namespace std;

struct Ans { int sum, prefix, suffix, best; };

Ans solveMinSub(int A[], int l, int r) {
    if (l == r) return {A[l], A[l], A[l], A[l]};
    
    int m = (l + r) / 2;
    Ans L = solveMinSub(A, l, m), R = solveMinSub(A, m + 1, r);
    Ans out;
    
    // CHANGE FROM BASE: Same four-field combine rule.
    out.sum = L.sum + R.sum;
    out.prefix = min(L.prefix, L.sum + R.prefix);
    out.suffix = min(R.suffix, R.sum + L.suffix);
    out.best = min(min(L.best, R.best), L.suffix + R.prefix);
    
    return out;
}

int main() {
    int arr[] = {4, -7, 2, -3, 5};
    cout << solveMinSub(arr, 0, 4).best << endl; 
    return 0;
}