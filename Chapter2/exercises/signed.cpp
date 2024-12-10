#include <iostream>
using namespace std;

int main() {

    // Declare variables
    signed int signed_var = -10;
    unsigned int unsigned_var = 10;
    unsigned int unsigned_wrap = 0;

    // Substract 1 from the smallest possible value of unsigned variable
    unsigned_wrap = unsigned_wrap - 1;

    // Display values
    cout << "Signed variable: " << signed_var << endl;
    cout << "Unsigned variable: " << unsigned_var << endl;
    cout << "When an unsigned variable wraps around: " << unsigned_wrap << endl;

    // Input signed variable exceeding range
    cout << "\nEnter a signed integer: ";
    cin >> signed_var;
    cout << "You entered: " << signed_var << endl;

    // Input unsigned variable exceeding range
    cout << "Enter an unsigned integer: ";
    cin >> unsigned_var;
    cout << "You entered: " << unsigned_var << endl;

    return 0;

}