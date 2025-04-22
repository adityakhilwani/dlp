#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Quadruple {
    string op, arg1, arg2, result;
};

int tempVar = 1;
vector<Quadruple> quads;

string newTemp() {
    return "t" + to_string(tempVar++);
}

void generate(string op, string arg1, string arg2) {
    Quadruple q = {op, arg1, arg2, newTemp()};
    quads.push_back(q);
}

int main() {
    string expr = "9+42*8";
    generate("*", "42", "8");
    generate("+", "9", "t1");

    cout << "Operator\tOperand1\tOperand2\tResult" << endl;
    for (auto &q : quads) {
        cout << q.op << "\t\t" << q.arg1 << "\t\t" << q.arg2 << "\t\t" << q.result << endl;
    }
    return 0;
}
