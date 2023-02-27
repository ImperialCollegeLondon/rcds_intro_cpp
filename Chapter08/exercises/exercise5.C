/*
  Exercise: Hello World struct - ROOT macro
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <cmath>
using namespace std;

// Declaring variables of mycomplex structure
struct mycomplex {
  double real;
  double imag;
};

// Declare print function
void print(mycomplex const& v);

// Declare module function
double modulo(mycomplex const& v);

// Declare the function sum
mycomplex sum(mycomplex const& a, mycomplex const& b);

void exercise5() {

  // Declare variables
  mycomplex a, b;

  // Assign the complex number to a
  a.real = 7;
  a.imag = 2;

  // Assign b to a
  b = a;

  // Print a
  cout << "Printing a:" << endl;
  print(a);

  // Print b
  cout << "Printing b:" << endl;
  print(b);

  // Compute the module of a
  cout << "Modulo di a = " << modulo(a) << endl;

  // Create sum
  mycomplex c = sum(a,b);
  cout << "Printing c:" << endl;
  print(c);
}

void print(mycomplex const& v)
{
  cout << "(" << v.real << "," << v.imag << ")" << endl;
}

double modulo(mycomplex const& v)
{
  return sqrt(pow(v.real, 2) + pow(v.imag, 2));
}

mycomplex sum(mycomplex const& a, mycomplex const& b)
{
  mycomplex s;
  s.real = a.real + b.real;
  s.imag = a.imag + b.imag;
  return s;
}