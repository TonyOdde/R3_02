#ifndef ITERATORLIST_H
#define ITERATORLIST_H

class Element;

/**
 * @brief The IteratorList class is an iterator on the list
 */
class IteratorList
{
private:
    Element* element;
public:
    IteratorList():element(nullptr){}
    IteratorList(Element *e);
    IteratorList(const Element* e);
    void next();
    bool equals(const IteratorList& other) const;
    int getValue() const ;
};

#endif // ITERATORLIST_H
