#ifndef _Expr_Node_H_
#define _Expr_Node_H_

#include "Expr_Node_Visitor.h"
#include "Eval_Expr_Tree.h"

class Expr_Node
{
protected:
    int data_;
    friend class TreeBuilder;

public:
    Expr_Node();
    virtual ~Expr_Node();
    virtual void accept(Expr_Node_Visitor &v) = 0;
    virtual int eval(void) = 0;
    virtual int data() const;
    
};

class Unary_Expr_Node : public Expr_Node
{
protected:
    //friend class TreeBuilder;
    Expr_Node *child_;

public:
    Unary_Expr_Node(void);
    virtual ~Unary_Expr_Node(void);
    virtual int eval(void) = 0;
};

class Binary_Expr_Node : public Expr_Node
{
protected:
    //friend class TreeBuilder;
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Binary_Expr_Node(/* args */);
    virtual ~Binary_Expr_Node();
    virtual int eval(void) = 0;
    virtual Expr_Node* left(void) const;
    virtual Expr_Node* right(void) const;
};

class Number_Node : public Expr_Node
{
public:
    Number_Node(int number);
    ~Number_Node();
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

class Add_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Add_Expr_Node(/* args */);
    Add_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Add_Expr_Node();
    virtual Expr_Node* left(void) const;
    virtual Expr_Node* right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

class Subtract_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;
public:
    Subtract_Expr_Node(/* args */);
    Subtract_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Subtract_Expr_Node();
    virtual Expr_Node* left(void) const;
    virtual Expr_Node* right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

class Multiplication_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Multiplication_Expr_Node(/* args */);
    Multiplication_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Multiplication_Expr_Node();
    virtual Expr_Node* left(void) const;
    virtual Expr_Node* right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

class Division_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Division_Expr_Node(/* args */);
    Division_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Division_Expr_Node();
    virtual Expr_Node* left(void) const;
    virtual Expr_Node* right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};

class Modulus_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Modulus_Expr_Node(/* args */);
    Modulus_Expr_Node(Expr_Node *n1, Expr_Node *n2);
    virtual ~Modulus_Expr_Node();
    virtual Expr_Node* left(void) const;
    virtual Expr_Node* right(void) const;
    virtual int eval(void);
    virtual void accept(Expr_Node_Visitor &v);
};
#endif