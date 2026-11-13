// QUESTION 1.2: Sort by dividing into three sections.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void merge3(int A[], int l, int m1, int m2, int r) {
    vector<int> T(A + l, A + r + 1);
    int i = 0, j = m1 - l + 1, k = m2 - l + 1, out = l;
    int e1 = j, e2 = k, e3 = T.size();
    
    // CHANGE FROM BASE: Combine step chooses smallest current item among three sorted runs.
    while (i < e1 || j < e2 || k < e3) {
        int best = INT_MAX, from = -1;
        if (i < e1 && T[i] < best) { best = T[i]; from = 1; }
        if (j < e2 && T[j] < best) { best = T[j]; from = 2; }
        if (k < e3 && T[k] < best) { best = T[k]; from = 3; }
        
        A[out++] = best;
        if (from == 1) ++i; else if (from == 2) ++j; else ++k;
    }
}

void mergeSort3(int A[], int l, int r) {
    if (l >= r) return;
    int n = r - l + 1;
    // CHANGE FROM BASE: Replace two recursive calls with three ranges.
    int m1 = l + n / 3 - 1, m2 = l + 2 * n / 3 - 1;
    
    if (m1 < l) m1 = l;
    if (m2 <= m1) m2 = m1 + 1;
    if (m2 >= r) {
        int m = l + (r - l) / 2;
        mergeSort3(A, l, m); mergeSort3(A, m + 1, r); return;
    }
    
    mergeSort3(A, l, m1); mergeSort3(A, m1 + 1, m2); mergeSort3(A, m2 + 1, r);
    merge3(A, l, m1, m2, r);
}

int main() {
    int arr[] = {12, 5, 18, 3, 14, 9};
    mergeSort3(arr, 0, 5);
    for (int x : arr) cout << x << " "; 
    return 0;
}