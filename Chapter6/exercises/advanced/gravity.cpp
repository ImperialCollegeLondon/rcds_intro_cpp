/*
  Exercise: Compute mean (input from file)
*/

// Import libraries
#include <iostream>
#include <fstream>
using namespace std;

// Main function
int main() {

  // Declare variables
  fstream file_input, file_output;
  double num, mean;
  double sum = 0.0, n = 0.0; 

  // Open input file
  file_input.open("00data/data_gravity.dat", ios::in);

  // Ensure file is correctly read
  if (!file_input.good()) {
      cout << "Problems with the file data.dat" << endl;
      return -1;
  }
      
  // Infinite loop until end of file
  for (;;) {

    // Read the numbers and compute sum 
    file_input >> num;
    if (file_input.eof()) break;
    sum += num;
    n++;
  
  }

  // Close file
  file_input.close();

  // Compute mean
  mean = sum / n;
  cout << "Mean = " << mean << endl;
  
  // Store results in output file
  file_output.open("00data/results_gravity.dat", ios::out);
  file_output << "Mean = " << mean << endl;
  file_output.close();

  return 0;

}