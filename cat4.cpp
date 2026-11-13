// QUESTION: Find the second minimum in {7, 2, 9, 4, 3, 8, 6, 1}.
#include <iostream>
#include <algorithm>

using namespace std;

struct PairMin { int mn, second; };

PairMin secondMin(int A[], int l, int r) {
    if (r - l + 1 == 2) {
        // CHANGE FROM BASE: Reversed the comparison in the size-2 base case to prioritize minimums.
        if (A[l] < A[r]) return {A[l], A[r]};
        return {A[r], A[l]};
    }
    
    int m = l + (r - l) / 2;
    PairMin L = secondMin(A, l, m);
    PairMin R = secondMin(A, m + 1, r);
    
    // CHANGE FROM BASE: Sort candidates ascending (default sort) so the smallest are at index 0 and 1.
    int vals[4] = {L.mn, L.second, R.mn, R.second};
    sort(vals, vals + 4);
    
    return {vals[0], vals[1]};
}

int main() {
    int arr[] = {7, 2, 9, 4, 3, 8, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    PairMin result = secondMin(arr, 0, n - 1);
    cout << "Second Minimum: " << result.second << endl; 
    return 0;
}