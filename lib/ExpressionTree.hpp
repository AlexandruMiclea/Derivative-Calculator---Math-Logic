#pragma once
#include <string>
#include <stack>
using namespace std;

typedef struct node {
	string sData;
	node *pRight = NULL, *pLeft = NULL, *pDad = NULL;
} node;

class ExpressionTree{

private:
	node *Tree = NULL, *head = NULL;
	stack <string> expression;

public:

	void setExpression(stack <string>);
	void createTree();
	node* getTree();
	node* getDerivedTree(node*);
	string printTree(node*);
};