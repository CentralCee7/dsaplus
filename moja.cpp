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


        cout << " Sort in descending order\n";


        cout << "type 1: ";
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
    }
    return 0;
}