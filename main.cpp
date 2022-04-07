#include <iostream>
#include "FunctionParser.h"
#include "ExpressionTree.h"

using namespace std;

string sInput;
stack <string> sAfterParse;
FunctionParser parser;
ExpressionTree tree;

int main() {

    cout << "Enter the function to derive: ";
    cin >> sInput;

    // transform the input from an infix to a postfix notation
    // e.g. 5*x^3 -> 5x3^*

    parser.fnSetExpression(sInput);
    parser.fnParseExpression();
    sAfterParse = parser.sfnGetExpression();

    stack <string> stsCopy = sAfterParse;

    while (!stsCopy.empty()) {
        cout << stsCopy.top();
        stsCopy.pop();
    }

    // create an expression tree from sAfterParse
    //                                *
    // e.g. 5x3^* -> *^3x5 ->       ^   5
    //                            3   x

    //TODO

    tree.fnSetExpression(sAfterParse);
    tree.fnCreateTree();

    node* functionTree = new node;
    functionTree = tree.fnGetTree();

    cout << functionTree->sData;

    // derive each operation of the tree according to derivation rules
    // e.g. 5x^3 -> 0 * x^3 + 5 * 3x^2  -> 15x^2

    //TODO

    //cout << sInput;

    return 0;
}