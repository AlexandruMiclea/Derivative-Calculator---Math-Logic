#pragma once
#include <string>
#include <vector>
using namespace std;

struct node {
	string sData;
	node* pRight, * pLeft;
};

class ExpressionTree{

private:
	//variables
	
	node Tree;
	string sExpression;

protected:

	
public:
	void fnSetExpression(string);
	bool bfnIsOperator(string);
	void fnCreateTree();
	node* createNode(string);
	void fnGetTree();
};

