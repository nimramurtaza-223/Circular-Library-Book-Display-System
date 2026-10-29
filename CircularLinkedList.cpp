/* Circular Linked List Implementation */
#include "CircularLinkedList.h"
#include "InsertOperations.h"
#include "RemoveOperations.h"

CircularLinkedList::CircularLinkedList() {
    head = nullptr;
    count = 0;
}

CircularLinkedList::CircularLinkedList(const CircularLinkedList& other) {
    head = nullptr;
    count = 0;
    if (other.head == nullptr) return;

    BookNode* current = other.head->next;
    for (int i = 0; i < other.count; i++) {
        BookNode* copy = InsertOperations::CreateBook(current->bookID, current->title);
        InsertOperations::InsertAt(*this, copy, count);
        current = current->next;
    }
}

CircularLinkedList& CircularLinkedList::operator=(const CircularLinkedList& other) {
    if (this == &other) return *this;

    while (IsNotEmpty()) {
        BookNode* removed = RemoveOperations::Remove(*this);
        delete removed;
    }

    if (other.head == nullptr) return *this;

    BookNode* current = other.head->next;
    for (int i = 0; i < other.count; i++) {
        BookNode* copy = InsertOperations::CreateBook(current->bookID, current->title);
        InsertOperations::InsertAt(*this, copy, count);
        current = current->next;
    }
    return *this;
}

CircularLinkedList::~CircularLinkedList() {
    while (IsNotEmpty()) {
        BookNode* removed = RemoveOperations::Remove(*this);
        delete removed;
    }
}

bool CircularLinkedList::IsEmpty() const {
    return count == 0;
}

bool CircularLinkedList::IsNotEmpty() const {
    return count > 0;
}

int CircularLinkedList::GetCount() const {
    return count;
}

int CircularLinkedList::NormalizeIndex(int index) {
    if (count == 0) return 0;
    return ((index % count) + count) % count;
}

BookNode* CircularLinkedList::GetNodeAt(int index) {
    if (head == nullptr) return nullptr;
    BookNode* current = head->next;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}
