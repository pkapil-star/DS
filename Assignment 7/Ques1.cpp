#include <iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[m]) m = j;
        swap(a[i], a[m]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int partition(int a[], int l, int r) {
    int p = a[r], i = l - 1;
    for (int j = l; j < r; j++)
        if (a[j] < p) swap(a[++i], a[j]);
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int a[n], b[n], c[n], d[n], e[n];
    for (int i = 0; i < n; i++) {
        a[i] = arr[i];
        b[i] = arr[i];
        c[i] = arr[i];
        d[i] = arr[i];
        e[i] = arr[i];
    }

    selectionSort(a, n);
    cout << "Selection Sort: ";
    print(a, n);

    insertionSort(b, n);
    cout << "Insertion Sort: ";
    print(b, n);

    bubbleSort(c, n);
    cout << "Bubble Sort: ";
    print(c, n);

    mergeSort(d, 0, n - 1);
    cout << "Merge Sort: ";
    print(d, n);

    quickSort(e, 0, n - 1);
    cout << "Quick Sort: ";
    print(e, n);

    return 0;
}
