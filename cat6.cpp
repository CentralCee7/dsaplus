// QUESTION: Count qualifying values (multiples of 3 or 5) in {3, 4, 5, 7, 9}.
#include <iostream>

using namespace std;

int countMultiples(int A[], int l, int r) {
    if (l == r) {
        // CHANGE FROM BASE: Base case checks modulo 3 OR 5. 
        // Returns a count of 1 if true, 0 if false.
        return (A[l] % 3 == 0 || A[l] % 5 == 0) ? 1 : 0;
    }
    
    int m = l + (r - l) / 2;
    int left = countMultiples(A, l, m);
    int right = countMultiples(A, m + 1, r);
    
    // CHANGE FROM BASE: Combine step adds the counts.
    return left + right;
}

int main() {
    int arr[] = {3, 4, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int count = countMultiples(arr, 0, n - 1);
    cout << "Count of multiples of 3 or 5: " << count << endl; 
    return 0;
}