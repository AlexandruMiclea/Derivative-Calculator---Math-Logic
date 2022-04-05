#include "ExpressionTree.h"

void ExpressionTree::fnSetExpression(stack <string> vsArg) { stsExpression = vsArg; }

bool ExpressionTree::bfnIsOperator(string sArg) {
	return sArg == "+" ||
		sArg == "-" ||
		sArg == "*" ||
		sArg == "/" ||
		sArg == "^";
}


node* createNode(string sargData) {
	node newNode;
	newNode.sData = sargData;
	newNode.pLeft = NULL;
	newNode.pRight = NULL;

	return *newNode;
}


