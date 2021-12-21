#pragma once
#include <string>
#include <stack>
using namespace std;

class FunctionParser{

private:

	//function declarations
	bool bfnIsOperator(string);
	int ifnPriority(string);

public:
	void fnSetExpression(string);
	void fnParseExpression();
	string sfnGetExpression();
};

