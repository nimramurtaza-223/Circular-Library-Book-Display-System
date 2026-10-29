#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <string>
using namespace std;

struct BookNode {
    int bookID;
    string title;
    BookNode* next;
};

class CircularLinkedList {
private:
    BookNode* head;
    int count;

public:
    CircularLinkedList();
    CircularLinkedList(const CircularLinkedList& other);
    CircularLinkedList& operator=(const CircularLinkedList& other);
    ~CircularLinkedList();

    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
    int NormalizeIndex(int index);
    BookNode* GetNodeAt(int index);

    // Friend classes to access private members for modular functions
    friend class InsertOperations;
    friend class RemoveOperations;
    friend class SwapOperations;
    friend class SortReverseOperations;
    friend class PrintOperations;
};

#endif