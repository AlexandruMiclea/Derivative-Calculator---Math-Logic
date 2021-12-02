#include <iostream>
#include <stack>
#include <string>

using namespace std;

string sInput;

int main() {

    cout << "Enter the function to derive: ";
    cin >> sInput;
    
    // transform the input from an infix to a reverse postfix notation
    // e.g. 5*x^3 -> 5x3^*

    //TODO

    // flip the input and create an expression tree from it
    //                                *
    // e.g. 5x3^* -> *^3x5 ->       ^   5
    //                            3   x

    //TODO

    // derive each operation of the tree according to derivation rules
    // e.g. 5x^3 -> 3x^2 * 5 + x^3 * 0 -> 15x^2

    //TODO

    cout << sInput;

    return 0;
}