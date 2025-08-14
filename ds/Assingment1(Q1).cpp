#include <iostream>
using namespace std;

int arr[10], n = 0;

void create() {
    cout << "How many elements? ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void display() {
    if (n == 0) cout << "Array is empty\n";
    else {
        cout << "Array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
}

void insert() {
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    if (pos < 0 || pos > n || n >= 10) {
        cout << "Invalid position or array full\n";
        return;
    }
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void removeElement() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void search() {
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at position " << i << "\n";
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if      (choice == 1) create();
        else if (choice == 2) display();
        else if (choice == 3) insert();
        else if (choice == 4) removeElement();
        else if (choice == 5) search();
        else if (choice == 6) cout << "Exiting...\n";
        else cout << "Invalid choice\n";

    } while (choice != 6);

    return 0;
}
