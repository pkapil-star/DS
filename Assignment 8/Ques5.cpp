#include <iostream>
using namespace std;

void heapify(int a[], int n, int i, bool increasing) {
    int extreme = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (increasing) {
        if (l < n && a[l] > a[extreme]) extreme = l;
        if (r < n && a[r] > a[extreme]) extreme = r;
    } else {
        if (l < n && a[l] < a[extreme]) extreme = l;
        if (r < n && a[r] < a[extreme]) extreme = r;
    }

    if (extreme != i) {
        swap(a[i], a[extreme]);
        heapify(a, n, extreme, increasing);
    }
}

void heapSort(int a[], int n, bool increasing) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, increasing);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, increasing);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int ch;
    cout << "1. Increasing order\n2. Decreasing order\nEnter choice: ";
    cin >> ch;

    if (ch == 1) heapSort(a, n, true);
    else heapSort(a, n, false);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
