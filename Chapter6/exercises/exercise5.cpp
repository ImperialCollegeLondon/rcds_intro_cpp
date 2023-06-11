/*
  Exercise: Hello World struct
*/

#include <iostream>
#include <cmath>
using namespace std;

// Declare the complex structure
struct complex {
  double real;
  double imag;
};

// Declaring print function
void print(complex const& v);

// Declaring module function
double modulo(complex const& v);

// Declare a new object with the sum
complex sum(complex const& a, complex const& b);

int main() {

  // Create variables
  complex a, b;

  // Assign the complex number to a
  a.real = 7;
  a.imag = 2;

  // Assign b to a
  b = a;

  // Print a
  cout << "Printing a:" << endl;
  print(a);

  // Printing b
  cout << "Printing b:" << endl;
  print(b);

  // Compute the module of a
  cout << "Module of a = " << modulo(a) << endl;

  // Create the object sum
  complex c = sum(a,b);
  cout << "Printing c:" << endl;
  print(c);
  
  return 0;

}

void print(complex const& v)
{
  cout << "(" << v.real << "," << v.imag << ")" << endl;
}

double modulo(complex const& v)
{
  return sqrt(pow(v.real, 2) + pow(v.imag, 2));
}

complex sum(complex const& a, complex const& b)
{
  complex s;
  s.real = a.real + b.real;
  s.imag = a.imag + b.imag;
  return s;
}