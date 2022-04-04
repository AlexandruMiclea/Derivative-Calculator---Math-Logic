#include "FunctionParser.h"


bool FunctionParser::bfnIsOperator(string sArg) {
	return sArg == "+" ||
		sArg == "-" ||
		sArg == "*" ||
		sArg == "/" ||
		sArg == "^";
}

int FunctionParser::ifnPriority(string sArg) {
	if (sArg == "+" || sArg == "-") return 1;
	if (sArg == "*" || sArg == "/") return 2;
	if (sArg == "^" ) return 3;
	return -1;
}

string FunctionParser::sfnGetExpression(){ 
	reverse(sReturnExpression.begin(), sReturnExpression.end());
	return sReturnExpression;
}

void FunctionParser::fnSetExpression(string sArg) { sExpression = sArg; }

void FunctionParser::fnParseExpression() {
	for (int i = 0; i < (int)sExpression.size(); i++) {

		if (sExpression[i] == '(') stOperators.push("(");
		else if (sExpression[i] == ')') {
			while (stOperators.top() != "(") {
				sReturnExpression += stOperators.top();
				stOperators.pop();
			}
			stOperators.pop();
		}
		else if (bfnIsOperator(sExpression.substr(i, 1))) {
			while (!stOperators.empty() && (ifnPriority(stOperators.top()) >= ifnPriority(sExpression.substr(i, 1)))) {
				sReturnExpression += stOperators.top();
				stOperators.pop();
			}
			stOperators.push(sExpression.substr(i, 1));
		}
		else {
			string sValue = "";
			while (i < (int)sExpression.size() && isalnum(sExpression[i])) {
				 sValue += sExpression[i++];
			}
			--i;
			sReturnExpression += sValue;
		}
	}

	while (!stOperators.empty()) {
		sReturnExpression += stOperators.top();
		stOperators.pop();
	}
}



