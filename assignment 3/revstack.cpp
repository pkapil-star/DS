#include <iostream>
#include <string>
using namespace std;

struct Stack {
    char arr[1000]; // array to hold characters (enough size)
    int top;
};

void push(Stack &s, char ch) {
    s.top++;
    s.arr[s.top] = ch;
}

char pop(Stack &s) {
    if (s.top == -1)
        return '\0'; // return null char if empty
    char ch = s.arr[s.top];
    s.top--;
    return ch;
}

int main() {
    Stack s;
    s.top = -1;

    string input;
    cout << "Enter a string to reverse: ";
    getline(cin, input);

    // Push characters into stack
    for (int i = 0; i < input.length(); i++) {
        push(s, input[i]);
    }

    cout << "Reversed string: ";
    while (s.top != -1) {
        cout << pop(s);
    }
    cout << endl;

    return 0;
}
