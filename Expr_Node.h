#ifndef _Expr_Node_H_
#define _Expr_Node_H_

#include "Expr_Node_Visitor.h"

// COMMENT Separate the class definition and class implementation into
// a header and source file, respectively.
//
// FIX: I've completely redesigned the program from when this comment was made. Class definitions and implementations should be separated.

// Abstract Basic Node. Pure Virtual class.
class Expr_Node
{
protected:
    int data_;

public:
    Expr_Node();
    virtual ~Expr_Node();
    virtual void accept(Expr_Node_Visitor &v) = 0;
    virtual int eval(void) = 0;
    virtual int data() const;
};

// Pure Virtual class for Unary class with one child object.
class Unary_Expr_Node : public Expr_Node
{
protected:
    Expr_Node *child_;

public:
    Unary_Expr_Node(void);
    virtual ~Unary_Expr_Node(void);
    virtual int eval(void) = 0;
};

// Pure Virtual class for Unary class with two child objects.
class Binary_Expr_Node : public Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Binary_Expr_Node(/* args */);
    virtual ~Binary_Expr_Node();
    virtual int eval(void) = 0;
    virtual Expr_Node *left(void) const;
    virtual Expr_Node *right(void) const;
};

// Number Node's main purpose is to hold a int data, and output it when asked.
class Number_Node : public Expr_Node
{
public:
    Number_Node(int number);
    ~Number_Node();
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

// Add_Expr_Node's function is to add its children together recursively when asked.
class Add_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Add_Expr_Node(/* args */);
    Add_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Add_Expr_Node();
    virtual Expr_Node *left(void) const;
    virtual Expr_Node *right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

// Add_Expr_Node's function is to subtract its left child buy its right child recursively when asked.
class Subtract_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Subtract_Expr_Node(/* args */);
    Subtract_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Subtract_Expr_Node();
    virtual Expr_Node *left(void) const;
    virtual Expr_Node *right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

// Add_Expr_Node's function is to multiply its children together recursively when asked.
class Multiplication_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Multiplication_Expr_Node(/* args */);
    Multiplication_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Multiplication_Expr_Node();
    virtual Expr_Node *left(void) const;
    virtual Expr_Node *right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

// Add_Expr_Node's function is to divide its left child buy its right child recursively when asked.
class Division_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Division_Expr_Node(/* args */);
    Division_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Division_Expr_Node();
    virtual Expr_Node *left(void) const;
    virtual Expr_Node *right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

// Add_Expr_Node's function is to modulo its left child buy its right child recursively when asked.
class Modulus_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Modulus_Expr_Node(/* args */);
    Modulus_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Modulus_Expr_Node();
    virtual Expr_Node *left(void) const;
    virtual Expr_Node *right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};
#endif
