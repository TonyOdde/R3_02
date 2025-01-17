#include "tree.h"



//----------------- QUESTION #1 : SIZE ---------------------------
/**
 * @brief Tree::Size computes the size of the tree
 * @return the number of values
 */
int Tree::size() const
{
	int size = 0;
	if(root != nullptr) size = root->size();
	return size;
}

//----------------- QUESTION #2 : ADD -----------------------------
/**
 * @brief Tree::Add add a value
 * @param value the value to add
 */
void Tree::add(int value)
{
	if (root == nullptr) {
		root = new Node(value);
	} else {
		Node* newNode = root->add(value);
		if(newNode != nullptr) {
			newNode->balance();
			root = newNode->getRoot();
		}
	}
}
//--------------- QUESTION #3 : Find ------------------------------
/**
 * @brief Tree::Find find a value
 * @param value the value to find
 * @return an iterator to the value. Equals to End() if not found.
 */
TreeIterator Tree::find(int value) const
{
	TreeIterator it = TreeIterator();
	if(root != nullptr) {
		it = root->find(value);
	}
	return it;
}

//--------------- QUESTION #4 : iterate the tree
/**
 * @brief Tree::Begin Give an iterator on the first value (the lowest)
 * @return an iterator on the lowest value (may be End() if tree is empty)
 */
TreeIterator Tree::begin() const {
	TreeIterator it;
	if(root != nullptr) {
		it = TreeIterator(root->get_lowest());
	}
	else {
		it = end();
	}
	return it;
}

//----- DO NOT MODIFY AFTER THIS LINE
Tree::Tree()
    :root(nullptr)
{

}

Tree::~Tree()
{
    delete root;
}

/**
 * @brief Tree::End Invalid iterator (out of tree)
 * @return an invalid iterator (out of tree)
 */
TreeIterator Tree::end() const
{
    return TreeIterator();
}

int Tree::depth() const
{
	return root ? root->levels() : 0;
}
