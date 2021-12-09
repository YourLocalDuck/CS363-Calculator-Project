#ifndef _Expr_Node_H_
#define _Expr_Node_H_

class Expr_Node
{
protected:
    int data;
    int priority;
    friend class TreeBuilder;

public:
    Expr_Node();
    virtual ~Expr_Node();
    virtual int eval(void) = 0;
    virtual bool openChild(void);
    virtual bool insert(int childnum, Expr_Node *newChild);
};

class Unary_Expr_Node : public Expr_Node
{
protected:
    friend class TreeBuilder;
    Expr_Node *child_;

public:
    Unary_Expr_Node(void);
    virtual ~Unary_Expr_Node(void);
    virtual int eval(void) = 0;
    virtual bool openChild(void);
    virtual bool insert(int childnum, Expr_Node *newChild);;
};

class Binary_Expr_Node : public Expr_Node
{
protected:
    friend class TreeBuilder;
    Expr_Node *right_;
    Expr_Node *left_;

public:
    Binary_Expr_Node(/* args */);
    virtual ~Binary_Expr_Node();
    virtual int eval(void) = 0;
    virtual bool openChild(void);
    virtual bool insert(int childnum, Expr_Node *newChild);;
};

class Number_Node : public Expr_Node
{
public:
    Number_Node(int number);
    ~Number_Node();
    virtual int eval(void);
};

class Add_Expr_Node : public Binary_Expr_Node
{
protected:
    Expr_Node *right_;
    Expr_Node *left_;
    int priority;
    friend class TreeBuilder;

public:
    Add_Expr_Node(/* args */);
    Add_Expr_Node(Expr_Node* n1, Expr_Node* n2);
    virtual ~Add_Expr_Node();
    virtual int eval(void);
};
#endif