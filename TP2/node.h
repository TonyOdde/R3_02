#ifndef NODE_H
#define NODE_H

#include "treeiterator.h"

/**
 * @brief The Node class a node of a binary tree
 */
class Node
{
    int _value;
    Node* _left;
    Node* _right;
    Node* _parent;

public:
    Node(int value, Node* dad=nullptr);
    ~Node();
    int value() const {return _value;} /**< gets value to store */
    int& value() {return _value;} /**< sets value to store */    
    Node* add(int value);
    TreeIterator find(int value) const;
    int size() const;
    Node* get_lowest() const;
    Node* get_next_node() const;
	Node* rotate_right();
	Node* rotate_left();
	int levels() const;
	int gap() const;
	Node* balance();
	Node* getRoot();
};

#endif // NODE_H
