#include "ExpressionTree.h"
#include <iostream>

void ExpressionTree::fnSetExpression(stack <string> stsArg) { stsExpression = stsArg; }
node* ExpressionTree::fnGetTree() { return head; }

bool ExpressionTree::bfnIsOperator(string sArg) {
	return sArg == "+" ||
		sArg == "-" ||
		sArg == "*" ||
		sArg == "/" ||
		sArg == "^";
}

void ExpressionTree::fnCreateTree() {
	// add the first node 

	//nu ii place ca accesez stsExpression

	node* create = new node;
	create->sData = stsExpression.top();
	create->pDad = NULL;
	create->pLeft = NULL;
	create->pRight = NULL;
	stsExpression.pop();

	Tree = create;
	head = create;

	while (!stsExpression.empty()) {
		create = new node;
		create->sData = stsExpression.top();

		create->pDad = Tree;
		if (Tree->pLeft != NULL && Tree->pRight != NULL) {
			// go upwards until you find a free right node
			while (Tree->pRight != NULL) Tree = Tree->pDad;
		}

		if (Tree->pLeft == NULL) Tree->pLeft = create;
		else if (Tree->pRight == NULL)Tree->pRight = create;

		if (bfnIsOperator(stsExpression.top())) {
			Tree = create;
		}

		stsExpression.pop();
	}
}






