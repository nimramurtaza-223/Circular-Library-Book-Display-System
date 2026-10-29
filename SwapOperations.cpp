#include "SwapOperations.h"
#include <utility>

void SwapOperations::SwapData(BookNode* a, BookNode* b) {
    swap(a->bookID, b->bookID);
    swap(a->title, b->title);
}

void SwapOperations::Swap(CircularLinkedList& list, int index1, int index2) {
    if (list.IsEmpty()) return;
    index1 = list.NormalizeIndex(index1);
    index2 = list.NormalizeIndex(index2);
    if (index1 == index2) return;

    BookNode* first = list.GetNodeAt(index1);
    BookNode* second = list.GetNodeAt(index2);
    if (first != nullptr && second != nullptr) {
        SwapData(first, second);
    }
}