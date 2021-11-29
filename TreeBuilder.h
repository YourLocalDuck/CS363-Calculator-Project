#ifndef TREEBUILDER_H_EXISTS
#define TREEBUILDER_H_EXISTS

#include "Node.h"
#include <string>

class TreeBuilder
{
private:
    Node* root;
    int middleIndex(std::string str);
public:
    TreeBuilder(std::string postfix);
    ~TreeBuilder();
    Node* buildBST(std::string pfExp, int start, int end);
};

int TreeBuilder::middleIndex(std::string str)
{
    return str.length()/2;
}

TreeBuilder::TreeBuilder(std::string postfix)
{
    buildBST(postfix, 0, postfix.length());
}

TreeBuilder::~TreeBuilder()
{
}


#endif