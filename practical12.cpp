#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string optimize(string expr) {
    string res;
    int i = 0;
    while (i < expr.length()) {
        if (isdigit(expr[i])) {
            int num1 = 0;
            while (i < expr.length() && isdigit(expr[i])) num1 = num1*10 + (expr[i++] - '0');
            if (i < expr.length() && (expr[i] == '*' || expr[i] == '/')) {
                char op = expr[i++];
                int num2 = 0;
                while (i < expr.length() && isdigit(expr[i])) num2 = num2*10 + (expr[i++] - '0');
                if (op == '*') num1 = num1 * num2;
                else if (op == '/') num1 = num1 / num2;
            }
            res += to_string(num1);
        } else {
            res += expr[i++];
        }
    }
    return res;
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);
    cout << "Optimized Expression: " << optimize(expr) << endl;
    return 0;
}
