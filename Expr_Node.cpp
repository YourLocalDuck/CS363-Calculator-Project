#include "Expr_Node.h"

// START EXPR_NODE CLASS
Expr_Node::Expr_Node()
:data(0),
priority(0)
{
}

Expr_Node::~Expr_Node()
{
}

bool Expr_Node::openChild()
{
    return false;
}

bool Expr_Node::insert(int childnum, Expr_Node *newChild)
{
    return false;
}

// START UNARY_EXPR_NODE CLASS

Unary_Expr_Node::Unary_Expr_Node()
:child_(nullptr)
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

bool Unary_Expr_Node::openChild()
{
    if (child_ == nullptr)
    {
        return true;
    }
    return false;
}

bool Unary_Expr_Node::insert(int childnum, Expr_Node *newChild)
{
    switch (childnum)
    {
    case 1:
        child_ = newChild;
        return true;
        break;
    
    default:
        return false;
        break;
    }
}

// START BINARY_EXPR_NODE
Binary_Expr_Node::Binary_Expr_Node()
:right_(nullptr),
left_(nullptr)
{
}

Binary_Expr_Node::~Binary_Expr_Node()
{
    delete right_;
    delete left_;
}

bool Binary_Expr_Node::openChild()
{
    if (right_ == nullptr || left_ == nullptr)
    {
        return true;
    }
    return false;
}

bool Binary_Expr_Node::insert(int childnum, Expr_Node *newChild)
{
    switch (childnum)
    {
    case 1:
        left_ = newChild;
        return true;
        break;
    case 2:
        right_ = newChild;
        return true;
        break;
    default:
        return false;
        break;
    }
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
:left_(nullptr),
right_(nullptr),
priority(1)
{
}

Add_Expr_Node::Add_Expr_Node(Expr_Node* n1, Expr_Node* n2)
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
