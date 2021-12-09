#include "Calculator.h"

Calculator::Calculator(/* args */)
:Root(nullptr)
{
}

Calculator::Calculator(std::string expression2)
:Root(nullptr)
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
    std::istringstream input(expression);
    std::string token;
    int number;

    //builder.start_expression();

    while (!input.eof())
    {
        input >> token;
        if (token == "+")
            this->builder.add_operator();
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