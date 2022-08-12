#include "DerivativeCalc.h"

bool DerivativeCalc::bfnIsOperator(string sArg){
	return sArg == "+" ||
		sArg == "-" ||
		sArg == "*" ||
		sArg == "/" ||
		sArg == "^";
}

node* DerivativeCalc::fnGetDerivatedTree()
{
	return nullptr;
}
