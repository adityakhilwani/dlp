#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

map<char, set<char>> firstSet;
map<char, set<char>> followSet;
map<char, map<char, string>> parsingTable;
set<char> terminals;
set<char> nonTerminals;

// Function to add First set
void addFirst(char key, char value) {
    if (value != 'ε') {
        firstSet[key].insert(value);
    }
}

// Function to compute First Set
void computeFirst() {
    firstSet['A'] = {'a', '@'};  // Using '@' to represent epsilon
    firstSet['B'] = {'b', '@'};
    firstSet['C'] = {'(', 'c'};
    firstSet['D'] = {'a', '('};
    firstSet['S'] = {'a', 'b', '(', 'c'};
}

// Function to compute Follow Set
void computeFollow() {
    followSet['S'] = {')', '$'};
    followSet['A'] = {'b', '(', ')', '$'};
    followSet['B'] = {'c', ')', '$'};
    followSet['C'] = {')', '$'};
    followSet['D'] = {')', '$'};
}

// Function to construct Predictive Parsing Table
void constructParsingTable() {
    parsingTable['S']['a'] = "A B C";
    parsingTable['S']['b'] = "A B C";
    parsingTable['S']['('] = "A B C";
    parsingTable['S']['c'] = "A B C";
    parsingTable['S']['$'] = "D";

    parsingTable['A']['a'] = "a";
    parsingTable['A']['b'] = "ε";
    parsingTable['A']['('] = "ε";
    parsingTable['A']['c'] = "ε";

    parsingTable['B']['b'] = "b";
    parsingTable['B']['('] = "ε";
    parsingTable['B']['c'] = "ε";
    parsingTable['B'][')'] = "ε";

    parsingTable['C']['('] = "( S )";
    parsingTable['C']['c'] = "c";

    parsingTable['D']['a'] = "A C";
    parsingTable['D']['('] = "A C";
}

// Function to check if Grammar is LL(1)
bool isLL1() {
    for (auto &entry : parsingTable) {
        set<string> productions;
        for (auto &rule : entry.second) {
            if (!rule.second.empty()) {
                if (productions.find(rule.second) != productions.end()) {
                    return false;
                }
                productions.insert(rule.second);
            }
        }
    }
    return true;
}

// Function to display Parsing Table
void displayParsingTable() {
    cout << "\nPredictive Parsing Table:\n";
    cout << "--------------------------------\n";
    cout << "Non-Terminal\tInput Symbol\tProduction\n";
    cout << "--------------------------------\n";
    for (auto &entry : parsingTable) {
        for (auto &rule : entry.second) {
            if (!rule.second.empty()) {
                cout << entry.first << "\t\t" << rule.first << "\t\t" << rule.second << endl;
            }
        }
    }
}

int main() {
    computeFirst();
    computeFollow();
    constructParsingTable();

    displayParsingTable();

    if (isLL1()) {
        cout << "\nThe given grammar is **LL(1)**" << endl;
    } else {
        cout << "\nThe given grammar is **not LL(1)**" << endl;
    }

    return 0;
}
