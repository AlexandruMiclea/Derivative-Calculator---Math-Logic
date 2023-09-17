#include "../lib/ExpressionTree.hpp"
#include "../lib/FunctionParser.hpp"

void ExpressionTree::fnSetExpression(stack <string> stsArg) { stsExpression = stsArg; }
node* ExpressionTree::fnGetTree() { return head; }


void ExpressionTree::fnCreateTree() {
	// add the first node 

	//nu ii place ca accesez stsExpression
	//nu asta este problema, are ceva de a face cu arborele

	node* create = new node;
	create->sData = stsExpression.top();
	create->pDad = NULL;
	create->pLeft = NULL;
	create->pRight = NULL;
	stsExpression.pop();

	Tree = create;
	head = create;

	while (!stsExpression.empty()) {
		bool bIsPlaced = false;
		create = new node;
		create->sData = stsExpression.top();
		create->pDad = NULL;
		create->pLeft = NULL;
		create->pRight = NULL;

		if (Tree->pLeft == NULL) {
			Tree->pLeft = create;
			bIsPlaced = true;
		}
		else if (Tree->pRight == NULL) {
			Tree->pRight = create;
			bIsPlaced = true;
		}

		if (Tree->pRight != NULL && !bIsPlaced) {
			// go upwards until you find a free right node
			while (Tree->pDad != NULL) Tree = Tree->pDad;
			Tree->pRight = create;
		}

		create->pDad = Tree;

		if (FunctionParser::bfnIsOperator(stsExpression.top())) {
			Tree = create;
		}
		

		stsExpression.pop();
	}
}

node* ExpressionTree::fnGetDerivatedTree(node* nodeArg){

	// check whether you have a node or a leaf
	// if node, derive using switch case
	// if leaf, number -> 0, x -> 1

	return nullptr;
}






