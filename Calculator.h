#ifndef CALCULATOR_H_EXISTS
#define CALCULATOR_H_EXISTS

#include <string>
#include <sstream>
#include "TreeBuilder.h"
#include "Print_Inorder_Expression.h"
#include "Eval_Expr_Tree.h"

class Calculator
{
private:
    TreeBuilder builder; // Builder Pattern
    std::string expression;
    bool parse_expr();
    Expr_Node *Root;
    Eval_Expr_Tree eval; // Composite and Visitor Pattern
    Print_Inorder_Expression IOExp;

public:
    Calculator(/* args */);
    Calculator(std::string expression);
    ~Calculator();
    bool insert(std::string insertExpression);
    int evaluate(void);
    void getExpression(void);
};

#endif