#ifndef CALCULATOR_H_EXISTS
#define CALCULATOR_H_EXISTS

#include <string>
#include <sstream>
#include "TreeBuilder.h"

class Calculator
{
private:
    TreeBuilder builder;
    std::string expression;
    bool parse_expr();
    void cleanUp(void);
    Expr_Node* Root;
   // bool expressionExists;
public:
    Calculator(/* args */);
    Calculator(std::string expression);
    ~Calculator();
    bool insert(std::string insertExpression);
    int evaluate(void);
};

#endif