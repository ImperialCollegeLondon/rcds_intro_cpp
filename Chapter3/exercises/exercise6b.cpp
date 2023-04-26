/*
  Esercizio 4: Output file
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main() {

  // Declare variables  
  ofstream myfile;
  string line;
  
  // Write on file
  myfile.open ("greeting.txt");
  myfile << "Hello there!" << endl;
  myfile.close();

  // Read on file
  myfile.open ("greeting.txt");
  while (getline(myfile, line)){
      cout << line << endl;
  }
  myfile.close();

  return 0;

}