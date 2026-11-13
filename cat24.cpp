// QUESTION 2.4: Find the sum of even elements in {0, 1, 2, 3, 4, 5, 6}.
#include <iostream>
using namespace std;

int evenSum(int A[], int l, int r) {
    // CHANGE FROM BASE: No algorithm change; zero satisfies 0 % 2 == 0.
    if (l == r) return (A[l] % 2 == 0) ? A[l] : 0;
    int m = (l + r) / 2;
    return evenSum(A, l, m) + evenSum(A, m + 1, r);
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6};
    cout << evenSum(arr, 0, 6) << endl; 
    return 0;
}