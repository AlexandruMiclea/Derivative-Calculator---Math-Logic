#pragma once
#include <string>
#include <stack>
using namespace std;

class FunctionParser{

private:

	//variables
	stack <string> stValues;
	stack <string> stOperators;
	string sExpression, sReturnExpression;

	//function declarations
	bool bfnIsOperator(string);
	int ifnPriority(string);

public:
	
	void fnSetExpression(string);
	void fnParseExpression();
	string sfnGetExpression();
};

