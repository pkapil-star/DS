#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch); // push opening bracket
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false; // no matching opening

            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // mismatch
                }
            s.pop(); // matched pair
        }
    }

    return s.empty(); // if empty → balanced
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "Balanced Parentheses ✅" << endl;
    else
        cout << "Not Balanced ❌" << endl;

    return 0;
}
