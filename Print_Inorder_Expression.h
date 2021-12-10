#ifndef _Print_Inorder_Exp_H_
#define _Print_Inorder_Exp_H_

#include <fstream>
#include "Expr_Node_Visitor.h"

// This class is just Eval_Expr_Tree, but it is In order instead of post order, and instead of evaluating, it will just output the tree recursively.
class Print_Inorder_Expression : public Expr_Node_Visitor
{
public:
    Print_Inorder_Expression();
    virtual ~Print_Inorder_Expression(void);
    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node(const Add_Expr_Node &node);
    virtual void Visit_Subtraction_Node(const Subtract_Expr_Node &node);
    virtual void Visit_Multiplication_Node(const Multiplication_Expr_Node &node);
    virtual void Visit_Division_Node(const Division_Expr_Node &node);
    virtual void Visit_Modulus_Node(const Modulus_Expr_Node &node);
    virtual void Visit_Number_Node(const Number_Node &node);
    // ...
};

#endif