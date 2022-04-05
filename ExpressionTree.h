#pragma once
#include <string>
#include <stack>
using namespace std;

struct node {
	string sData;
	node* pRight, * pLeft;
};

class ExpressionTree{

private:
	//variables
	
	node Tree;
	stack <string> stsExpression;

protected:

	
public:
	void fnSetExpression(stack <string>);
	bool bfnIsOperator(string);
	void fnCreateTree();
	node* createNode(string);
	void fnGetTree();
};

