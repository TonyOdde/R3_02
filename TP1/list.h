#ifndef LIST_H
#define LIST_H

#include "element.h"
#include "iteratorlist.h"
#include "ExceptionList.h"
/**
 * @brief The List class a simple linked list of integers
 */
class List
{
private:
    Element* first;
    List(const List&); // to prevent copy
    void operator=(const List&); // to prevent copy
public:
    List();
    ~List();
    void addFirst(int val);
    void addLast(int val);
    IteratorList begin();
    IteratorList end();
    IteratorList find(int val) const;
    int size() const;
    int get(int i) const;

};

#endif // LIST_H
