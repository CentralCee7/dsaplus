#include <vector>
#include <iostream>
using namespace std;

void merge(int A[], int l, int m, int r) {
    // Changed vector names to uppercase L and R to avoid conflict with parameters l and r
    vector<int> L(A + l, A + m + 1);
    vector<int> R(A + m + 1, A + r + 1);
    
    int i = 0, j = 0, k = l; 

    while (i < (int)L.size() && j < (int)R.size()) {
        // Changed to >= to sort in descending order
        if (L[i] >= R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    
    while (i < (int)L.size()) A[k++] = L[i++];
    while (j < (int)R.size()) A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r) {
    if (l >= r) return;
    
    // Added parentheses to fix the mathematical order of operations
    int m = l + (r - l) / 2; 
    
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call mergeSort with 0 as the left index and n-1 as the right index
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array (descending): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
