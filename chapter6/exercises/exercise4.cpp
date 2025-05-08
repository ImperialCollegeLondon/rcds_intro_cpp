/*
  Exercise: Scalar product, norm, transpose matrix
*/

#include <iostream>
#include <cmath>
using namespace std;

double scalar(const double a[], const double b[], int n);
double norm(const double a[], int n);
void change(double &a, double &b);

int main() {

  // Create variables
  const int n = 5;
  const double v[n] = {1,2,3,4,5};
  const double w[n] = {10,2,4,3,2};
  double M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

  // Compute scalar product
  cout << scalar(v, w, n) << endl;

  // Compute norm
  cout << norm(v, n) << endl;

  // Compute transpose matrix
  for (int i = 0; i < 3; i++)
    for (int j = i; j < 3; j++)
      change(M[i][j], M[j][i]);

  // Print transpose matrix
  for (int i = 0; i < 3; i++) {

    for (int j = 0; j < 3; j++)
      cout << M[i][j] << " ";
    cout << endl;

  }

  return 0;

}

// Scalar product
double scalar(const double a[], const double b[], int n) {
  double s = 0;
  for (int i = 0; i < n; i++)
    s += a[i] * b[i];
  return s;
}

// Compute the norm of an array
double norm(const double a[], int n) {
  double s = scalar(a, a, n);
  return sqrt(s);
}

// Change a with b
void change(double &a, double &b) {
  const double dep = a;
  a = b;
  b = dep;
}