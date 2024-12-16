#ifndef ELEMENT_H
#define ELEMENT_H

#include "iteratorlist.h"

/**
 * @brief The Element class represents an element of a linked list
 */
class Element
{
private:
    int value;
    Element* next;
    void operator=(const Element&); // to prevent copy
    Element(const Element&); // to prevent copy
public:
    Element(int val);
    ~Element();
    Element* getNext() const {return next;}
    int getValue() const {return value;}
    void connect(Element* elt);
    void disconnect();
    void addLast(Element* elt);
    IteratorList find(int value) const;
    int size() const;
    void removeLast();
};

#endif // ELEMENT_H
