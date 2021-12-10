#ifndef TREEBUILDER_H_EXISTS
#define TREEBUILDER_H_EXISTS

#include "Expr_Node.h"
#include <string>
#include "Stack.h"

#define maxDigits 9

class TreeBuilder
{
protected:
    Expr_Node* Root;
    Stack<Expr_Node*> TreeHelper;
    void switchNodes(Expr_Node* node1, Expr_Node* node2);
    
public:
    TreeBuilder();
    ~TreeBuilder();
    virtual Expr_Node* getRoot();
    //virtual void start_expression(void);
    virtual void build_number(int value);
    virtual void add_operator(void);
    virtual void subtract_operator(void);
    virtual void multiplication_operator(void);
    virtual void division_operator(void);
    virtual void modulus_operator(void);

    virtual void open_parenthesis(void);
    virtual void close_parenthesis(void);
};

#endif