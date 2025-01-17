#ifndef TREE_H
#define TREE_H

#include "treeiterator.h"
#include "node.h"

/**
 * @brief The Tree class a binary tree of integers
 */
class Tree
{
    Node* root;
public:
    Tree();
    ~Tree();
    void add(int value);
    TreeIterator find(int value) const;
    int size() const;
    TreeIterator begin() const;
    TreeIterator end() const;
	int depth() const;
};

#endif // TREE_H
