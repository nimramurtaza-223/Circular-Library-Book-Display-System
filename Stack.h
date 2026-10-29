#ifndef STACK_H
#define STACK_H

struct StackNode {
    int data;
    StackNode* next;
};

class Stack {
private:
    StackNode* topNode;
    int count;

public:
    Stack();
    ~Stack();
    void Push(int val);
    int Pop();
    bool IsEmpty() const;
    int GetCount() const;
};

#endif