#include "SortReverseOperations.h"
#include "SwapOperations.h"

void SortReverseOperations::Sort(CircularLinkedList& list) {
    if (list.count < 2) return;
    BookNode* current = list.head->next;
    for (int i = 0; i < list.count - 1; i++) {
        BookNode* nextNode = current->next;
        for (int j = i + 1; j < list.count; j++) {
            if (current->bookID > nextNode->bookID) {
                SwapOperations::SwapData(current, nextNode);
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

void SortReverseOperations::Reverse(CircularLinkedList& list) {
    if (list.count < 2) return;
    BookNode* oldTail = list.head;
    BookNode* oldFirst = list.head->next;
    BookNode* previous = oldTail;
    BookNode* current = oldFirst;

    while (current != oldTail) {
        BookNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    oldTail->next = previous;
    list.head = oldFirst;
}