// Include libraries
#include <iostream>
#include <thread>
using namespace std;

// Function 1 - write "+" two hundred times
void function1() {
    for (int i = 0; i < 200; ++i) {
        cout << "+";
    }
}

// Function 2 - write "-" two hundred times
void function2() {
    for (int i = 0; i < 200; ++i) {
        cout << "-";
    }
}

// Main function
int main() {

    // Call two instances of the class thread
    thread worker1(function1);
    thread worker2(function2);

    // Join threads for proper syncronization
    // Avoid termination issue
    worker1.join();
    worker2.join();

    // Call function
    function1();
    function2();

    return 0;

}