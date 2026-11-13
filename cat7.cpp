// QUESTION: Find the minimum consecutive sum in {3, -2, 5, -4, 6, -1, -2, 3, 5, 2}.
#include <iostream>
#include <algorithm>

using namespace std;

// CHANGE FROM BASE: Must track 4 specific properties per chunk to account for borders.
struct Ans { int sum, prefix, suffix, best; };

Ans solveMinSub(int A[], int l, int r) {
    if (l == r) return {A[l], A[l], A[l], A[l]};
    
    int m = l + (r - l) / 2;
    Ans L = solveMinSub(A, l, m);
    Ans R = solveMinSub(A, m + 1, r);
    
    Ans out;
    out.sum = L.sum + R.sum;
    
    // CHANGE FROM BASE: Replaced max() with min() for all structural comparisons 
    // compared to the standard maximum-subarray problem.
    out.prefix = min(L.prefix, L.sum + R.prefix);
    out.suffix = min(R.suffix, R.sum + L.suffix);
    out.best = min(min(L.best, R.best), L.suffix + R.prefix);
    
    return out;
}

int main() {
    int arr[] = {3, -2, 5, -4, 6, -1, -2, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Ans result = solveMinSub(arr, 0, n - 1);
    cout << "Minimum consecutive subarray sum: " << result.best << endl; 
    return 0;
}