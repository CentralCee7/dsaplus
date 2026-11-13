// QUESTION 3.4: Find the second maximum in {21, 17, 30, 25, 11, 28, 19, 23}.
#include <iostream>
#include <algorithm>
using namespace std;

struct Pair { int mx, second; };

Pair secondMax(int A[], int l, int r) {
    if (r - l + 1 == 2) {
        if (A[l] > A[r]) return {A[l], A[r]};
        return {A[r], A[l]};
    }
    int m = (l + r) / 2;
    Pair L = secondMax(A, l, m), R = secondMax(A, m + 1, r);
    // CHANGE FROM BASE: Same pair-returning recursion for larger numbers.
    int vals[4] = {L.mx, L.second, R.mx, R.second};
    sort(vals, vals + 4, greater<int>());
    return {vals[0], vals[1]};
}

int main() {
    int arr[] = {21, 17, 30, 25, 11, 28, 19, 23};
    cout << secondMax(arr, 0, 7).second << endl; 
    return 0;
}