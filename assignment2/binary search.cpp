#include <iostream>
#include <algorithm>  // for sort()
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            return mid; // found element
        }
        else if (arr[mid] < key) {
            left = mid + 1; // search right side
        }
        else {
            right = mid - 1; // search left side
        }
    }
    return -1; // not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort array to apply binary search
    sort(arr, arr + n);

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
