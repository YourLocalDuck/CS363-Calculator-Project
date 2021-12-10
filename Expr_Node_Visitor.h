#include "Expr_Node.h"

class Expr_Node_Visitor
{
public:
    Expr_Node_Visitor(/* args */);
    virtual ~Expr_Node_Visitor();

    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node (const Add_Expr_Node & node);
    virtual void Visit_Subtraction_Node (const Subtract_Expr_Node & node);
    virtual void Visit_Number_Node (const Number_Node & node);
};

