#include "treeiterator.h"
#include "node.h"



//--------------- QUESTION #4 : iterate the tree
/**
 * @brief TreeIterator::Next move iterator to next element in the tree
 * @throws InvalidIterator if iterator is invalid
 */
void TreeIterator::next()
{
   if (node == nullptr) {
	   throw InvalidIterator();
   }
   node = node->get_next_node();
}

//----- DO NOT MODIFY AFTER THIS LINE
/**
 * @brief TreeIterator::TreeIterator initiate the iterator
 * @param node the node referenced
 */
TreeIterator::TreeIterator(Node* node)
{
    this->node = node;
}
/**
 * @brief TreeIterator::TreeIterator initiate the iterator
 * @param node the node referenced
 */
TreeIterator::TreeIterator(const Node* node) : TreeIterator(const_cast<Node*>(node))
{
}
/**
 * @brief TreeIterator::Equals tells if 2 iterators referenced the same value
 * @param ti another iterator
 * @return true if both iterators referenced same element
 */
bool TreeIterator::equals(const TreeIterator& ti) const
{
    return this->node==ti.node;
}

/**
 * @brief TreeIterator::Value get the value referenced
 * @return the value referenced
 * @throws InvalidIterator if iterator is invalid (out of tree)
 */
int TreeIterator::value() const{
    if(node==nullptr) throw InvalidIterator();
    return this->node->value();
}
/**
 * @brief TreeIterator::Value set the value referenced
 * @return the value referenced (lvalue)
 * @throws InvalidIterator if iterator is invalid (out of tree)
 */
int& TreeIterator::value()
{
    if(node==nullptr) throw InvalidIterator();
    return this->node->value();
}
