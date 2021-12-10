#include "Expr_Node.h"

// START EXPR_NODE CLASS
Expr_Node::Expr_Node()
    : data(0)
{
}

Expr_Node::~Expr_Node()
{
}

// START UNARY_EXPR_NODE CLASS

Unary_Expr_Node::Unary_Expr_Node()
    : child_(nullptr)
{
}

Unary_Expr_Node::~Unary_Expr_Node()
{
    delete child_;
}

/*int Unary_Expr_Node::eval(void)
{
    if (this->child_ != nullptr)
        return this->child_->eval();
}*/

// START BINARY_EXPR_NODE
Binary_Expr_Node::Binary_Expr_Node()
    : right_(nullptr),
      left_(nullptr)
{
}

Binary_Expr_Node::~Binary_Expr_Node()
{
    delete right_;
    delete left_;
}

//START NUMBER_NODE
Number_Node::Number_Node(int number)
{
    data = number;
}

Number_Node::~Number_Node()
{
}

int Number_Node::eval(void)
{
    return data;
}

// START ADD_EXPR_NODE
Add_Expr_Node::Add_Expr_Node()
    : left_(nullptr),
      right_(nullptr)
{
}

Add_Expr_Node::Add_Expr_Node(Expr_Node *n1, Expr_Node *n2)
{
    left_ = n1;
    right_ = n2;
}

Add_Expr_Node::~Add_Expr_Node()
{
}

int Add_Expr_Node::eval(void)
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() + right_->eval());
    }
    return -1;
}

// START SUBTRACT_EXPR_NODE
Subtract_Expr_Node::Subtract_Expr_Node()
    : left_(nullptr),
      right_(nullptr)
{
}

Subtract_Expr_Node::Subtract_Expr_Node(Expr_Node *n1, Expr_Node *n2)
{
    left_ = n1;
    right_ = n2;
}

Subtract_Expr_Node::~Subtract_Expr_Node()
{
}

int Subtract_Expr_Node::eval()
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() - right_->eval());
    }
    return -1;
}

// START MULTIPLICATION_EXPR_NODE
Multiplication_Expr_Node::Multiplication_Expr_Node()
    :left_(nullptr),
     right_(nullptr)
{
}

Multiplication_Expr_Node::Multiplication_Expr_Node(Expr_Node *n1, Expr_Node *n2)
{
    left_ = n1;
    right_ = n2;
}

Multiplication_Expr_Node::~Multiplication_Expr_Node()
{
}

int Multiplication_Expr_Node::eval()
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() * right_->eval());
    }
    return -1;
}

// START DIVISION_EXPR_NODE
Division_Expr_Node::Division_Expr_Node()
    :left_(nullptr),
     right_(nullptr)
{
}

Division_Expr_Node::Division_Expr_Node(Expr_Node *n1, Expr_Node *n2)
{
    left_ = n1;
    right_ = n2;
}

Division_Expr_Node::~Division_Expr_Node()
{
}

int Division_Expr_Node::eval()
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() / right_->eval());
    }
    return -1;
}

// START MODULUS_EXPR_NODE
Modulus_Expr_Node::Modulus_Expr_Node()
    :left_(nullptr),
     right_(nullptr)
{
}

Modulus_Expr_Node::Modulus_Expr_Node(Expr_Node *n1, Expr_Node *n2)
{
    left_ = n1;
    right_ = n2;
}

Modulus_Expr_Node::~Modulus_Expr_Node()
{
}

int Modulus_Expr_Node::eval()
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() % right_->eval());
    }
    return -1;
}