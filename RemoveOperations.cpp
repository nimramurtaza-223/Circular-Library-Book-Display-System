#include "RemoveOperations.h"

BookNode* RemoveOperations::Remove(CircularLinkedList& list) {
    if (list.IsEmpty()) return nullptr;
    BookNode* first = list.head->next;
    if (first == list.head) {
        list.head = nullptr;
    } else {
        list.head->next = first->next;
    }
    first->next = nullptr;
    list.count--;
    return first;
}

BookNode* RemoveOperations::RemoveAt(CircularLinkedList& list, int index) {
    if (list.IsEmpty()) return nullptr;
    index = list.NormalizeIndex(index);
    if (index == 0) return Remove(list);

    BookNode* previous = list.GetNodeAt(index - 1);
    BookNode* target = previous->next;
    previous->next = target->next;

    if (target == list.head) {
        list.head = previous;
    }
    target->next = nullptr;
    list.count--;
    return target;
}