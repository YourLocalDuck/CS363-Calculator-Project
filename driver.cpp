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
        }
        else
        {
            std::cout << "Invalid Expression" << std::endl;
        }
	}

	int p[123] = {0};
	p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
    p[')'] = 0;
	
	return 0;
}