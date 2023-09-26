#include <iostream>
#include "./lib/FunctionParser.hpp"
#include "./lib/ExpressionTree.hpp"
#include "./lib/DerivativeCalc.hpp"

using namespace std;

string input;
stack <string> afterParse;
FunctionParser parser;
ExpressionTree tree;
DerivativeCalc calc;

int main() {

    cout << "Enter the function to derive: ";
    cin >> input;

    // transform the input from an infix to a postfix notation
    // e.g. 5*x^3 -> 5x3^*

    parser.setExpression(input);
    parser.parseExpression();
    afterParse = parser.getExpression();

    stack <string> stsCopy = afterParse;

    while (!stsCopy.empty()) {
        cout << stsCopy.top();
        stsCopy.pop();
    }
    cout << '\n';

    // create an expression tree from afterParse
    //                                *
    // e.g. 5*x^3 -> *^3x5 ->       ^   5
    //                            3   x

    //TODO

    tree.setExpression(afterParse);
    tree.createTree();
    cout << tree.printTree(nullptr) << '\n';

    node* functionTree = new node;
    functionTree = tree.getTree();
    // cout << '\n';
    // cout << functionTree->sData;
    // cout << '\n';
    // cout << functionTree->pRight->sData;
    // cout << '\n';
    // cout << functionTree->pLeft->sData;
    // cout << '\n';
    // cout << functionTree->pLeft->pLeft->sData;
    // cout << '\n';
    // cout << functionTree->pLeft->pRight->sData;

    // derive each operation of the tree according to derivation rules
    // e.g. 5x^3 -> 0 * x^3 + 5 * 3x^2  -> 15x^2

    // CHANGE
    node* firstDerivative = calc.deriveTree(functionTree);
    cout << tree.getDerivedTree(firstDerivative) << '\n';

    //cout << input;

    return 0;
}

// TODO list
// abst class for isOperator
// merge DerivativeCalc with ExpressionTree ?? 
// method for printing the Expression Tree