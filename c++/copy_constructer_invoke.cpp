#include <iostream>

class MyClass {
private:
    int data;

public:
    // Constructor
    MyClass(int d) : data(d) {}

    // Copy constructor
    MyClass(const MyClass &other) {
        data = other.data;
        std::cout << "Copy constructor invoked" << std::endl;
    }

    // Method to display data
    void display() {
        std::cout << "Data: " << data << std::endl;
    }
};

// Function that takes an object by value
void functionTakingObject(MyClass obj) {
    std::cout << "Inside functionTakingObject" << std::endl;
    obj.display();
}

int main() {
    // Create an object
    MyClass original(10);

    std::cout << "Calling functionTakingObject" << std::endl;
    functionTakingObject(original);

    return 0;
}
