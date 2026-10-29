#include "PrintOperations.h"
#include <iostream>

using namespace std;

void PrintOperations::Print(const CircularLinkedList& list) {
    if (list.IsEmpty()) {
        cout << "No books in the collection.\n";
        return;
    }
    BookNode* current = list.head->next;
    cout << "\nIndex\tBook ID\tTitle\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < list.count; i++) {
        cout << i << "\t" << current->bookID << "\t" << current->title << endl;
        current = current->next;
    }
    cout << "Total books: " << list.count << endl;
    cout << "------------------------------------\n";
}