#ifndef _MULT_COMMAND_H_
#define _MULT_COMMAND_H_

#include "Expr_Command.h"

class Multiply_Command : public Expr_Command
{
private:
    /* data */
public:
    Multiply_Command(int n1, int n2);
    ~Multiply_Command();
    void execute();
};

Multiply_Command::Multiply_Command(int n1, int n2)
{
    num1 = n1;
    num2 = n2;
}

Multiply_Command::~Multiply_Command()
{
}

void Multiply_Command::execute()
{
    *num3 = num1*num2;
}

#endif