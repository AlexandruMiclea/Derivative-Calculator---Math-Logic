#pragma once
#include <string>
#include <stack>
using namespace std;

class FunctionParser{

private:

	//variables
	stack <string> stValues;
	stack <string> stOperators;
	string sExpression;
	stack <string> stsReturn;

	//function declarations
	bool bfnIsOperator(string);
	int ifnPriority(string);

public:
	
	void fnSetExpression(string);
	void fnParseExpression();
	stack <string> sfnGetExpression();
};

