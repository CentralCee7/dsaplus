// QUESTION 1.3: Sort in descending order using three sections.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void merge3Desc(int A[], int l, int m1, int m2, int r) {
    vector<int> T(A + l, A + r + 1);
    int i = 0, j = m1 - l + 1, k = m2 - l + 1, out = l;
    int e1 = j, e2 = k, e3 = T.size();
    
    while (i < e1 || j < e2 || k < e3) {
        // CHANGE FROM BASE: Initialize best = INT_MIN, and choose largest value (T[x] > best).
        int best = INT_MIN, from = -1;
        if (i < e1 && T[i] > best) { best = T[i]; from = 1; }
        if (j < e2 && T[j] > best) { best = T[j]; from = 2; }
        if (k < e3 && T[k] > best) { best = T[k]; from = 3; }
        
        A[out++] = best;
        if (from == 1) ++i; else if (from == 2) ++j; else ++k;
    }
}

void mergeSort3Desc(int A[], int l, int r) {
    if (l >= r) return;
    int n = r - l + 1;
    int m1 = l + n / 3 - 1, m2 = l + 2 * n / 3 - 1;
    
    if (m1 < l) m1 = l;
    if (m2 <= m1) m2 = m1 + 1;
    if (m2 >= r) {
        int m = l + (r - l) / 2;
        mergeSort3Desc(A, l, m); mergeSort3Desc(A, m + 1, r); return;
    }
    
    mergeSort3Desc(A, l, m1); mergeSort3Desc(A, m1 + 1, m2); mergeSort3Desc(A, m2 + 1, r);
    merge3Desc(A, l, m1, m2, r);
}

int main() {
    int arr[] = {12, 5, 18, 3, 14, 9};
    mergeSort3Desc(arr, 0, 5);
    for (int x : arr) cout << x << " "; 
    return 0;
}