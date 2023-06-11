/*
  Exercise: Histograms and measurements - Higgs mass
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

  // Declaring variables;
  const int n = 10000;
  double mass[n];

  // Open data file
  fstream f;
  f.open("data_higgs.dat", ios::in);

  if (!f.good())
    {
      cerr << "Error reading data_higgs.dat" << endl;
      return 1;
    }

  // Read data
  for (int i = 0; i < n; i++)
    f >> mass[i];

  f.close();

  // Sor the vector in increading mode, selection sort O(n^2)
  for (int i = 0; i < n-1; i++)
    for (int j = i+1; j < n; j++)
      if (mass[i] > mass[j])
      {
        double tmp = mass[i];
        mass[i] = mass[j];
        mass[j] = tmp;
      }

  // Print minimum and maximum values
  const double massmin = mass[0];
  const double massmax = mass[sizeof(mass)/sizeof(*mass)-1]; // oppure mass[9999];
  cout << "Minimum mass  = " << massmin << " GeV." << endl;
  cout << "Maximum mass = " << massmax << " GeV." << endl;

  // Build binning and fequence histogram
  int nbins = int((massmax - massmin) / 5) + 1;
  double *bins = new double[nbins];
  int *freq = new int[nbins];

  // Initialize bins
  for (int i = 0; i < nbins; i++)
    {
      bins[i] = mass[0] + i*5.0; // binning con lower-edges
      freq[i] = 0;
    }

  // Fill the histogram
  for (int i = 0; i < n; i++)
    for (int b = 0; b < nbins-1; b++)
      if (mass[i] <= bins[b+1]) // Take the upper edge bin as limit
	{
	  freq[b]++;
	  break;
	}

  // Print the histogram
  cout << endl;
  cout << "Histogram:" << endl;
  for (int b = 0; b < nbins; b++)
    cout << "M = " << bins[b] << " GeV -> " << freq[b] << endl;

  // Determina the bin with the highest freq
  int fmax = 0;
  int freqmax = freq[0];

  for (int i = 0; i < nbins; i++)
    if (freq[i] > freqmax)
      {
        fmax = i;
        freqmax = freq[i];
      }

  // Print result
  cout << endl;
  cout << "Most frequent value M = " << bins[fmax] << " GeV with freq = " << freq[fmax] << endl;

  delete[] bins;
  delete[] freq;

  return 0;

}