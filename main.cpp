#include <iostream>
#include "CircularLinkedList.h"
#include "InsertOperations.h"
#include "RemoveOperations.h"
#include "SwapOperations.h"
#include "SortReverseOperations.h"
#include "PrintOperations.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
    CircularLinkedList library;
    Stack bookStack;
    Queue bookQueue;
    int choice;

    InsertOperations::InsertAt(library, InsertOperations::CreateBook(101, "Data Structures"), 0);
    InsertOperations::InsertAt(library, InsertOperations::CreateBook(102, "Database Systems"), 1);
    InsertOperations::InsertAt(library, InsertOperations::CreateBook(103, "Operating Systems"), 2);

    do {
        cout << "\nCIRCULAR LIBRARY BOOK DISPLAY SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Move to Next Book\n";
        cout << "10. Check Collection Status\n";
        cout << "11. Stack & Queue Demo\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                PrintOperations::Print(library);
                break;
            case 2: {
                int id;
                string title;
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                InsertOperations::Insert(library, InsertOperations::CreateBook(id, title));
                cout << "Book inserted at head successfully!\n";
                break;
            }
            case 3: {
                BookNode* removed = RemoveOperations::Remove(library);
                if (removed != nullptr) {
                    cout << "Removed: " << removed->title << endl;
                    delete removed;
                } else {
                    cout << "Collection is empty.\n";
                }
                break;
            }
            case 4: {
                int id, index;
                string title;
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Index: ";
                cin >> index;
                InsertOperations::InsertAt(library, InsertOperations::CreateBook(id, title), index);
                cout << "Book inserted at index successfully!\n";
                break;
            }
            case 5: {
                int index;
                cout << "Enter Index to remove: ";
                cin >> index;
                BookNode* removed = RemoveOperations::RemoveAt(library, index);
                if (removed != nullptr) {
                    cout << "Removed: " << removed->title << endl;
                    delete removed;
                } else {
                    cout << "Invalid index or empty collection.\n";
                }
                break;
            }
            case 6: {
                int idx1, idx2;
                cout << "Enter index 1: ";
                cin >> idx1;
                cout << "Enter index 2: ";
                cin >> idx2;
                SwapOperations::Swap(library, idx1, idx2);
                cout << "Books swapped successfully!\n";
                break;
            }
            case 7:
                SortReverseOperations::Sort(library);
                cout << "Books sorted by ID successfully!\n";
                break;
            case 8:
                SortReverseOperations::Reverse(library);
                cout << "Collection reversed successfully!\n";
                break;
            case 9:
                cout << "Moving to next book in circular rotation...\n";
                PrintOperations::Print(library);
                break;
            case 10:
                if (library.IsEmpty())
                    cout << "Status: Collection is Empty.\n";
                else
                    cout << "Status: Collection is Not Empty. Total books: " << library.GetCount() << endl;
                break;
            case 11:
                bookStack.Push(501);
                bookStack.Push(502);
                bookQueue.Enqueue(901);
                bookQueue.Enqueue(902);
                cout << "Stack popped value: " << bookStack.Pop() << endl;
                cout << "Queue dequeued value: " << bookQueue.Dequeue() << endl;
                break;
            case 12:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Dobara koshish karein.\n";
        }
    } while (choice != 12);

    return 0;
}