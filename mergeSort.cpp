
#include <iostream>
#include <vector>
using namespace std;

// Merge function
template <typename T, typename Compare>
void merge(vector<T>& arr, int left, int mid, int right, Compare comp) {

    vector<T> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (comp(arr[i], arr[j])) {
            temp.push_back(arr[i]);
            i++;
        }
        else if (comp(arr[j], arr[i])) {
            temp.push_back(arr[j]);
            j++;
        }
        else {
            temp.push_back(arr[i]);
            i++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Merge Sort function
template <typename T, typename Compare>
void mergeSort(vector<T>& arr, int left, int right, Compare comp) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, comp);
    mergeSort(arr, mid + 1, right, comp);

    merge(arr, left, mid, right, comp);
}

// Calculate absolute value safely
unsigned long long absoluteValue(long long n) {
    if (n >= 0) {
        return static_cast<unsigned long long>(n);
    }

    return static_cast<unsigned long long>(-(n + 1)) + 1;
}

// Calculate sum of digits
long long digitSum(long long n) {

    long long sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

// Print array
void printArray(vector<long long> arr) {

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {

    int choice;

    while (true) {

        cout << "\n===== MERGE SORT PRACTICE PROBLEMS =====\n";

        cout << "1. Sort in descending order\n";
        cout << "2. Sort a specific range\n";
        cout << "3. Sort according to absolute values\n";
        cout << "4. Sort according to sum of digits\n";
        cout << "5. Sort only odd indices\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > 5) {
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

        // 1. Descending order

        if (choice == 1) {

            mergeSort(arr, 0, n - 1, greater<long long>());

            cout << "Sorted array: ";
            printArray(arr);
        }

        // 2. Sort a specific range

        else if (choice == 2) {

            int start, end;

            cout << "Enter start index: ";
            cin >> start;

            cout << "Enter end index: ";
            cin >> end;

            if (start < 0 || end >= n || start > end) {
                cout << "Invalid range!" << endl;
            }
            else {

                mergeSort(arr, start, end, less<long long>());

                cout << "Sorted array: ";
                printArray(arr);
            }
        }

        // 3. Sort according to absolute values

        else if (choice == 3) {

            auto comp = [](long long a, long long b) {
                return absoluteValue(a) < absoluteValue(b);
            };

            mergeSort(arr, 0, n - 1, comp);

            cout << "Sorted array: ";
            printArray(arr);
        }

        // 4. Sort according to sum of digits

        else if (choice == 4) {

            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (arr[i] < 0) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                cout << "Only non-negative integers are allowed." << endl;
            }
            else {

                auto comp = [](long long a, long long b) {
                    return digitSum(a) < digitSum(b);
                };

                mergeSort(arr, 0, n - 1, comp);

                cout << "Sorted array: ";
                printArray(arr);
            }
        }

        // 5. Sort only odd indices

        else if (choice == 5) {

            vector<long long> oddIndexElements;

            for (int i = 1; i < n; i += 2) {
                oddIndexElements.push_back(arr[i]);
            }

            if (!oddIndexElements.empty()) {

                mergeSort(
                    oddIndexElements,
                    0,
                    oddIndexElements.size() - 1,
                    less<long long>()
                );
            }

            int j = 0;

            for (int i = 1; i < n; i += 2) {
                arr[i] = oddIndexElements[j];
                j++;
            }

            cout << "Sorted array: ";
            printArray(arr);
        }
    }

    return 0;
}
