#ifndef TREEITERATOR_H
#define TREEITERATOR_H
#include <exception>
class Node;

/**
 * @brief The InvalidIterator class exception when an iterator is invalid
 */
class InvalidIterator : std::exception
{

};

/**
 * @brief The TreeIterator class an iterator on a binary tree
 */
class TreeIterator
{
    Node* node;
public:
    TreeIterator(Node* node);
    TreeIterator(const Node* node);
    TreeIterator():node(nullptr){}    
    // methods (for standard notation)
    void next();
    bool equals(const TreeIterator& ti) const;
    int value() const;
    int& value();
    // operators redefinition to increase readability (and more C++ way)
    bool operator==(const TreeIterator& ti) const {return equals(ti);}
    bool operator!=(const TreeIterator& ti) const {return !(*this==ti);}
    int operator*() const {return value();}
    int& operator*() {return value();}
    void operator++() {next();}

};

#endif // TREEITERATOR_H
