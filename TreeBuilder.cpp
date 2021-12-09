#include "TreeBuilder.h"
#include <iostream> //temporary

TreeBuilder::TreeBuilder()
:Root(nullptr)
{  
}

TreeBuilder::~TreeBuilder()
{
    delete Root;
}

void TreeBuilder::build_number(int value)
{
    if (this->Root == nullptr)
    {
        Root = new Number_Node(value);
    }
    else if (Root->openChild())
    {
        Expr_Node* newchild = new Number_Node(value);
        Root->insert(2, newchild);
    }
    std::cout << Root << std::endl;

}

void TreeBuilder::add_operator(void)
{
    if (Root->openChild())
    {
        Add_Expr_Node* newchild = new Add_Expr_Node();
        Root->insert(2, newchild);
    }
    else
    {
        Add_Expr_Node* newchild = new Add_Expr_Node();
        newchild->insert(1, Root);
        Root = newchild;
    }
    std::cout << Root << std::endl;

}

void TreeBuilder::open_parenthesis(void)
{
    
}

Expr_Node* TreeBuilder::getRoot()
{
    return Root;
}
