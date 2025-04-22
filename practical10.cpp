#include <iostream>
#include <stack>
#include <cmath>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a,b);
    }
    return 0;
}

int evaluate(string tokens) {
    stack<int> values;
    stack<char> ops;
    for (int i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ') continue;
        else if (tokens[i] == '(') ops.push(tokens[i]);
        else if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            values.push(val);
            i--;
        } else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int v2 = values.top(); values.pop();
                int v1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(v1, v2, op));
            }
            ops.pop();
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                int v2 = values.top(); values.pop();
                int v1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(v1, v2, op));
            }
            ops.push(tokens[i]);
        }
    }
    while (!ops.empty()) {
        int v2 = values.top(); values.pop();
        int v1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(v1, v2, op));
    }
    return values.top();
}

int main() {
    string expr;
    cout << "Enter arithmetic expression: ";
    getline(cin, expr);
    try {
        cout << "Result: " << evaluate(expr) << endl;
    } catch (...) {
        cout << "Invalid Expression" << endl;
    }
    return 0;
}
