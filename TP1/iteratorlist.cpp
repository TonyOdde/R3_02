#include "iteratorlist.h"
#include "element.h"
#include "ExceptionList.h"

/**
 * @brief IteratorList::IteratorList initialize the iterator
 * @param e the reference element (can be nullptr)
 */
IteratorList::IteratorList(Element *e) : element(e)
{}

/**
 * @brief IteratorList::IteratorList initialize the iterator
 * @param e the const reference element (can be nullptr)
 */
IteratorList::IteratorList(const Element* e)
{
    element = const_cast<Element*>(e);
}

/**
 * @brief IteratorList::next goes to next element
 * @throw ExceptionList if iterator is invalid
 */
void IteratorList::next()
{
    if(element==nullptr)
        throw ExceptionList();
    element = element->getNext();
}

/**
 * @brief IteratorList::equals tells if 2 iterator has the same element
 * @param other the other iterator
 * @return true if both iterators points to same element
 */
bool IteratorList::equals(const IteratorList& other) const
{
    return element == other.element;
}

/**
 * @brief IteratorList::getValue gets the value behind the iterator
 * @return the value stored
 * @throw ExceptionList if iterator is invalid
 */
int IteratorList::getValue() const
{
    if(element==nullptr) throw ExceptionList();
    return element->getValue();
}

