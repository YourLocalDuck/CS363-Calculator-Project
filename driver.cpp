#include "Calculator.h"
#include <iostream>
#include <string>

#include "Expr_Node.h"

int main(int argc, char *argv[])
{
	Calculator calc;

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
		if (calc.insert(exp))
        {
            std::cout << calc.evaluate() << std::endl;
			//calc.getExpression();
        }
        else
        {
            std::cout << "Invalid Expression" << std::endl;
        }
	}

	return 0;
}