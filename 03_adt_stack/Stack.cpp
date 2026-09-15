
#include "Stack.h"

#include <iostream>
#include <ostream>

Stack::Stack() {
    topIndex=-1;
}

void Stack::push(int value) {
    // TODO: add value to the top of data_ (vector has a method for this)
    if (isFull()==false) {
        topIndex++;
        data[topIndex]=value;
    }
    else {
        std::cout<<"Stack is full"<<std::endl;
    }
}

int Stack::pop() {
    // TODO: if data_ isn't empty, remove the top element
    if (isEmpty()==false) {
        int num=data[topIndex];
        topIndex--;
        return num;
    }

    std::cout<<"Stack is empty"<<std::endl;
    return -1;
}

int Stack::peek() const {
    // TODO: return the top element of data_
    if (isEmpty()==false) {
        return data[topIndex];
    }
    std::cout<<"Stack is empty"<<std::endl;
    return -1;
}

bool Stack::isEmpty() const {
    // TODO: return whether data_ has zero elements
    if (topIndex == -1)
        return true;

    return false;
}

bool Stack::isFull() const {
    if (topIndex == 99)
        return true;

    return false;
}

int Stack::size() const {
    // TODO: return how many elements are in data_ (cast to int)
    return topIndex+1;
}
