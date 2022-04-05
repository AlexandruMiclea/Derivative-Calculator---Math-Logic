#pragma once
#include <string>
#include <stack>
#include <vector>

using namespace std;

class FunctionParser{

private:

	//variables
	stack <string> stValues;
	stack <string> stOperators;
	string sExpression;
	vector <string> vsReturn;

	//function declarations
	bool bfnIsOperator(string);
	int ifnPriority(string);

public:
	
	void fnSetExpression(string);
	void fnParseExpression();
	vector <string> sfnGetExpression();
};

