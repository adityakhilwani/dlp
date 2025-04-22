#include <iostream>
#include <set>
using namespace std;

int main() {
    cout << "First(S) = { a, b, (, c }" << endl;
    cout << "First(A) = { a, ε }" << endl;
    cout << "First(B) = { b, ε }" << endl;
    cout << "First(C) = { (, c }" << endl;
    cout << "First(D) = { a, ( }" << endl;
    
    cout << "Follow(S) = { ), $ }" << endl;
    cout << "Follow(A) = { b, (, ), $ }" << endl;
    cout << "Follow(B) = { c, ), $ }" << endl;
    cout << "Follow(C) = { ), $ }" << endl;
    cout << "Follow(D) = { ), $ }" << endl;
    return 0;
}
