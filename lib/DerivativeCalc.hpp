#pragma once
#include <string>
#include "ExpressionTree.hpp"
using namespace std;

class DerivativeCalc {
private:
	bool bfnIsOperator(string);
	bool bfnIsNumber(string);

public:
	
	node* fnGetDerivatedTree(node*);

};

