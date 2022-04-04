#include "ExpressionTree.h"
#include "FunctionParser.h"

void ExpressionTree::fnSetExpression(string sArg) { sExpression = sArg; }

bool ExpressionTree::bfnIsOperator(string sArg) {
	return sArg == "+" ||
		sArg == "-" ||
		sArg == "*" ||
		sArg == "/" ||
		sArg == "^";
}

void ExpressionTree::fnCreateTree() {
	// create first node
	struct node* root = NULL;

	for (int i = 1; i < sExpression.length(); i++) {
		
	}
}

node* ExpressionTree::createNode(string sArg) {
	node* newNode;
	newNode->sData = sArg;
	newNode->pLeft = NULL;
	newNode->pRight = NULL;

	return newNode;
}

void ExpressionTree::fnGetTree() {

}
