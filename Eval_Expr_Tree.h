#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:
    Eval_Expr_Tree(void);
    virtual ~Eval_Expr_Tree(void);
    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node(Add_Expr_Node &node)
    {
        // visit left node, visit right node, then perform addition
        node.accept(this);
        
    }
    virtual void Visit_Subtraction_Node(const Subtract_Expr_Node &node);
    virtual void Visit_Number_Node(const Number_Node &node);
    // ...
    int result(void) const { return this->result_; }

private:
    int result_;
    // other state for calculating result
};