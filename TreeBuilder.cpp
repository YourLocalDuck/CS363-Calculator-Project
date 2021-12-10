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
    /*if (this->Root == nullptr)
    {
        Root = new Number_Node(value);
    }
    else if (Root->openChild())
    {
        Expr_Node* newchild = new Number_Node(value);
        Root->insert(2, newchild);
    }
    std::cout << Root << std::endl;*/

    Expr_Node* newNumber = new Number_Node(value);
    TreeHelper.push(newNumber);
}

void TreeBuilder::add_operator(void)
{
    /*if (Root->openChild())
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
    std::cout << Root << std::endl;*/
    
    Expr_Node* right_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* left_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* addOperator = new Add_Expr_Node(left_, right_);
    TreeHelper.push(addOperator);
}

void TreeBuilder::subtract_operator(void)
{
    Expr_Node* right_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* left_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* subtract_operator = new Subtract_Expr_Node(left_, right_);
    TreeHelper.push(subtract_operator);
}

void TreeBuilder::multiplication_operator(void)
{
    Expr_Node* right_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* left_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* multiply_operator = new Multiplication_Expr_Node(left_, right_);
    TreeHelper.push(multiply_operator);
}

void TreeBuilder::division_operator(void)
{
    Expr_Node* right_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* left_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* divide_operator = new Division_Expr_Node(left_, right_);
    TreeHelper.push(divide_operator);
}

void TreeBuilder::modulus_operator(void)
{
    Expr_Node* right_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* left_ = TreeHelper.top();
    TreeHelper.pop();
    Expr_Node* mod_operator = new Modulus_Expr_Node(left_, right_);
    TreeHelper.push(mod_operator);
}

void TreeBuilder::open_parenthesis(void)
{
    //stackOperators.push('(');
}

void TreeBuilder::close_parenthesis(void)
{

}

Expr_Node* TreeBuilder::getRoot()
{
    Root = TreeHelper.top();
    TreeHelper.pop();
    return Root;
}
