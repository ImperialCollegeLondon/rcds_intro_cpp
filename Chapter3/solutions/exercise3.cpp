/*
  Exercise 3: Hello World with for, while,  do while
*/

#include <iostream>
using namespace std;

int main() {

  // for loop
  cout << "for loop" << endl;
  for (int i = 0; i < 5; i++)
    {
      cout << "Hello World; index = " << i << endl;
    }

  // while loop
  cout << "while loop" << endl;
  int counter = 0;
  while(counter < 5)
    {
      cout << "Hello World; index = " << counter << endl;
      counter++;
    }

  // do/while loop
  cout << "do/while loop" << endl;
  counter = 0;
  do {
    cout << "Hello World; index = " << counter << endl;
    counter++;
  }
  while(counter < 5);
  
  return 0;

}