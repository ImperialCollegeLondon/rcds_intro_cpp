// JU26625

// Anonymous functions & lambda expressions

// The core syntax difference:
// C++ added lambda expressions / anonymous functions in C++11 (2011) with full closure capture semantics.
// C++ lambdas are full statement blocks ([capture](params) { body }); more powerful than Python lambdas at the cost of verbosity.

// Import libraries
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Example 1: double a number
int double_int(int x) {          // fix: missing type "int" before x
    return 2 * x;
}

auto f = [](int x) {
    return x * 2;
};                               // fix: missing semicolon


// Example 2: add two numbers
int add(int x, int y) {
    return x + y;
}

auto add_lambda = [](int x, int y) {
    return x + y;
};


// Example 3: filter even numbers
bool is_even(int x) {
    return x % 2 == 0;
}


// Main function
int main() {

    // Example 1: double a number ..................................................................
    cout << "\nDouble a number" << endl;
    cout << "With double_int(x): " << double_int(5) << endl;
    cout << "With lambda f(x): " << f(5) << endl;         // fix: missing << before f(5)
    // Normal function: human-readable name
    cout << typeid(double_int).name() << endl; // "FiiE" or similar (mangled)

    // Example 2: add two numbers ..................................................................
    cout << "\nAdd two numbers" << endl;
    cout << "With add(x, y): " << add(2, 3) << endl;
    cout << "With lambda add(x, y): " << add_lambda(2, 3) << endl;
    // Lambda: compiler-generated unique type, unreadable
    cout << typeid(f).name() << endl; // "Z4mainEUliE_" or similar
    
    // Example 3: filter even numbers ..............................................................
    cout << "\nFilter even numbers" << endl;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> evens;

    // With a normal function
    copy_if(numbers.begin(), numbers.end(), back_inserter(evens), is_even);
    cout << "With is_even(x): ";
    for (int n : evens) cout << n << " ";
    cout << endl;

    // With a lambda expression
    evens.clear();
    copy_if(numbers.begin(), numbers.end(), back_inserter(evens),
            [](int x) { return x % 2 == 0; });
    cout << "With lambda(x): ";
    for (int n : evens) cout << n << " ";
    cout << endl;

    return 0;

}