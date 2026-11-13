// QUESTION 2.2: Find the sum of even elements in {-6, 3, 10, 5, 8}.
#include <iostream>
using namespace std;

int evenSum(int A[], int l, int r) {
    // CHANGE FROM BASE: Same recursive function; negative even numbers are also even.
    if (l == r) return (A[l] % 2 == 0) ? A[l] : 0;
    int m = (l + r) / 2;
    return evenSum(A, l, m) + evenSum(A, m + 1, r);
}

int main() {
    int arr[] = {-6, 3, 10, 5, 8};
    cout << evenSum(arr, 0, 4) << endl; 
    return 0;
}