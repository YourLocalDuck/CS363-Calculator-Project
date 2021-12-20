#include "Print_Inorder_Expression.h"
#include "Expr_Node.h"
#include <iostream>

Print_Inorder_Expression::Print_Inorder_Expression()
{
}

Print_Inorder_Expression::~Print_Inorder_Expression()
{
}

void Print_Inorder_Expression::Visit_Addition_Node(const Add_Expr_Node &node)
{
    node.left()->accept(*this);
    std::cout << " + ";
    node.right()->accept(*this);
}

void Print_Inorder_Expression::Visit_Subtraction_Node(const Subtract_Expr_Node &node)
{
    node.left()->accept(*this);
    std::cout << " - ";
    node.right()->accept(*this);
}

void Print_Inorder_Expression::Visit_Multiplication_Node(const Multiplication_Expr_Node &node)
{
    node.left()->accept(*this);
    std::cout << " * ";
    node.right()->accept(*this);
}

void Print_Inorder_Expression::Visit_Division_Node(const Division_Expr_Node &node)
{
    node.left()->accept(*this);
    std::cout << " / ";
    node.right()->accept(*this);
}

void Print_Inorder_Expression::Visit_Modulus_Node(const Modulus_Expr_Node &node)
{
    node.left()->accept(*this);
    std::cout << " % ";
    node.right()->accept(*this);
}

void Print_Inorder_Expression::Visit_Number_Node(const Number_Node &node)
{
    std::cout << node.data();
}
