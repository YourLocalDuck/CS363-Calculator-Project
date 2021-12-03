#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Expr_Command.h"

// COMMENT Separate the class definition and class implementation into
// a header and source file, respectively.

class Add_Command : public Expr_Command
{
private:
    /* data */
public:
    Add_Command(int n1, int n2);
    ~Add_Command();
    void execute();
};

Add_Command::Add_Command(int n1, int n2)
{
    num1 = n1;
    num2 = n2;
}

Add_Command::~Add_Command()
{
}

void Add_Command::execute()
{
    *num3 = num1+num2;
}

#endif
