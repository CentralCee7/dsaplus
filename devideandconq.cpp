
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ---------------- MERGE SORT ----------------

// Merge two sections
void mergeTwo(vector<long long>& arr, int left, int mid,
              int right, bool descending) {

    vector<long long> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<long long> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < L.size() && j < R.size()) {
        if (descending ? L[i] >= R[j] : L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

// Two-way Merge Sort
void mergeSortTwo(vector<long long>& arr, int left,
                  int right, bool descending) {

    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSortTwo(arr, left, mid, descending);
    mergeSortTwo(arr, mid + 1, right, descending);

    mergeTwo(arr, left, mid, right, descending);
}

// Compare two values for three-way merge sort
bool comesBefore(long long a, long long b, bool descending) {
    return descending ? a > b : a < b;
}

// Merge three sorted sections
void mergeThree(vector<long long>& arr, int left, int mid1,
                int mid2, int right, bool descending) {

    vector<long long> temp(arr.begin() + left, arr.begin() + right + 1);

    int i = 0;
    int j = mid1 - left + 1;
    int k = mid2 - left + 1;

    int end1 = j;
    int end2 = k;
    int end3 = temp.size();

    int out = left;

    while (i < end1 || j < end2 || k < end3) {

        int from = -1;
        int bestIndex = -1;

        if (i < end1) {
            from = 0;
            bestIndex = i;
        }

        if (j < end2 &&
            (bestIndex == -1 ||
             comesBefore(temp[j], temp[bestIndex], descending))) {
            from = 1;
            bestIndex = j;
        }

        if (k < end3 &&
            (bestIndex == -1 ||
             comesBefore(temp[k], temp[bestIndex], descending))) {
            from = 2;
            bestIndex = k;
        }

        arr[out++] = temp[bestIndex];

        if (from == 0) i++;
        else if (from == 1) j++;
        else k++;
    }
}

// Three-way Merge Sort
void mergeSortThree(vector<long long>& arr, int left,
                    int right, bool descending) {

    if (left >= right) return;

    int length = right - left + 1;

    int len1 = (length + 2) / 3;
    int len2 = (length + 1) / 3;

    int mid1 = left + len1 - 1;
    int mid2 = mid1 + len2;

    mergeSortThree(arr, left, mid1, descending);

    if (len2 > 0) {
        mergeSortThree(arr, mid1 + 1, mid2, descending);
    }

    if (length / 3 > 0) {
        mergeSortThree(arr, mid2 + 1, right, descending);
    }

    mergeThree(arr, left, mid1, mid2, right, descending);
}

// ---------------- ARRAY INPUT/OUTPUT ----------------

bool readArray(vector<long long>& arr) {

    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return false;
    }

    arr.resize(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return true;
}

void printArray(const vector<long long>& arr) {

    for (long long value : arr) {
        cout << value << " ";
    }

    cout << endl;
}

// ---------------- SUM OF EVEN NUMBERS ----------------

long long evenSum(const vector<long long>& arr,
                  int left, int right) {

    if (left == right) {
        return (arr[left] % 2 == 0) ? arr[left] : 0;
    }

    int mid = left + (right - left) / 2;

    long long leftSum = evenSum(arr, left, mid);
    long long rightSum = evenSum(arr, mid + 1, right);

    return leftSum + rightSum;
}

// ---------------- SECOND MAXIMUM ----------------

struct TwoValues {
    long long first = 0;
    long long second = 0;

    bool hasFirst = false;
    bool hasSecond = false;
};

void addLargest(TwoValues& result, long long value) {

    if (!result.hasFirst) {
        result.first = value;
        result.hasFirst = true;
        return;
    }

    if (value == result.first ||
        (result.hasSecond && value == result.second)) {
        return;
    }

    if (value > result.first) {
        result.second = result.first;
        result.hasSecond = true;
        result.first = value;
    }
    else if (!result.hasSecond || value > result.second) {
        result.second = value;
        result.hasSecond = true;
    }
}

TwoValues secondMaximum(const vector<long long>& arr,
                        int left, int right) {

    if (left == right) {
        TwoValues result;
        addLargest(result, arr[left]);
        return result;
    }

    int mid = left + (right - left) / 2;

    TwoValues L = secondMaximum(arr, left, mid);
    TwoValues R = secondMaximum(arr, mid + 1, right);

    TwoValues result;

    if (L.hasFirst) addLargest(result, L.first);
    if (L.hasSecond) addLargest(result, L.second);

    if (R.hasFirst) addLargest(result, R.first);
    if (R.hasSecond) addLargest(result, R.second);

    return result;
}

// ---------------- SECOND MINIMUM ----------------

void addSmallest(TwoValues& result, long long value) {

    if (!result.hasFirst) {
        result.first = value;
        result.hasFirst = true;
        return;
    }

    if (value == result.first ||
        (result.hasSecond && value == result.second)) {
        return;
    }

    if (value < result.first) {
        result.second = result.first;
        result.hasSecond = true;
        result.first = value;
    }
    else if (!result.hasSecond || value < result.second) {
        result.second = value;
        result.hasSecond = true;
    }
}

TwoValues secondMinimum(const vector<long long>& arr,
                        int left, int right) {

    if (left == right) {
        TwoValues result;
        addSmallest(result, arr[left]);
        return result;
    }

    int mid = left + (right - left) / 2;

    TwoValues L = secondMinimum(arr, left, mid);
    TwoValues R = secondMinimum(arr, mid + 1, right);

    TwoValues result;

    if (L.hasFirst) addSmallest(result, L.first);
    if (L.hasSecond) addSmallest(result, L.second);

    if (R.hasFirst) addSmallest(result, R.first);
    if (R.hasSecond) addSmallest(result, R.second);

    return result;
}

// ---------------- POWER USING DIVIDE AND CONQUER ----------------

long long power(long long base, int exponent) {

    if (exponent == 0) return 1;

    long long half = power(base, exponent / 2);

    long long answer = half * half;

    if (exponent % 2 == 1) {
        answer *= base;
    }

    return answer;
}

// ---------------- COUNT MULTIPLES OF 3 OR 5 ----------------

int countMultiples(const vector<long long>& arr,
                   int left, int right) {

    if (left == right) {
        return (arr[left] % 3 == 0 || arr[left] % 5 == 0) ? 1 : 0;
    }

    int mid = left + (right - left) / 2;

    int leftCount = countMultiples(arr, left, mid);
    int rightCount = countMultiples(arr, mid + 1, right);

    return leftCount + rightCount;
}

// ---------------- MINIMUM SUM CONSECUTIVE SUBARRAY ----------------

struct SubarrayAnswer {
    long long sum;
    long long prefix;
    long long suffix;
    long long best;
};

SubarrayAnswer minimumSubarray(const vector<long long>& arr,
                               int left, int right) {

    if (left == right) {
        return {arr[left], arr[left], arr[left], arr[left]};
    }

    int mid = left + (right - left) / 2;

    SubarrayAnswer L = minimumSubarray(arr, left, mid);
    SubarrayAnswer R = minimumSubarray(arr, mid + 1, right);

    SubarrayAnswer result;

    result.sum = L.sum + R.sum;

    result.prefix = min(L.prefix, L.sum + R.prefix);

    result.suffix = min(R.suffix, R.sum + L.suffix);

    result.best = min(
        min(L.best, R.best),
        L.suffix + R.prefix
    );

    return result;
}

// ---------------- MAIN FUNCTION ----------------

int main() {

    int choice;

    while (true) {

        cout << "\n===== DIVIDE AND CONQUER PRACTICE =====" << endl;

        cout << "\n--- MERGE SORT ---" << endl;
        cout << "1. Sort in descending order" << endl;
        cout << "2. Sort using three sections (ascending)" << endl;
        cout << "3. Sort using three sections (descending)" << endl;
        cout << "4. Sort first n elements in ascending order" << endl;

        cout << "\n--- SUM OF EVEN NUMBERS ---" << endl;
        cout << "5-8. Four variations" << endl;

        cout << "\n--- SECOND MAXIMUM ---" << endl;
        cout << "9-12. Four variations" << endl;

        cout << "\n--- SECOND MINIMUM ---" << endl;
        cout << "13-16. Four variations" << endl;

        cout << "\n--- POWER ---" << endl;
        cout << "17-20. Four variations" << endl;

        cout << "\n--- COUNT MULTIPLES OF 3 OR 5 ---" << endl;
        cout << "21-24. Four variations" << endl;

        cout << "\n--- MINIMUM SUM SUBARRAY ---" << endl;
        cout << "25-28. Four variations" << endl;

        cout << "\n0. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 0 || choice > 28) {
            cout << "Invalid choice!" << endl;
            continue;
        }

        // 1-4: Merge Sort

        if (choice >= 1 && choice <= 4) {

            vector<long long> arr;

            if (!readArray(arr)) continue;

            if (choice == 1) {

                mergeSortTwo(arr, 0, arr.size() - 1, true);

            }
            else if (choice == 2) {

                mergeSortThree(arr, 0, arr.size() - 1, false);

            }
            else if (choice == 3) {

                mergeSortThree(arr, 0, arr.size() - 1, true);

            }
            else {

                int n;

                cout << "Enter how many first elements to sort: ";
                cin >> n;

                if (n < 0 || n > arr.size()) {
                    cout << "Invalid n!" << endl;
                    continue;
                }

                if (n > 1) {
                    mergeSortTwo(arr, 0, n - 1, false);
                }
            }

            cout << "Result: ";
            printArray(arr);
        }

        // 5-8: Sum of Even Numbers

        else if (choice >= 5 && choice <= 8) {

            vector<long long> arr;

            if (!readArray(arr)) continue;

            cout << "Sum of even elements: "
                 << evenSum(arr, 0, arr.size() - 1) << endl;
        }

        // 9-12: Second Maximum

        else if (choice >= 9 && choice <= 12) {

            vector<long long> arr;

            if (!readArray(arr)) continue;

            if (arr.size() < 2) {
                cout << "At least two distinct values are required." << endl;
                continue;
            }

            TwoValues result = secondMaximum(
                arr, 0, arr.size() - 1
            );

            if (result.hasSecond) {

                cout << "Maximum: " << result.first << endl;
                cout << "Second maximum: " << result.second << endl;

            }
            else {
                cout << "At least two distinct values are required." << endl;
            }
        }

        // 13-16: Second Minimum

        else if (choice >= 13 && choice <= 16) {

            vector<long long> arr;

            if (!readArray(arr)) continue;

            if (arr.size() < 2) {
                cout << "At least two distinct values are required." << endl;
                continue;
            }

            TwoValues result = secondMinimum(
                arr, 0, arr.size() - 1
            );

            if (result.hasSecond) {

                cout << "Minimum: " << result.first << endl;
                cout << "Second minimum: " << result.second << endl;

            }
            else {
                cout << "At least two distinct values are required." << endl;
            }
        }

        // 17-20: Calculate Power

        else if (choice >= 17 && choice <= 20) {

            long long base;
            int exponent;

            cout << "Enter base b: ";
            cin >> base;

            cout << "Enter exponent n: ";
            cin >> exponent;

            if (exponent < 0) {
                cout << "Exponent must be non-negative." << endl;
            }
            else {
                cout << "Result: "
                     << power(base, exponent) << endl;
            }
        }

        // 21-24: Count Multiples of 3 or 5

        else if (choice >= 21 && choice <= 24) {

            vector<long long> arr;

            if (!readArray(arr)) continue;

            cout << "Count of multiples of 3 or 5: "
                 << countMultiples(arr, 0, arr.size() - 1)
                 << endl;
        }

        // 25-28: Minimum Sum Subarray

        else if (choice >= 25 && choice <= 28) {

            vector<long long> arr;

            if (!readArray(arr)) continue;

            SubarrayAnswer result = minimumSubarray(
                arr, 0, arr.size() - 1
            );

            cout << "Minimum consecutive subarray sum: "
                 << result.best << endl;
        }
    }

    cout << "Program ended." << endl;

    return 0;
}
