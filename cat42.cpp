// QUESTION 4.2: Find the second minimum in {12, 5, 18, 3, 14, 9}.
#include <iostream>
#include <algorithm>
using namespace std;

struct PairMin { int mn, second; };

PairMin secondMin(int A[], int l, int r) {
    if (r - l + 1 == 2) {
        if (A[l] < A[r]) return {A[l], A[r]};
        return {A[r], A[l]};
    }
    int m = (l + r) / 2;
    PairMin L = secondMin(A, l, m), R = secondMin(A, m + 1, r);
    // CHANGE FROM BASE: Same code; six-element array.
    int vals[4] = {L.mn, L.second, R.mn, R.second};
    sort(vals, vals + 4);
    return {vals[0], vals[1]};
}

int main() {
    int arr[] = {12, 5, 18, 3, 14, 9};
    cout << secondMin(arr, 0, 5).second << endl; 
    return 0;
}