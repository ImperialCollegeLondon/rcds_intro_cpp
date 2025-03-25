#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // Declare variables
    ofstream myfile;

    // Open file and write a message
    myfile.open("greetings.txt");
    myfile << "Hello there!" << endl;

    // Close file
    myfile.close();

    return 0;

}