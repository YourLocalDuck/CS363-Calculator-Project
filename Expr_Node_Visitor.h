#ifndef _Expr_Node_VISITOR_H_
#define _Expr_Node_VISITOR_H_

class Expr_Node;
class Add_Expr_Node;
class Subtract_Expr_Node;
class Multiplication_Expr_Node;
class Division_Expr_Node;
class Modulus_Expr_Node;
class Number_Node;
// Forward declaring these concrete classes to avoid circular dependency.

// Class Expr_Node_Visitor is a pure virtual class used to implement the visitor pattern to evaluate or traverse an expression tree.
class Expr_Node_Visitor
{
public:
    virtual ~Expr_Node_Visitor() {}
    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node(const Add_Expr_Node &node) = 0;
    virtual void Visit_Subtraction_Node(const Subtract_Expr_Node &node) = 0;
    virtual void Visit_Multiplication_Node(const Multiplication_Expr_Node &node) = 0;
    virtual void Visit_Division_Node(const Division_Expr_Node &node) = 0;
    virtual void Visit_Modulus_Node(const Modulus_Expr_Node &node) = 0;
    virtual void Visit_Number_Node(const Number_Node &node) = 0;
    // ...
};

#endif