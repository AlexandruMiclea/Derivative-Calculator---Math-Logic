#pragma once
#include <string>
#include <stack>
using namespace std;

struct node {
	string sData;
	node *pRight = NULL, *pLeft = NULL, *pDad = NULL;
};

class ExpressionTree{

private:
	node *Tree = NULL, *head = NULL;
	stack <string> stsExpression;

public:

	void fnSetExpression(stack <string>);
	void fnCreateTree();
	node* fnGetTree();
	node* fnGetDerivatedTree(node*);
};

