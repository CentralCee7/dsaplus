// QUESTION 1.4: Sort only the first n elements in ascending order, where n is passed.
#include <iostream>
#include <vector>
using namespace std;

void merge(int A[], int l, int m, int r) {
    vector<int> L(A + l, A + m + 1), R(A + m + 1, A + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j]) A[k++] = L[i++]; 
        else A[k++] = R[j++];
    }
    while (i < (int)L.size()) A[k++] = L[i++];
    while (j < (int)R.size()) A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(A, l, m); mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 4; // limit
    // CHANGE FROM BASE: Make the array range parameterized by calling 0 to n-1
    mergeSort(arr, 0, n - 1); 
    for (int x : arr) cout << x << " "; 
    return 0;
}