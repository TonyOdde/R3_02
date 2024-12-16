#include "node.h"

//----------------- QUESTION #1 : SIZE ---------------------------
/**
 * @brief Node::size computes the number of nodes
 * @return the number of nodes into the subtree
 */
int Node::size() const
{
	int size = 1;
	if(_left != nullptr) size += _left -> size();
	if(_right != nullptr) size += _right -> size();
	return size;
}

//----------------- QUESTION #2 : ADD -----------------------------
/**
 * @brief Node::add add a value into the subtree
 * @param value the value to add
 */
void Node::add(int value)
{
	if (value < _value) {
		if (_left == nullptr) {
			_left = new Node(value, this);
		} else {
			_left->add(value);
		}
	} else if (value > _value) {
		if (_right == nullptr) {
			_right = new Node(value, this);
		} else {
			_right->add(value);
		}
	}
}

//--------------- QUESTION #3 : Find ------------------------------
/**
 * @brief Node::find find a value into the subtree
 * @param value the value to find
 * @return an iterator on the value founded (may be end() if not founded)
 */
TreeIterator Node::find(int value) const
{
	TreeIterator it;
	if (value == _value) {
		it = TreeIterator(const_cast<Node*>(this));
	}
	if (value < _value && _left != nullptr) {
		it = _left->find(value);
	}
	if (value > _value && _right != nullptr) {
		it = _right->find(value);
	}
	return it;
}

//--------------- QUESTION #4 : iterate the tree -----------------------
/**
 * @brief Node::get_lowest Get the lowest node of the sub-tree (first node in infixe iteration)
 * @return the lowest node of the sub tree
*/
Node* Node::get_lowest() const
{
	Node *lowest = const_cast<Node *>(this);
	if(_left != nullptr) lowest = _left -> get_lowest();
	return lowest;
}

/**
 * @brief Node::get_next_node Get the next node of the sub-tree (in infixe iteration)
 * @return the next node of the sub tree
*/
Node* Node::get_next_node() const
{
	Node* next;
	if (_right != nullptr) {
		next = _right->get_lowest();
	}
	else {
		const Node* current = const_cast<Node*>(this);
		next = _parent;
		while (next != nullptr && current == next->_right) {
			current = next;
			next = next->_parent;
		}
	}
	return next;
}

//----- DO NOT MODIFY AFTER THIS LINE
/**
 * @brief Node::Node build a node
 * @param value the value stored
 * @param parent the parent of the node (nullptr default)
 */
Node::Node(int value, Node* parent)
    :_value(value),_left(nullptr),_right(nullptr),_parent(parent)
{
}

Node::~Node()
{
    delete _left;
    delete _right;
}
