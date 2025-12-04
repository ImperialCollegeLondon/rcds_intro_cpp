// Import libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function reversing a string
string reverse_string(const string& input) {

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
    string original;

    cout << "Enter a string: ";
    // cin >> original; // Read string until space
    getline(cin, original); // Read entire line including spaces

    // Reverse the string
    string reversed = reverse_string(original);

    // Print results
    cout << "\nOriginal string: " << original << endl;
    cout << "Reversed string: " << reversed << endl;

    // Append reversed string to existing file
    ofstream file("greetings.txt", ios::app);
    if (!file) {
        cout << "Error: Could not open file for appending.\n";
        return 1;
    }

    file << reversed << "\n";
    file.close();
    
    cout << "\nReversed string appended to greetings.txt\n";

    return 0;
    
}