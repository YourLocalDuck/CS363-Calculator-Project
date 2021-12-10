#include "Eval_Expr_Tree.h"
#include "Expr_Node.h"

Eval_Expr_Tree::Eval_Expr_Tree(void)
    : result_(0)
{
}

Eval_Expr_Tree::~Eval_Expr_Tree(void)
{
}

void Eval_Expr_Tree::Visit_Addition_Node(const Add_Expr_Node &node)
{
    // visit left node, visit right node, then perform addition
    node.left()->accept(*this);
    int n1 = result_;
    node.right()->accept(*this);
    int n2 = result_;
    result_ = n1 + n2;
}

void Eval_Expr_Tree::Visit_Subtraction_Node(const Subtract_Expr_Node &node)
{
    // visit left node, visit right node, then perform subtraction
    node.left()->accept(*this);
    int n1 = result_;
    node.right()->accept(*this);
    int n2 = result_;
    result_ = n1 - n2;
}

void Eval_Expr_Tree::Visit_Multiplication_Node(const Multiplication_Expr_Node &node)
{
    // visit left node, visit right node, then perform multiplication
    node.left()->accept(*this);
    int n1 = result_;
    node.right()->accept(*this);
    int n2 = result_;
    result_ = n1 * n2;
}

void Eval_Expr_Tree::Visit_Division_Node(const Division_Expr_Node &node)
{
    // visit left node, visit right node, then perform multiplication
    node.left()->accept(*this);
    int n1 = result_;
    node.right()->accept(*this);
    int n2 = result_;
    result_ = n1 / n2;
}

void Eval_Expr_Tree::Visit_Modulus_Node(const Modulus_Expr_Node &node)
{
    // visit left node, visit right node, then perform multiplication
    node.left()->accept(*this);
    int n1 = result_;
    node.right()->accept(*this);
    int n2 = result_;
    result_ = n1 % n2;
}

void Eval_Expr_Tree::Visit_Number_Node(const Number_Node &node)
{
    // Just send data
    result_ = node.data();
}