#include <iostream>
#include <string>
using namespace std;

string input;
int pos = 0;

bool S();
bool E();
bool Sdash();

bool match(char c) {
    if (pos < input.length() && input[pos] == c) {
        pos++;
        return true;
    }
    return false;
}

bool E() {
    return match('b');
}

bool S() {
    if (match('i')) {
        if (E() && match('t') && S() && Sdash()) {
            return true;
        }
    } else if (match('a')) {
        return true;
    }
    return false;
}

bool Sdash() {
    if (match('e')) {
        return S();
    }
    return true; // ε
}

int main() {
    cout << "Enter string: ";
    cin >> input;
    pos = 0;
    if (S() && pos == input.length()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }
    return 0;
}
