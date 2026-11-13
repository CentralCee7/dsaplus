// QUESTION: Sort the array in descending order.
#include <iostream>
#include <vector>

using namespace std;

void merge(int A[], int l, int m, int r) {
    vector<int> L(A + l, A + m + 1), R(A + m + 1, A + r + 1);
    int i = 0, j = 0, k = l;
    
    while (i < (int)L.size() && j < (int)R.size()) {
        // CHANGE FROM BASE: Only the ordering comparison changes from <= to >= 
        // to choose the larger element first.
        if (L[i] >= R[j]) A[k++] = L[i++]; 
        else A[k++] = R[j++];
    }
    
    while (i < (int)L.size()) A[k++] = L[i++];
    while (j < (int)R.size()) A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(A, l, m); 
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}

int main() {
    int arr[] = {4, 7, 2, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted Array (Descending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}