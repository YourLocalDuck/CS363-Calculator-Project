#include "Stack.h"
#include "Queue.h"
#include "Fixed_Array.h"
#include <iostream>
#include <string>

// COMMENT This is considered an incomplete solution. You are supposed to be
// going from infix to tree, and then solving the tree using the visitor pattern.
// From what I see, you are using the approach in assignment 3.

int priority(char op)
{
	switch (op)
	{
	case '+':
		return 0;
		break;
	case '-':
		return 0;
		break;
	case '*':
		return 1;
		break;
	case '/':
		return 1;
		break;
	case '%':
		return 1;
		break;
	case '^':
		return 2;
		break;
	default:
		return -1;
		break;
	}
}

std::string infixToPostFix(std::string s)
{
	std::string pfExpression;
	Stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		char op = s[i];

		if ((op >= '0' && op <= '9'))
			pfExpression += op;
		else if (op == '(')
		{
			st.push('(');
		}
		else if (op == ')')
		{
			while (st.top() != '(')
			{
				pfExpression += st.top();
				st.pop();
			}
			st.pop();
		}

		else
		{
			while (st.is_empty() == false && priority(s[i]) <= priority(st.top()))
			{
				pfExpression += st.top();
				st.pop();
			}
			st.push(op);
		}
	}
	while (!st.is_empty())
	{
		pfExpression += st.top();
		st.pop();
	}

	return pfExpression;
}

int solvePostFixExp(std::string pfExpression)
{
	Stack<int> solveStack;
	for (int i = 0; i < pfExpression.length(); i++)
	{
		if (pfExpression[i] == ' ')
		{
		}
		else if (pfExpression[i] >= '0' && pfExpression[i] <= '9')
		{
			int num = (int)(pfExpression[i] - '0');

			solveStack.push(num);
		}
		else
		{
			if (solveStack.is_empty())
				return -1;
			int operand1 = solveStack.top();
			solveStack.pop();
			if (solveStack.is_empty())
				return -1;
			int operand2 = solveStack.top();
			solveStack.pop();

			switch (pfExpression[i])
			{
			case '+':
				solveStack.push(operand1 + operand2);
				break;
			case '-':
				solveStack.push(operand1 - operand2);
				break;
			case '*':
				solveStack.push(operand1 * operand2);
				break;
			case '/':
				solveStack.push(operand1 / operand2);
				break;
			case '%':
				solveStack.push(operand1 % operand2);
				break;
			default:
				break;
			}
		}
	}
	return solveStack.top();
	solveStack.pop();
}

int solveInfixExpression(std::string ifExpression)
{
	std::string pfExpression = infixToPostFix(ifExpression);
	int solution = solvePostFixExp(pfExpression);
	return solution;
}

int main(int argc, char *argv[])
{
	std::string exp;
	bool keepGoing = true;
	while (keepGoing)
	{
		std::cout << "Please enter expression: ";
		std::getline(std::cin, exp);
		if (exp == "QUIT")
		{
			keepGoing = false;
			break;
		}
		int output = solveInfixExpression(exp);
		std::cout << output << std::endl;
	}
	return 0;
}
