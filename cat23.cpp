// QUESTION 2.3: Find the sum of even elements in an array of 1 element.
#include <iostream>
using namespace std;

int evenSum(int A[], int l, int r) {
    // CHANGE FROM BASE: Recursion immediately reaches its single-element base case.
    if (l == r) return (A[l] % 2 == 0) ? A[l] : 0;
    int m = (l + r) / 2;
    return evenSum(A, l, m) + evenSum(A, m + 1, r);
}

int main() {
    int arr[] = {11};
    cout << evenSum(arr, 0, 0) << endl; 
    return 0;
}