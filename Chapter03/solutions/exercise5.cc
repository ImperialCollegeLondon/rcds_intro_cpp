/*
  Esercizio 5: Input

  Author: Stefano Carrazza - 2018
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

  // Declare variabili
  char name[20];
  string surname;
  int number;
  fstream finput, foutput;

  // Prepare input stream
  finput.open("myinput.dat", ios::in);

  // Check if file exists
  if (!finput.good())
    {
      cout << "Cannot open myinput.dat" << endl;
      return -1;
    }

  // Read from file
  finput >> name;
  finput >> surname;
  finput >> number;

  // Close input file
  finput.close();
  
  cout << surname << ", " << name << " is registered with number " << number << ".\n";  

  // Print to file
  foutput.open("result.dat", ios::out);

  if (!foutput.good())
    {
      cout << "Error: file is not good!" << endl;
      return -1;
    }

  foutput << surname << ", " << name << " is registered with number " << number << ".\n";  
  
  // Close file
  foutput.close();
  
  return 0;

}