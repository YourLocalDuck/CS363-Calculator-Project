#include "Calculator.h"
#include "Calculator.inl"
#include <iostream>

Calculator::Calculator(/* args */)
    : Root(nullptr)
{
}

Calculator::Calculator(std::string expression2)
    : Root(nullptr)
{
    this->expression = expression2;
}

bool Calculator::insert(std::string insertExpression) // Check for empty string. Expression is so far infix.
{
    if (insertExpression == "")
        return false;
    expression = insertExpression;
    return true;
}

bool Calculator::parse_expr()
{
    expression = infixToPostFix(expression); // This will use a priority system and method found in Calculator.inl to convert existing Infix expression to postfix, since postfix is more straightforward to build a tree with.
    std::istringstream input(expression);
    std::string token;

    while (!input.eof()) // for each token in postfix expression
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
    if (Root != nullptr)
        delete Root;
    parse_expr();               // Build tree and update this->root
    Root->accept(eval);         // Using visitor pattern to traverse the tree in a post order fashion.
    int result = eval.result(); // Final result of tree
    return result;
    //return Root->eval(); // Composite pattern to evauluate the tree in post order
}

void Calculator::getExpression() // Print tree In Order
{
    Root->accept(IOExp);
    std::cout << std::endl;
}

Calculator::~Calculator()
{
    if (Root != nullptr)
        delete Root;
}