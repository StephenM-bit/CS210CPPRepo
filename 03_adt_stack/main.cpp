
#include <iostream>
#include "Stack.h"

int main() {
    Stack s;

    s.push(10);
    s.push(20);

    std::cout << "Stack size: " << s.size() << std::endl;
    std::cout << "Top: " << s.peek() << std::endl;

    s.push(30);

    std::cout << "Stack size: " << s.size() << std::endl;
    std::cout << "Top: " << s.peek() << std::endl;

    s.pop();
    std::cout << "After pop, top: " << s.peek() << std::endl;
    s.pop();
    std::cout << "After pop, top: " << s.peek() << std::endl;
    // s.pop();
    // std::cout << "After pop, top: " << s.peek() << std::endl;

    std::cout << "Is empty? " << (s.isEmpty() ? "yes" : "no") << std::endl;

    return 0;
}
