#include <iostream>
#include <algorithm> // Required for max()

using namespace std;

int findmax(int a[], int n) {
    if (n == 1) return a[0];
    int restMax = findmax(a, n - 1);
    return max(a[n - 1], restMax); 
}

int main() {
    int a[] = {7, 2, 9, 4};
    cout << findmax(a, 4) << endl;
    return 0;
}