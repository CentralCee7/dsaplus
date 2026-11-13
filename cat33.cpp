// QUESTION 3.3: Find the second maximum in {-8, -2, -15, -4}.
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
    // CHANGE FROM BASE: Do not assume values are positive; sorting still works perfectly.
    int vals[4] = {L.mx, L.second, R.mx, R.second};
    sort(vals, vals + 4, greater<int>());
    return {vals[0], vals[1]};
}

int main() {
    int arr[] = {-8, -2, -15, -4};
    cout << secondMax(arr, 0, 3).second << endl; 
    return 0;
}