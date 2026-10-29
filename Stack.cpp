#include "Stack.h"

Stack::Stack() {
    topNode = nullptr;
    count = 0;
}

Stack::~Stack() {
    while (!IsEmpty()) {
        Pop();
    }
}

void Stack::Push(int val) {
    StackNode* newNode = new StackNode{val, topNode};
    topNode = newNode;
    count++;
}

int Stack::Pop() {
    if (IsEmpty()) return -1;
    StackNode* temp = topNode;
    int poppedVal = temp->data;
    topNode = topNode->next;
    delete temp;
    count--;
    return poppedVal;
}

bool Stack::IsEmpty() const {
    return topNode == nullptr;
}

int Stack::GetCount() const {
    return count;
}