#include "Queue.h"

Queue::Queue() {
    frontNode = nullptr;
    rearNode = nullptr;
    count = 0;
}

Queue::~Queue() {
    while (!IsEmpty()) {
        Dequeue();
    }
}

void Queue::Enqueue(int val) {
    QueueNode* newNode = new QueueNode{val, nullptr};
    if (rearNode == nullptr) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    count++;
}

int Queue::Dequeue() {
    if (IsEmpty()) return -1;
    QueueNode* temp = frontNode;
    int dequeuedVal = temp->data;
    frontNode = frontNode->next;
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    delete temp;
    count--;
    return dequeuedVal;
}

bool Queue::IsEmpty() const {
    return frontNode == nullptr;
}

int Queue::GetCount() const {
    return count;
}