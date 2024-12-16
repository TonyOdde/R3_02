#include "list.h"

#include <ranges>

#include "ExceptionList.h"
/** 
 * @brief List::List init the list
 @todo 
 */
List::List()
{
  first = nullptr;
}


/** 
 @todo 
 * @brief List::~List release the memory
 */
List::~List()
{
    delete(first);
}

/** 
 @todo
 * @brief List::addFirst Add a value at the beginning of the list
 * @param val the value to add
 */
void List::addFirst(int val)
{
 Element* elt = new Element(val);
 elt->connect(first);
 first = elt;
}

/** 
 @todo
 * @brief List::addLast add a value at the end of the list
 * @param val the value to add
 */
void List::addLast(int val)
{
 Element* elt = new Element(val);
 if(first == nullptr) first = elt;
 else first->addLast(elt);
}

/**
 * @brief List::begin give begin of the list
 * @return iterator on the first element (if exists)
 */
IteratorList List::begin()
{
    return IteratorList(first);
}

/**
 * @brief List::end give an invalid iterator
 * @return iterator invalid (out of list)
 */
IteratorList List::end()
{
    return IteratorList();
}
/**
 @todo 
 * @brief List::find Search the value inside the list
 * @param val the value to find
 * @return iterator on value foud (or end() if not found)
 */
IteratorList List::find(int val) const
{
    IteratorList iter;
    if (first != nullptr) iter = first->find(val);
    return iter;
}

/** 
 @todo
 * @brief List::size calculates the number of values in the list
 * @return the number of list elements
 */
int List::size() const
{
    int s=0;
    if(first != nullptr) s += first->size();
    return s;
}

/**
 @todo
 * @brief List::get gives the i-th value
 * @param i the desired range ([0..size[)
 * @return the value
 * @throws ExceptionList if bad range
 */
int List::get(int i) const
{
    Element* elt = first;
    int pas = 0;
    while (elt != nullptr && pas < i)
    {
     elt = elt->getNext();
     pas++;
    }
    if (elt == nullptr) throw ExceptionList();
    return elt->getValue();
}


