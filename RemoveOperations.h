#ifndef REMOVE_OPERATIONS_H
#define REMOVE_OPERATIONS_H

#include "CircularLinkedList.h"

class RemoveOperations {
public:
    static BookNode* Remove(CircularLinkedList& list);
    static BookNode* RemoveAt(CircularLinkedList& list, int index);
};

#endif