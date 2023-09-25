#include "../lib/ExpressionTree.hpp"
#include "../lib/FunctionParser.hpp"

void ExpressionTree::setExpression(stack <string> stsArg) { expression = stsArg; }
node* ExpressionTree::getTree() { return head; }


void ExpressionTree::createTree() {
	// add the first node 

	//nu ii place ca accesez stsExpression
	//nu asta este problema, are ceva de a face cu arborele

	node* create = new node;
	create->sData = expression.top();
	create->pDad = NULL;
	create->pLeft = NULL;
	create->pRight = NULL;
	expression.pop();

	Tree = create;
	head = create;

	while (!expression.empty()) {
		bool bIsPlaced = false;
		create = new node;
		create->sData = expression.top();
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

		if (FunctionParser::isOperator(expression.top())) {
			Tree = create;
		}
		

		expression.pop();
	}
}

node* ExpressionTree::getDerivedTree(node* nodeArg){

	// check whether you have a node or a leaf
	// if node, derive using switch case
	// if leaf, number -> 0, x -> 1
	nodeArg = nullptr;
	return nodeArg;
}






