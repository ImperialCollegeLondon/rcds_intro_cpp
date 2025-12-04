// Import libraries
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Original version
string reverse_string(const string& input) {

    string reversed = "";

    // Iterate over input and fill reversed
    for (int i = input.length() - 1; i >= 0; i--) {
        reversed += input[i];
    }

    return reversed;
}

// Improved version (pre-allocates final size and writes in place)
string reverse_string_fast(const string& input) {

    // Allocate exact size
    string reversed;
    reversed.reserve(input.size());

    // Fill buffer directly
    for (size_t index = 0; index < input.size(); ++index) {
        reversed[index] = input[input.size() - 1 - index];
    }

    return reversed;

}

// Main function
int main() {

    // Declare variables
    string original;
    cout << "Enter a string: ";
    getline(cin, original);

    // Time original version
    auto t1 = high_resolution_clock::now();
    string reversed_old = reverse_string(original);
    auto t2 = high_resolution_clock::now();

    // Time improved version
    auto t3 = high_resolution_clock::now();
    string reversed_fast = reverse_string_fast2(original);
    auto t4 = high_resolution_clock::now();

    // Print results
    // cout << "\nOriginal string: " << original << "\n";
    cout << "Reversed (old):  " << reversed_old << "\n";
    cout << "Reversed (fast): " << reversed_fast << "\n";

    // cout << "\nTiming results:\n";
    cout << "  Old method:  " << duration_cast<nanoseconds>(t2 - t1).count() << " ns\n";
    cout << "  Fast method: " << duration_cast<nanoseconds>(t4 - t3).count() << " ns\n";

    // Append result to file
    ofstream file("greetings.txt", ios::app);
    if (!file) {
        cout << "Error: Could not open file for appending.\n";
        return 1;
    }

    file << reversed_fast << "\n";
    cout << "\nReversed string appended to greetings.txt\n";

    return 0;

}
