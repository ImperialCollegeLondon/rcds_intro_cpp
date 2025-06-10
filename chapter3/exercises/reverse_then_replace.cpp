// Import libraries
#include <iostream>
#include <string>
using namespace std;

// Function reversing a string and replacing vowels
string reverse_string(string input) {

    // Declare variables
    string result = "";

    // Iterate over input and fill reversed
    for (int i = input.length() - 1; i >= 0; i--) {

        char c = input[i];
        switch (c) {
            case 'a': result += 'A'; break;
            case 'e': result += 'E'; break;
            case 'i': result += 'I'; break;
            case 'o': result += 'O'; break;
            case 'u': result += 'U'; break;
            default: result += c;
        }
    }

    return result;

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
    cout << "Processed string: " << reverse_string(original) << endl;

    return 0;

}
