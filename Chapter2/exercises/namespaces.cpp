#include <iostream>

// First namespace
namespace First {

    // Void function printing greeting
    void greet() {
        std::cout << "Hello from First namespace!" << std::endl;
    }
}

// Second namespace
namespace Second {

    // Void function printing greeting
    void greet() {
        std::cout << "Hello from Second namespace!" << std::endl;
    }
}

// Main function
int main() {
    
    // Calls greet from First namespace
    First::greet();

    // Calls greet from Second namespace
    Second::greet();

    return 0;

}