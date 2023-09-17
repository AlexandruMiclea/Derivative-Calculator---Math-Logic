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
	int ifnPriority(string);

public:
	
	static bool bfnIsOperator(string);
	void fnSetExpression(string);
	void fnParseExpression();
	stack <string> sfnGetExpression();
};

