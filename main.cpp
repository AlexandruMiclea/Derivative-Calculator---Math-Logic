#include <iostream>
#include "FunctionParser.h"
#include "ExpressionTree.h"
#include "DerivativeCalc.h"

using namespace std;

string sInput;
stack <string> sAfterParse;
FunctionParser parser;
ExpressionTree tree;
DerivativeCalc calc;

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
    // e.g. 5*x^3 -> *^3x5 ->       ^   5
    //                            3   x

    //TODO

    tree.fnSetExpression(sAfterParse);
    tree.fnCreateTree();

    node* functionTree = new node;
    functionTree = tree.fnGetTree();
    cout << '\n';
    cout << functionTree->sData;
    cout << '\n';
    cout << functionTree->pRight->sData;
    cout << '\n';
    cout << functionTree->pLeft->sData;
    cout << '\n';
    cout << functionTree->pLeft->pLeft->sData;
    cout << '\n';
    cout << functionTree->pLeft->pRight->sData;

    // derive each operation of the tree according to derivation rules
    // e.g. 5x^3 -> 0 * x^3 + 5 * 3x^2  -> 15x^2

    // CHANGE
    node* firstDerivative = calc.fnGetDerivatedTree(functionTree);

    //cout << sInput;

    return 0;
}