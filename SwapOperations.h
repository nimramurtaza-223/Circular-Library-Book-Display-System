#ifndef SWAP_OPERATIONS_H
#define SWAP_OPERATIONS_H

#include "CircularLinkedList.h"

class SwapOperations {
public:
    static void SwapData(BookNode* a, BookNode* b);
    static void Swap(CircularLinkedList& list, int index1, int index2);
};

#endif