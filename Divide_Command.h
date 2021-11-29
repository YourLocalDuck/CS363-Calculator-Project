#ifndef _DIV_COMMAND_H_
#define _DIV_COMMAND_H_

#include "Expr_Command.h"

class Divide_Command : public Expr_Command
{
private:
    /* data */
public:
    Divide_Command(int n1, int n2);
    ~Divide_Command();
    void execute();
};

Divide_Command::Divide_Command(int n1, int n2)
{
    num1 = n1;
    num2 = n2;
}

Divide_Command::~Divide_Command()
{
}

void Divide_Command::execute()
{
    *num3 = num1/num2;
}

#endif