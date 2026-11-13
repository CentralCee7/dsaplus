// QUESTION 4.4: Find the second minimum in {21, 17, 30, 25, 11, 28, 19, 23}.
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
    // CHANGE FROM BASE: Same merge candidate list.
    int vals[4] = {L.mn, L.second, R.mn, R.second};
    sort(vals, vals + 4);
    return {vals[0], vals[1]};
}

int main() {
    int arr[] = {21, 17, 30, 25, 11, 28, 19, 23};
    cout << secondMin(arr, 0, 7).second << endl; 
    return 0;
}
