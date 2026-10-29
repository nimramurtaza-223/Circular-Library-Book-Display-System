#ifndef INSERT_OPERATIONS_H
#define INSERT_OPERATIONS_H

#include "CircularLinkedList.h"

class InsertOperations {
public:
    static BookNode* CreateBook(int id, string title);
    static void Insert(CircularLinkedList& list, BookNode* book);
    static void InsertAt(CircularLinkedList& list, BookNode* book, int index);
};

#endif