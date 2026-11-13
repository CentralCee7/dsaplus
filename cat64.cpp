// QUESTION 6.4: Count qualifying values in {1, 2, 4, 7, 8, 11}.
#include <iostream>
using namespace std;

int countMultiples(int A[], int l, int r) {
    // CHANGE FROM BASE: Same code; every base case safely returns zero here.
    if (l == r) return (A[l] % 3 == 0 || A[l] % 5 == 0) ? 1 : 0;
    int m = (l + r) / 2;
    return countMultiples(A, l, m) + countMultiples(A, m + 1, r);
}

int main() {
    int arr[] = {1, 2, 4, 7, 8, 11};
    cout << countMultiples(arr, 0, 5) << endl; 
    return 0;
}