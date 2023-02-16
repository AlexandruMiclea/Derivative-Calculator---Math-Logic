#pragma once
#include <string>
#include "ExpressionTree.h"
using namespace std;

class DerivativeCalc {
private:
	bool bfnIsOperator(string);
	bool bfnIsNumber(string);

public:
	
	node* fnGetDerivatedTree(node*);

};

