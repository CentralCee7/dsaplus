// QUESTION 4.3: Find the second minimum in {-8, -2, -15, -4}.
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
    // CHANGE FROM BASE: Negative values need no special treatment.
    int vals[4] = {L.mn, L.second, R.mn, R.second};
    sort(vals, vals + 4);
    return {vals[0], vals[1]};
}

int main() {
    int arr[] = {-8, -2, -15, -4};
    cout << secondMin(arr, 0, 3).second << endl; 
    return 0;
}