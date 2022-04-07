#pragma once
#include <string>
#include <stack>
using namespace std;

struct node {
	string sData;
	node *pRight, *pLeft, *pDad;
};

class ExpressionTree{

private:
	node *Tree = NULL, *head = NULL;
	stack <string> stsExpression;
	bool bfnIsOperator(string);

public:

	void fnSetExpression(stack <string>);
	void fnCreateTree();
	node* fnGetTree();
};

