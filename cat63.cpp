// QUESTION 6.3: Count qualifying values in {-6, -2, 0, 8, 25}.
#include <iostream>
using namespace std;

int countMultiples(int A[], int l, int r) {
    // CHANGE FROM BASE: Negative multiples and zero also satisfy modulo test.
    if (l == r) return (A[l] % 3 == 0 || A[l] % 5 == 0) ? 1 : 0;
    int m = (l + r) / 2;
    return countMultiples(A, l, m) + countMultiples(A, m + 1, r);
}

int main() {
    int arr[] = {-6, -2, 0, 8, 25};
    cout << countMultiples(arr, 0, 4) << endl; 
    return 0;
}