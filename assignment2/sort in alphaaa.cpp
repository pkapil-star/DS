#include <iostream>
#include <cstring> // for strcmp and strcpy
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // clear buffer

    char str[20][50]; // array to store up to 20 strings, each max 50 chars

    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin.getline(str[i], 50);
    }

    // Bubble sort for strings
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                // swap strings
                char temp[50];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    cout << "\nStrings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
