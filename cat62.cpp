// QUESTION 6.2: Count qualifying values in {10, 11, 12, 13, 15, 20}.
#include <iostream>
using namespace std;

int countMultiples(int A[], int l, int r) {
    // CHANGE FROM BASE: No changes to the recurrence.
    if (l == r) return (A[l] % 3 == 0 || A[l] % 5 == 0) ? 1 : 0;
    int m = (l + r) / 2;
    return countMultiples(A, l, m) + countMultiples(A, m + 1, r);
}

int main() {
    int arr[] = {10, 11, 12, 13, 15, 20};
    cout << countMultiples(arr, 0, 5) << endl; 
    return 0;
}