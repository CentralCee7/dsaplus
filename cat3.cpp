// QUESTION: Find the second maximum in {7, 2, 9, 4, 3, 8, 6, 1}.
#include <iostream>
#include <algorithm>

using namespace std;

// CHANGE FROM BASE: Recursion now returns a struct containing two variables instead of one.
struct Pair { int mx, second; };

Pair secondMax(int A[], int l, int r) {
    // CHANGE FROM BASE: The base case stops at size 2 (instead of size 1) to form a valid pair.
    if (r - l + 1 == 2) {
        if (A[l] > A[r]) return {A[l], A[r]};
        return {A[r], A[l]};
    }
    
    int m = l + (r - l) / 2;
    Pair L = secondMax(A, l, m);
    Pair R = secondMax(A, m + 1, r);
    
    // CHANGE FROM BASE: The combine step collects 4 candidates, sorts them descending, 
    // and returns the top 2 overall.
    int vals[4] = {L.mx, L.second, R.mx, R.second};
    sort(vals, vals + 4, greater<int>());
    
    return {vals[0], vals[1]};
}

int main() {
    int arr[] = {7, 2, 9, 4, 3, 8, 6, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Pair result = secondMax(arr, 0, n - 1);
    cout << "Second Maximum: " << result.second << endl; 
    return 0;
}