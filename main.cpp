#include <iostream>
class Box {
public:
    Box(int value): data(new int(value)) {}

    ~Box () {
        delete data;
        data = nullptr;
    }
    int value() {
        return *data;
    }
private:
    int *data;
};
int main() {
    // int* p = new int(5);
    // std::cout << *p << std::endl;
    // std::cout << p << std::endl;
    // delete p; //-destructor in classes
    // p = nullptr;

    Box *box1 = new Box(5);
    std::cout << box1->value() << std::endl;
    delete box1;


    //int x=5;
    // int* p = &x; //pointer p- exist in stack memory
    // std::cout << x << std::endl;
    // std::cout << *p << std::endl; // -dereferencing- gives value inside adress
    // std::cout << p << std::endl; // -referencing- gives adress itself
    // *p=10;
    // std::cout << *p << std::endl;
    // std::cout << &x << std::endl;


    return 0;
}