#ifndef _EXPR_COMMAND_BASE_H_
#define _EXPR_COMMAND_BASE_H_

#include <stdexcept> // for std::out_of_bounds exception
#include <exception>

class Expr_Command
{
protected:
    int num1;
    int num2;
    int* num3;

public:
    Expr_Command(/* args */);
    ~Expr_Command();
    virtual void execute() = 0;
    virtual int getSol();
};

Expr_Command::Expr_Command(/* args */)
    : num1(0),
      num2(0),
      num3(nullptr)
{
}

Expr_Command::~Expr_Command()
{
}

int Expr_Command::getSol()
{
    if (num3 == nullptr)
    {
        throw std::logic_error("Command Not Executed");
        return;
    }
    return *num3;
}

#endif