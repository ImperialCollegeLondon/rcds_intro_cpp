// Import libraries
#include <iostream>
#include <string>
using namespace std;

// Function reversing a string
string reverse_string(string input) {

    // Declare variables
    string reversed = "";

    // Iterate over input and fill reversed
    for (int i = input.length() - 1; i >= 0; i--) {
        reversed += input[i];
    }

    return reversed;

}

// Main function
int main() {

    // Declare variables
    string original, reversed;
    cout << "Enter a string: ";
    // cin >> original; // Read string until space
    getline(cin, original); // Read entire line including spaces

    // Reverse string and print result
    cout << "Original string: " << original << endl;
    cout << "Reversed string: " << reverse_string(original) << endl;

    return 0;

}
