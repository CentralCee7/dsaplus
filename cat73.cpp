// QUESTION 7.3: Find the minimum consecutive sum in {-2, -4, -1, -6}.
#include <iostream>
#include <algorithm>
using namespace std;

struct Ans { int sum, prefix, suffix, best; };

Ans solveMinSub(int A[], int l, int r) {
    if (l == r) return {A[l], A[l], A[l], A[l]};
    
    int m = (l + r) / 2;
    Ans L = solveMinSub(A, l, m), R = solveMinSub(A, m + 1, r);
    Ans out;
    
    // CHANGE FROM BASE: Naturally chooses the entire all-negative array.
    out.sum = L.sum + R.sum;
    out.prefix = min(L.prefix, L.sum + R.prefix);
    out.suffix = min(R.suffix, R.sum + L.suffix);
    out.best = min(min(L.best, R.best), L.suffix + R.prefix);
    
    return out;
}

int main() {
    int arr[] = {-2, -4, -1, -6};
    cout << solveMinSub(arr, 0, 3).best << endl; 
    return 0;
}