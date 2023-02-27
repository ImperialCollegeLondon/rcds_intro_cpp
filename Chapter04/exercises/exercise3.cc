/*
  Exercise: Chosing bycicle size
  Author: Jesús Urtasun - 2020

*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

  // Declare variables                
  int age;
  double height, weight;
  string size;

  // Read input
  cout << "Introduce age, height, waight: ";
  cin >> age >> height >> weight;

  // Perform selection
  if (age <= 10)
    {
      size = "XS";
    }
  else if (age > 10 && age <= 18)
    {
      if (height <= 1.1)
	size = "XS";
      else if (height > 1.1 && height <= 1.3 && weight <= 40)
	size = "S";
      else if ((height > 1.1 && height <= 1.3 && weight > 40) ||
	       (height > 1.3 && height <= 1.6) )
	size = "M";      
      else if (height > 1.7)
	size = "L";
      else
	size = "no model available";
    }
  else
    {
      if (height <= 1.4 || weight <= 40)
	size = "XS";
      else if (height > 1.4 && height <= 1.6)
	size = "S";
      else if (height > 1.6 && height <= 1.7)
	size = "M";
      else if (height > 1.7 && height <= 1.9)
	size = "L";
      else if (height > 1.9)
	size = "XL";
      else
	size = "no model available";      
    }

  cout << "Suggested size: " << size << endl;
  
  return 0;

}