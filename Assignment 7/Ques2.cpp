#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int minIndex = left;
        int maxIndex = left;
        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex]) minIndex = i;
            if (a[i] > a[maxIndex]) maxIndex = i;
        }
        swap(a[left], a[minIndex]);
        if (maxIndex == left) maxIndex = minIndex;
        swap(a[right], a[maxIndex]);
        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    improvedSelectionSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
