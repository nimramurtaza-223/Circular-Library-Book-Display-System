#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
    int data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* frontNode;
    QueueNode* rearNode;
    int count;

public:
    Queue();
    ~Queue();
    void Enqueue(int val);
    int Dequeue();
    bool IsEmpty() const;
    int GetCount() const;
};

#endif