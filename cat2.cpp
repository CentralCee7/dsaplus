// QUESTION: Find the sum of even elements in {4, 7, 2, 9}.
#include <iostream>

using namespace std;

int evenSum(int A[], int l, int r) {
    // CHANGE FROM BASE: Base case checks modulo 2. 
    // Returns the element itself if it is even, otherwise returns 0.
    if (l == r) return (A[l] % 2 == 0) ? A[l] : 0;
    
    int m = l + (r - l) / 2;
    int left = evenSum(A, l, m);
    int right = evenSum(A, m + 1, r);
    
    // CHANGE FROM BASE: Combine step joins the subproblems using addition (+) instead of comparison.
    return left + right; 
}

int main() {
    int arr[] = {4, 7, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = evenSum(arr, 0, n - 1);
    cout << "Sum of even numbers: " << result << endl; 
    return 0;
}