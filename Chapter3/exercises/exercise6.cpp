/*
  Esercizio 4: Output file
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

  // Declare variables
  char name[20];
  string surname;
  int number;
  fstream foutput;
  
  // Print to screen
  cout << "Introduce name: ";
  cin >> name;

  cout << "Introduce surname: ";
  cin >> surname;

  cout << "Introduce number: ";
  cin >> number;

  cout << surname << ", " << name << " is registered with number " << number << ".\n";  

  // Print to file
  foutput.open("result.dat", ios::out);

  if (foutput.good())
    {
      foutput << surname << ", " << name << " is registered with number " << number << ".\n";  
    }
  else
    cout << "Error: file is not good!" << endl;

  // Close file
  foutput.close();
  
  return 0;

}