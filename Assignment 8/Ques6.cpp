#include <iostream>
using namespace std;

const int MAX = 100;

int heapArr[MAX];
int heapSize = 0;

void swapInt(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void heapifyDown(int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= heapSize && heapArr[left] > heapArr[largest])
        largest = left;
    if (right <= heapSize && heapArr[right] > heapArr[largest])
        largest = right;

    if (largest != i) {
        swapInt(heapArr[i], heapArr[largest]);
        heapifyDown(largest);
    }
}

void heapifyUp(int i) {
    int parent = i / 2;
    while (i > 1 && heapArr[i] > heapArr[parent]) {
        swapInt(heapArr[i], heapArr[parent]);
        i = parent;
        parent = i / 2;
    }
}

void insertPQ(int x) {
    if (heapSize == MAX - 1) {
        cout << "Priority queue full\n";
        return;
    }
    heapSize++;
    heapArr[heapSize] = x;
    heapifyUp(heapSize);
}

int getMax() {
    if (heapSize == 0) return -1;
    return heapArr[1];
}

int deleteMax() {
    if (heapSize == 0) {
        cout << "Priority queue empty\n";
        return -1;
    }
    int maxVal = heapArr[1];
    heapArr[1] = heapArr[heapSize];
    heapSize--;
    heapifyDown(1);
    return maxVal;
}

void displayPQ() {
    if (heapSize == 0) {
        cout << "Priority queue empty\n";
        return;
    }
    cout << "Heap elements: ";
    for (int i = 1; i <= heapSize; i++)
        cout << heapArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, x;
    do {
        cout << "\n1. Insert\n2. Get Max\n3. Delete Max\n4. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertPQ(x);
                break;
            case 2:
                x = getMax();
                if (x == -1 && heapSize == 0)
                    cout << "Priority queue empty\n";
                else
                    cout << "Max element: " << x << endl;
                break;
            case 3:
                x = deleteMax();
                if (!(x == -1 && heapSize == 0))
                    cout << "Deleted max: " << x << endl;
                break;
            case 4:
                displayPQ();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
