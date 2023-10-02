#include "../lib/ExpressionTree.hpp"
#include "../lib/FunctionParser.hpp"

void ExpressionTree::setExpression(stack <string> stsArg) { expression = stsArg; }
node* ExpressionTree::getTree() { return head; }

void ExpressionTree::createTree() {
	node* create = new node;
	create->sData = expression.top();
	create->pDad = nullptr;
	create->pLeft = nullptr;
	create->pRight = nullptr;
	expression.pop();

	Tree = create;
	head = create;

	while (!expression.empty()) {
		bool bIsPlaced = false;
		create = new node;
		create->sData = expression.top();
		create->pDad = nullptr;
		create->pLeft = nullptr;
		create->pRight = nullptr;

		if (Tree->pLeft == nullptr) {
			Tree->pLeft = create;
			bIsPlaced = true;
		}
		else if (Tree->pRight == nullptr) {
			Tree->pRight = create;
			bIsPlaced = true;
		}

		if (Tree->pRight != nullptr && !bIsPlaced) {
			// go upwards until you find a free right node
			while (Tree->pDad != nullptr) Tree = Tree->pDad;
			Tree->pRight = create;
		}

		create->pDad = Tree;

		if (FunctionParser::isOperator(expression.top())) {
			Tree = create;
		}
		
		expression.pop();
	}
}

string ExpressionTree::printTree(node* ptr) {

	// preorder printing of the tree
	// if node is nullptr use head

	if (ptr == nullptr) ptr = head;

	string res = ptr->sData;
	if (ptr->pLeft != nullptr)
		res += printTree(ptr->pLeft);
	if (ptr->pRight != nullptr)
		res += printTree(ptr->pRight);

	if (ptr == nullptr) return "";
	return res;
}