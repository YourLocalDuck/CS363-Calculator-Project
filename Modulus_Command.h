#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Expr_Command.h"

// COMMENT Separate the class definition and class implementation into
// a header and source file, respectively.

class Modulus_Command : public Expr_Command
{
private:
    /* data */
public:
    Modulus_Command(int n1, int n2);
    ~Modulus_Command();
    void execute();
};

Modulus_Command::Modulus_Command(int n1, int n2)
{
    num1 = n1;
    num2 = n2;
}

Modulus_Command::~Modulus_Command()
{
}

void Modulus_Command::execute()
{
    *num3 = num1%num2;
}

#endif
