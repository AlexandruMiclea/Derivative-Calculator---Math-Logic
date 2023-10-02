#pragma once
#include <string>
#include "ExpressionTree.hpp"
using namespace std;

class DerivativeCalc {
private:
	bool isOperator(string);
	bool isNumber(string);
public:
	node* deriveTree(node*);
};