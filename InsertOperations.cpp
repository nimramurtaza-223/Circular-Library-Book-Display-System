#include "InsertOperations.h"

BookNode* InsertOperations::CreateBook(int id, string title) {
    BookNode* book = new BookNode;
    book->bookID = id;
    book->title = title;
    book->next = nullptr;
    return book;
}

void InsertOperations::Insert(CircularLinkedList& list, BookNode* book) {
    if (book == nullptr) return;
    if (list.head == nullptr) {
        list.head = book;
        book->next = book;
    } else {
        book->next = list.head->next;
        list.head->next = book;
    }
    list.count++;
}

void InsertOperations::InsertAt(CircularLinkedList& list, BookNode* book, int index) {
    if (book == nullptr) return;
    if (list.count == 0) {
        list.head = book;
        book->next = book;
        list.count++;
        return;
    }

    if (index < 0) index = list.NormalizeIndex(index);
    if (index > list.count) index = list.count;

    if (index == 0) {
        Insert(list, book);
        return;
    }

    if (index == list.count) {
        book->next = list.head->next;
        list.head->next = book;
        list.head = book;
        list.count++;
        return;
    }

    BookNode* previous = list.GetNodeAt(index - 1);
    book->next = previous->next;
    previous->next = book;
    list.count++;
}