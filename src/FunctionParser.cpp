#include "../lib/FunctionParser.hpp"

bool FunctionParser::isOperator(string sArg) {
	return sArg == "+" ||
		sArg == "-" ||
		sArg == "*" ||
		sArg == "/" ||
		sArg == "^";
}

int FunctionParser::getPriority(string sArg) {
	if (sArg == "+" || sArg == "-") return 1;
	if (sArg == "*" || sArg == "/") return 2;
	if (sArg == "^" ) return 3;
	return -1;
}

stack <string> FunctionParser::getExpression(){ 
	return result;
}

void FunctionParser::setExpression(string sArg) { expression = sArg; }

void FunctionParser::parseExpression() {
	for (int i = 0; i < (int)expression.size(); i++) {

		if (expression[i] == '(') operators.push("(");
		else if (expression[i] == ')') {
			while (operators.top() != "(") {
				result.push(operators.top());
				operators.pop();
			}
			operators.pop();
		}
		else if (isOperator(expression.substr(i, 1))) {
			while (!operators.empty() && (getPriority(operators.top()) >= getPriority(expression.substr(i, 1)))) {
				result.push(operators.top());
				operators.pop();
			}
			operators.push(expression.substr(i, 1));
		}
		else {
			string sValue = "";
			while (i < (int)expression.size() && isalnum(expression[i])) {
				sValue += expression[i++];
			}
			--i;
			result.push(sValue);
		}
	}

	while (!operators.empty()) {
		result.push(operators.top());
		operators.pop();
	}
}