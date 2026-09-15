
#pragma once



class Stack {
public:
    Stack();
    void push(int value);   // add to the top
    int pop();              // remove the top (does nothing if empty)
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;

private:
    int data[100];
    int topIndex;
};
