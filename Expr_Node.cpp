#include "Expr_Node.h"

// START EXPR_NODE CLASS.
// Abstract Basic Node. Pure Virtual class.
Expr_Node::Expr_Node()
    : data_(0)
{
}

Expr_Node::~Expr_Node()
{
}

int Expr_Node::data() const
{
    return data_;
}

// START UNARY_EXPR_NODE CLASS
// Pure Virtual class for Unary class with one child object.
Unary_Expr_Node::Unary_Expr_Node()
    : child_(nullptr)
{
}

Unary_Expr_Node::~Unary_Expr_Node()
{
    if (child_ != nullptr)
    {
        delete child_;
        child_ = nullptr;
    }
}

int Unary_Expr_Node::eval(void)
{
    if (this->child_ != nullptr)
        return this->child_->eval();
}

// START BINARY_EXPR_NODE
// Pure Virtual class for Unary class with two child objects.
Binary_Expr_Node::Binary_Expr_Node()
    : right_(nullptr),
      left_(nullptr)
{
}

Binary_Expr_Node::~Binary_Expr_Node()
{
    if (left_ != nullptr)
    {
        delete left_;
        left_ = nullptr;
    }
    if (right_ != nullptr)
    {
        delete right_;
        right_ = nullptr;
    }
}

Expr_Node *Binary_Expr_Node::left() const
{
    return left_;
}

Expr_Node *Binary_Expr_Node::right() const
{
    return right_;
}

//START NUMBER_NODE
// Number Node's main purpose is to hold a int data, and output it when asked.
Number_Node::Number_Node(int number)
{
    data_ = number;
}

Number_Node::~Number_Node()
{
}

int Number_Node::eval(void)
{
    return data_;
}

void Number_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Number_Node(*this);
}

// START ADD_EXPR_NODE
// Add_Expr_Node's function is to add its children together recursively when asked.
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
    if (left_ != nullptr)
    {
        delete left_;
        left_ = nullptr;
    }
    if (right_ != nullptr)
    {
        delete right_;
        right_ = nullptr;
    }
}

Expr_Node *Add_Expr_Node::left() const
{
    return left_;
}

Expr_Node *Add_Expr_Node::right() const
{
    return right_;
}

int Add_Expr_Node::eval(void)
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() + right_->eval());
    }
    return -1;
}

void Add_Expr_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Addition_Node(*this);
}

// START SUBTRACT_EXPR_NODE
// Add_Expr_Node's function is to subtract its left child buy its right child recursively when asked.
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
    if (left_ != nullptr)
    {
        delete left_;
        left_ = nullptr;
    }
    if (right_ != nullptr)
    {
        delete right_;
        right_ = nullptr;
    }
}

Expr_Node *Subtract_Expr_Node::left() const
{
    return left_;
}

Expr_Node *Subtract_Expr_Node::right() const
{
    return right_;
}

int Subtract_Expr_Node::eval()
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() - right_->eval());
    }
    return -1;
}

void Subtract_Expr_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Subtraction_Node(*this);
}

// START MULTIPLICATION_EXPR_NODE
// Add_Expr_Node's function is to multiply its children together recursively when asked.
Multiplication_Expr_Node::Multiplication_Expr_Node()
    : left_(nullptr),
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
    if (left_ != nullptr)
    {
        delete left_;
        left_ = nullptr;
    }
    if (right_ != nullptr)
    {
        delete right_;
        right_ = nullptr;
    }
}

Expr_Node *Multiplication_Expr_Node::left() const
{
    return left_;
}

Expr_Node *Multiplication_Expr_Node::right() const
{
    return right_;
}

int Multiplication_Expr_Node::eval()
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() * right_->eval());
    }
    return -1;
}

void Multiplication_Expr_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Multiplication_Node(*this);
}

// START DIVISION_EXPR_NODE
// Add_Expr_Node's function is to divide its left child buy its right child recursively when asked.
Division_Expr_Node::Division_Expr_Node()
    : left_(nullptr),
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
    if (left_ != nullptr)
    {
        delete left_;
        left_ = nullptr;
    }
    if (right_ != nullptr)
    {
        delete right_;
        right_ = nullptr;
    }
}

Expr_Node *Division_Expr_Node::left() const
{
    return left_;
}

Expr_Node *Division_Expr_Node::right() const
{
    return right_;
}

int Division_Expr_Node::eval()
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() / right_->eval());
    }
    return -1;
}

void Division_Expr_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Division_Node(*this);
}

// START MODULUS_EXPR_NODE
// Add_Expr_Node's function is to modulo its left child buy its right child recursively when asked.
Modulus_Expr_Node::Modulus_Expr_Node()
    : left_(nullptr),
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
    if (left_ != nullptr)
    {
        delete left_;
        left_ = nullptr;
    }
    if (right_ != nullptr)
    {
        delete right_;
        right_ = nullptr;
    }
}

Expr_Node *Modulus_Expr_Node::left() const
{
    return left_;
}

Expr_Node *Modulus_Expr_Node::right() const
{
    return right_;
}

int Modulus_Expr_Node::eval()
{
    if (left_ != nullptr && right_ != nullptr)
    {
        return (left_->eval() % right_->eval());
    }
    return -1;
}

void Modulus_Expr_Node::accept(Expr_Node_Visitor &v)
{
    v.Visit_Modulus_Node(*this);
}