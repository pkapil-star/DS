#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[100];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                arr[j] = arr[size - 1]; 
                size--;                 
                j--;                    
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}
