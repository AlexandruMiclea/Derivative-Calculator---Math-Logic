#pragma once
#include <string>
#include <stack>
using namespace std;

class FunctionParser{

private:

	stack <string> stValues;
	stack <string> stOperators;
	string sExpression;
	stack <string> stsReturn;

	bool bfnIsOperator(string);
	int ifnPriority(string);

public:
	
	void fnSetExpression(string);
	void fnParseExpression();
	stack <string> sfnGetExpression();
};

