#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            // If operand, push to stack (convert char to int)
            st.push(ch - '0');
        }
        else {
            // Operator case
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (single-digit operands): ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
