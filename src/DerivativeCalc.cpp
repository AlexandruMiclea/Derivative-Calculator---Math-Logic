#include "../lib/DerivativeCalc.hpp"
#include "../lib/ExpressionTree.hpp"


bool DerivativeCalc::isOperator(string sArg) {

	return sArg == "+" ||
		sArg == "-" ||
		sArg == "*" ||
		sArg == "/" ||
		sArg == "^";
}

bool DerivativeCalc::isNumber(string sArg) {
	for (auto& x : sArg) {
		if (isdigit(x) == 0) return false;
	}
	return true;
}

node* DerivativeCalc::deriveTree(node* nodeArg){

	if (nodeArg->sData == "x") {
		node* ret = new node;
		ret->sData = "1";
		ret->pDad = nodeArg->pDad;
		ret->pLeft = NULL;
		ret->pRight = NULL;

		return ret;
	}
	else if (isNumber(nodeArg->sData)) {
		node* ret = new node;
		ret->sData = "0";
		ret->pDad = nodeArg->pDad;
		ret->pLeft = NULL;
		ret->pRight = NULL;

		return ret;
	}
	else if (nodeArg->sData == "+") {
		node* ret = new node;
		ret->sData = "+";
		ret->pDad = nodeArg->pDad;
		ret->pLeft = deriveTree(nodeArg->pLeft);
		ret->pRight = deriveTree(nodeArg->pRight);

		return ret;

	}
	else if (nodeArg->sData == "-") {
		node* ret = new node;
		ret->sData = "-";
		ret->pDad = nodeArg->pDad;
		ret->pLeft = deriveTree(nodeArg->pLeft);
		ret->pRight = deriveTree(nodeArg->pRight);

		return ret;
	}
	else if (nodeArg->sData == "*") {
		//cout << 'a';
		node* ret = new node;
		ret->sData = "+";
		ret->pDad = nodeArg->pDad;

		//cout << 'b';
		node* left = new node;
		left->sData = "*";
		left->pDad = ret;
		left->pLeft = deriveTree(nodeArg->pLeft);
		left->pRight = nodeArg->pRight;

		node* right = new node;
		right->sData = "*";
		right->pDad = ret;
		right->pLeft = nodeArg->pLeft;
		right->pRight = deriveTree(nodeArg->pRight);

		ret->pLeft = left;
		ret->pRight = right;

		return ret;
	}
	else if (nodeArg->sData == "/") {

		node* ret = new node;
		node* left = new node;
		node* right = new node;
		node* leftleft = new node;
		node* leftright = new node;
		node* two = new node;

		two->sData = "2";
		two->pDad = right;
		two->pLeft = NULL;
		two->pRight = NULL;

		leftleft->sData = "*";
		leftleft->pDad = left;
		leftleft->pLeft = deriveTree(nodeArg->pLeft);
		leftleft->pRight = nodeArg->pRight;

		leftright->sData = "*";
		leftright->pDad = left;
		leftright->pLeft = nodeArg->pLeft;
		leftright->pRight = deriveTree(nodeArg->pRight);

		left->sData = "-";
		left->pDad = ret;
		left->pLeft = leftleft;
		left->pRight = leftright;


		right->sData = "^";
		right->pDad = ret;
		right->pLeft = two; //TODO nod cu valoarea 2
		right->pRight = nodeArg->pRight;

		ret->sData = "/";
		ret->pDad = nodeArg->pDad;
		ret->pRight = right;
		ret->pLeft = left;

		return ret;
	}
	else if (nodeArg->sData == "^") {

		node* ret = new node;
		node* left = new node;
		//node* right = new node;
		node* leftleft = new node;
		node* lessone = new node;

		lessone->sData = to_string(stoi(nodeArg->pLeft->sData) - 1);
		lessone->pDad = leftleft; //TODO
		lessone->pLeft = NULL;
		lessone->pRight = NULL;

		leftleft->sData = "^";
		leftleft->pDad = left;
		leftleft->pLeft = lessone;
		leftleft->pRight = nodeArg->pRight;

		left->sData = "*";
		left->pDad = ret;
		left->pLeft = leftleft;
		left->pRight = nodeArg->pLeft;

		ret->sData = "*";
		ret->pDad = nodeArg->pDad;
		ret->pLeft = left;
		ret->pRight = deriveTree(nodeArg->pRight);

		return ret;
	}
	return NULL;
}