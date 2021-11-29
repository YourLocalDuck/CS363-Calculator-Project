#ifndef _NODE_H_
#define _NODE_H_

class Node
{
private:
    char data;
    Node* left;
    Node* right;
    friend class TreeBuilder;
public:
    Node();
    Node(char iData);
    ~Node();
    void insert(char character);
};

Node::Node()
:left(nullptr),
right(nullptr)
{
}

Node::Node(char iData)
:left(nullptr),
right(nullptr)
{
    data = iData;
}

Node::~Node()
{
    if (left != nullptr)
    {
        delete left;
    }
    if (right != nullptr)
    {
        delete right;
    }
}


#endif