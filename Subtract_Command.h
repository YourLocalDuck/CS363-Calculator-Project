#ifndef _SUB_COMMAND_H_
#define _SUB_COMMAND_H_

#include "Expr_Command.h"

class Subtract_Command : public Expr_Command
{
private:
    /* data */
public:
    Subtract_Command(int n1, int n2);
    ~Subtract_Command();
    void execute();
};

Subtract_Command::Subtract_Command(int n1, int n2)
{
    num1 = n1;
    num2 = n2;
}

Subtract_Command::~Subtract_Command()
{
}

void Subtract_Command::execute()
{
    *num3 = num1-num2;
}

#endif