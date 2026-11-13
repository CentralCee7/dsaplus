
#include <iostream>
#include <vector>
using namespace std;

struct MinMax {
    long long minimum;
    long long maximum;
};

struct UMinMax {
    unsigned long long minimum;
    unsigned long long maximum;
};

// Find minimum and maximum using Divide and Conquer
MinMax findMinMax(vector<long long>& arr, int left, int right) {

    if (left == right) {
        return {arr[left], arr[left]};
    }

    int mid = left + (right - left) / 2;

    MinMax leftResult = findMinMax(arr, left, mid);
    MinMax rightResult = findMinMax(arr, mid + 1, right);

    MinMax result;

    result.minimum = (leftResult.minimum < rightResult.minimum) ? leftResult.minimum : rightResult.minimum;

    result.maximum = (leftResult.maximum > rightResult.maximum) ? leftResult.maximum : rightResult.maximum;

    return result;
}

// Calculate absolute value
unsigned long long absoluteValue(long long n) {

    if (n >= 0) {
        return (unsigned long long)n;
    }

    return (unsigned long long)(-(n + 1)) + 1ULL;
}

// Calculate absolute difference
unsigned long long absoluteDifference(long long a, long long b) {

    if (a >= b) {
        return (unsigned long long)a - (unsigned long long)b;
    }

    return (unsigned long long)b - (unsigned long long)a;
}

// Find minimum and maximum absolute values
UMinMax findAbsoluteMinMax(vector<unsigned long long>& arr,
                           int left, int right) {

    if (left == right) {
        return {arr[left], arr[left]};
    }

    int mid = left + (right - left) / 2;

    UMinMax L = findAbsoluteMinMax(arr, left, mid);
    UMinMax R = findAbsoluteMinMax(arr, mid + 1, right);

    UMinMax result;

    result.minimum = (L.minimum < R.minimum) ? L.minimum : R.minimum;
    result.maximum = (L.maximum > R.maximum) ? L.maximum : R.maximum;

    return result;
}

// Find min and max among even indices
MinMax findEvenIndexMinMax(vector<long long>& arr,
                           int left, int right) {

    if (left == right) {
        long long value = arr[left * 2];
        return {value, value};
    }

    int mid = left + (right - left) / 2;

    MinMax L = findEvenIndexMinMax(arr, left, mid);
    MinMax R = findEvenIndexMinMax(arr, mid + 1, right);

    MinMax result;

    result.minimum = (L.minimum < R.minimum) ? L.minimum : R.minimum;
    result.maximum = (L.maximum > R.maximum) ? L.maximum : R.maximum;

    return result;
}

// Find maximum and minimum pair sums
MinMax findPairSumMinMax(vector<long long>& arr,
                         int left, int right) {

    if (left == right) {

        long long sum = arr[left] + arr[arr.size() - 1 - left];

        return {sum, sum};
    }

    int mid = left + (right - left) / 2;

    MinMax L = findPairSumMinMax(arr, left, mid);
    MinMax R = findPairSumMinMax(arr, mid + 1, right);

    MinMax result;

    result.minimum = (L.minimum < R.minimum) ? L.minimum : R.minimum;
    result.maximum = (L.maximum > R.maximum) ? L.maximum : R.maximum;

    return result;
}

// Find maximum and minimum adjacent absolute differences
UMinMax findAdjacentDiffMinMax(vector<long long>& arr,
    int left, int right) {

    if (left == right) {

        unsigned long long diff =
            absoluteDifference(arr[left], arr[left + 1]);

        return {diff, diff};
    }

    int mid = left + (right - left) / 2;

    UMinMax L = findAdjacentDiffMinMax(arr, left, mid);
    UMinMax R = findAdjacentDiffMinMax(arr, mid + 1, right);

    UMinMax result;

    result.minimum = (L.minimum < R.minimum) ? L.minimum : R.minimum;
    result.maximum = (L.maximum > R.maximum) ? L.maximum : R.maximum;

    return result;
}

void printArray(vector<long long>& arr) {

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {

    int choice;

    while (true) {

        cout << "\n===== MAX-MIN PRACTICE PROBLEMS =====" << endl;

        cout << "1. Difference between largest and smallest" << endl;
        cout << "2. Max and Min within a specific range" << endl;
        cout << "3. Largest and smallest absolute values" << endl;
        cout << "4. Max and Min at even indices" << endl;
        cout << "5. Maximum and minimum pair sums" << endl;
        cout << "6. Max and Min adjacent absolute differences" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "Invalid choice!" << endl;
            continue;
        }

        int n;

        cout << "Enter array size: ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid array size!" << endl;
            continue;
        }

        vector<long long> arr(n);

        cout << "Enter array elements: ";

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Find the difference between the largest and smallest elements using divide and conquer.
        if (choice == 1) {

            MinMax result = findMinMax(arr, 0, n - 1);

            unsigned long long difference =
                absoluteDifference(result.maximum, result.minimum);

            cout << "Difference = " << difference << endl;
        }

        // Given an array, find maximum and minimum values only between indices p and q, 
        // inclusive using divide and conquer. Take the value of p and q from user. 
        else if (choice == 2) {

            int p, q;

            cout << "Enter starting index p: ";
            cin >> p;

            cout << "Enter ending index q: ";
            cin >> q;

            if (p < 0 || q >= n || p > q) {
                cout << "Invalid range!" << endl;
            }
            else {

                MinMax result = findMinMax(arr, p, q);

                cout << "Max: " << result.maximum << endl;
                cout << "Min: " << result.minimum << endl;
            }
        }

        // Find the largest and smallest absolute values in an array 
        //containing both positive and negative integers using divide and conquer.

        else if (choice == 3) {

            vector<unsigned long long> absoluteArr(n);

            for (int i = 0; i < n; i++) {
                absoluteArr[i] = absoluteValue(arr[i]);
            }

            UMinMax result =
                findAbsoluteMinMax(absoluteArr, 0, n - 1);

            cout << "Max: " << result.maximum << endl;
            cout << "Min: " << result.minimum << endl;
        }

        // Find the maximum and minimum among elements stored 
        //at even indices (0th, 2nd, 4th, …) using divide and conquer.
        else if (choice == 4) {
            int count = (n + 1) / 2;
            MinMax result =
                findEvenIndexMinMax(arr, 0, count - 1);
            cout << "Max: " << result.maximum << endl;
            cout << "Min: " << result.minimum << endl;
        }
        // Given an array containing an even number of elements, 
        //pair the first element with the last, the second with the second-last,
        // and so on using divide and conquer.
        else if (choice == 5) {
            if (n % 2 != 0) {
                cout << "Array must contain an even number of elements."
                     << endl;
            }
            else {
                int pairs = n / 2;
                MinMax result =
                    findPairSumMinMax(arr, 0, pairs - 1);
                cout << "Maximum pair sum: "
                     << result.maximum << endl;
                cout << "Minimum pair sum: "
                     << result.minimum << endl;
            }
        }
        // Given an array of integers, find the largest and smallest absolute 
        //differences between consecutive elements, using divide and conquer.
        else if (choice == 6) {
            if (n < 2) {
                cout << "Array must contain at least 2 elements."
                     << endl;
            }
            else {
                UMinMax result =
                    findAdjacentDiffMinMax(arr, 0, n - 2);
                cout << "Max: " << result.maximum << endl;
                cout << "Min: " << result.minimum << endl;
            }
        }
    }
    return 0;
}
