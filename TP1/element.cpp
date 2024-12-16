#include "element.h"

#include <stdlib.h>

/** 
 @todo
 * @brief Element::Element init the element
 * @param val the value to store
 */
Element::Element(int val) 
{
  value = val;
  next = nullptr;
}

/** 
 @todo
 * @brief Element::~Element release the memory
 */
Element::~Element()
{
    delete(next);
}

/**
 * @brief Element::connect connect the element to another
 * @param elt the new next element
 * This function DO NOT create any element, it only makes the link
 */
void Element::connect(Element *elt)
{
    next = elt;
}

/**
 * @brief Element::disconnect remove the link with the next element
 * The function DO NOT destroy any element, it only break the link
 */
void Element::disconnect()
{
    next = nullptr;
}

/** 
 @todo
 * @brief Element::addLast add an element at the end of the chain
 * @param elt the element to add
 */
void Element::addLast(Element *elt)
{
	if(next == nullptr) next = elt;
	else next->addLast(elt);
}

/** 
 @todo
 * @brief Element::find search the linked list for a value
 * @param value the value to find
 * @return iterator on the element found (may be end)
 */
IteratorList Element::find(int value) const
{
    IteratorList iter;
	if (this->value != value && next != nullptr) iter = next->find(value);
	else if (this->value == value) iter = IteratorList(this);
    return iter;
}

/**
 @todo 
 * @brief Element::size Calculates the number of elements in the sublist (the element and the next ones)
 * @return the total number of values in the element & his nexts
 */
int Element::size() const
{
    int taille = 1;
	if (next != nullptr) taille += next->size();
    return taille	;
}

