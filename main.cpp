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

void runApp(){
    cout << "Enter the function to derive: ";
    cin >> input;

    // transform the input from an infix to a postfix notation
    // e.g. 5*x^3 -> 5x3^*

    parser.setExpression(input);
    parser.parseExpression();
    afterParse = parser.getExpression();

    // create an expression tree from afterParse
    //                                *
    // e.g. 5*x^3 -> *^3x5 ->       ^   5
    //                            3   x

    tree.setExpression(afterParse);
    tree.createTree();

    // derive each operation of the tree according to derivation rules
    // e.g. 5*x^3 -> 0*x^3 + 5*3x^2  -> 15x^2

    //DEBUG
    cout << tree.printTree(nullptr) << '\n';

    node* firstDerivative = calc.deriveTree(tree.getTree());

    //DEBUG
    cout << tree.printTree(firstDerivative) << '\n';
}

int main() {

    runApp();

    return 0;
}

// TODO list
// abst class for isOperator
// runApp does not clear itself after deriative print -> redo memory and pointers
// merge DerivativeCalc with ExpressionTree ?? 
// simplification rules