/*
  Exercise: Pointer arrays
*/

#include <iostream>
using namespace std;

int main() {

  // Declare dynamic array
  int n = 10;
  double *v = new double[10];

  // Print array
  cout << "Array of pointers:" << endl;
  for (int i = 0; i < n; i++)
    cout << "&v[" << i << "] = " << &v[i] << endl;
  delete[] v;

  return 0;

}