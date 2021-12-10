#ifndef _Expr_Node_Tree_H_
#define _Expr_Node_Tree_H_

#include "Expr_Node_Visitor.h"

// This class uses the Visitor Design pattern to recursively do whatever operation corresponds to the node type to its children and return the result upwards. In the case of Number Node, its only job is to send its own data upwards so that the higher operators can work with it.
class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:
    Eval_Expr_Tree(void);
    virtual ~Eval_Expr_Tree(void);
    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node(const Add_Expr_Node &node);
    virtual void Visit_Subtraction_Node(const Subtract_Expr_Node &node);
    virtual void Visit_Multiplication_Node(const Multiplication_Expr_Node &node);
    virtual void Visit_Division_Node(const Division_Expr_Node &node);
    virtual void Visit_Modulus_Node(const Modulus_Expr_Node &node);
    virtual void Visit_Number_Node(const Number_Node &node);
    // ...
    int result(void) const { return this->result_; }

private:
    int result_;
    // other state for calculating result
};

#endif