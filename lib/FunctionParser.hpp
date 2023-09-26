#pragma once
#include <string>
#include <stack>
using namespace std;

class FunctionParser{

private:

	stack <string> values;
	stack <string> operators;
	string expression;
	stack <string> result;
	int getPriority(string);

public:
	
	static bool isOperator(string); // dc am static?
	void setExpression(string);
	void parseExpression();
	stack <string> getExpression();
};