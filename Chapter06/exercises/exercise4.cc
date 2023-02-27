/*
  Exercise: Rectilinear movement
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define N 1000

int main() {

  // Decalre variables;
  double v[N];
  double spazio, tempo;

  // Open datafile
  fstream f;
  f.open("../data_moto.dat", ios::in);

  if (!f.good())
    {
      cerr << "Error reading file data_moto.dat" << endl;
      return 1;
    }

  // Reading data
  for (int i = 0; i < N; i++)
    {
      f >> spazio >> tempo;
      v[i] = spazio / tempo;
    }
  
  f.close();

  // Compute mean velocity
  double sum = 0;
  for (int i = 0; i < N; i++)
    sum += v[i];

  double vmedia = sum / N;
  cout << "Mean velocity = " << vmedia << endl;

  // Compute std.dev of v
  double sum2 = 0;
  for (int i = 0; i < N; i++)
    sum2 += pow(v[i] - vmedia, 2);

  double sigma = sqrt(sum2/(N-1));
  cout << "Standard dev = " << sigma << endl;

  // Compute minumum velocity
  double vmin = v[0];
  for (int i = 1; i < N; i++)
    if (v[i] < vmin)
      vmin = v[i];

  cout << "Minimum velocity = " << vmin << endl;

  // Compute maximum velocity
  double vmax = v[0];
  for (int i = 1; i < N; i++)
    if (v[i] > vmax)
      vmax = v[i];

  cout << "Maximum velocity = " << vmax << endl;
  
  return 0;

}