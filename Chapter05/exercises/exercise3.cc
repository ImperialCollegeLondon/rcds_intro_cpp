/*
  Exercise 3: Counting odds and evens
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
using namespace std;

int main() {

  // Declare variables
  int number;
  int odds = 0, evens = 0;

  cout << "Introduce an integer (press ctr+d to end): " << endl;
  for(;;)
    {
      cin >> number;
      if (cin.eof()) break;

      if (number % 2 == 0)
	      evens++;
      else
	      odds++;
    }

  /*
    // Instead
  cout << "Introduce and integer: ";
  cin >> number;
  while(!cin.eof())
    {
      if (number % 2 == 0)
	      odds++;
      else
	      evens++;
      cin >> number;
    }
  */

  cout << endl;
  cout << "Total evens = " << evens << endl;
  cout << "Total odds = " << odds << endl;

  return 0;

}