#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    int freq[256] = {0}; // frequency array for ASCII characters

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // push character to queue
        q.push(ch);
        freq[ch]++;

        // remove from front if it's repeating
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // print result
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter string (without spaces): ";
    cin >> input;

    cout << "Output: ";
    firstNonRepeating(input);

    return 0;
}
