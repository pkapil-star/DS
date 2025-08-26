#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int i = 0, j = 0;
    while (str[i] != '\0') {
        // check if current character is NOT a vowel
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
              str[i] == 'o' || str[i] == 'u' ||
              str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
              str[i] == 'O' || str[i] == 'U')) {
            str[j++] = str[i];  // copy only non-vowels
              }
        i++;
    }
    str[j] = '\0';  // end the new string

    cout << "String after deleting vowels: " << str << endl;

    return 0;
}
