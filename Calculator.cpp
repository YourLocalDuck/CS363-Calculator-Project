#include "Calculator.h"
#include "Calculator.inl"

Calculator::Calculator(/* args */)
    : Root(nullptr)
{
}

Calculator::Calculator(std::string expression2)
    : Root(nullptr)
{
    this->expression = expression2;
}

bool Calculator::insert(std::string insertExpression)
{
    expression = insertExpression;
    return true;
}


bool Calculator::parse_expr()
{
    if (expression == "")
        return false;
    expression = infixToPostFix(expression);
    std::istringstream input(expression);
    std::string token;

    while (!input.eof())
    {
        input >> token;
        if (token == "+")
            this->builder.add_operator();
        else if (token == "-")
            this->builder.subtract_operator();
        else if (token == "*")
            this->builder.multiplication_operator();
        else if (token == "/")
            this->builder.division_operator();
        else if (token == "%")
            this->builder.modulus_operator();
        else
        {
            this->builder.build_number(std::stoi(token));
        }
    }
    Root = this->builder.getRoot();
    return true;
}

int Calculator::evaluate()
{
    parse_expr();
    return Root->eval();
}

Calculator::~Calculator()
{
}