#pragma once
#include <string>
using namespace std;

class ExpressionTree{

private:
	struct node {
		string sData;
		node* pRight,* pLeft;
	};

	struct node* fnCreateNode();
public:

};

