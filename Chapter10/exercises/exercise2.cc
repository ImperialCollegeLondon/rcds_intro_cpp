/*
  Exercise: Fitting a TGraphErrors
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TAxis.h"
#include "TF1.h"
#include "TStyle.h"
using namespace std;

int main(int argc, char **argv) {

  // Update application
  TApplication app("App", &argc, argv);

  // Declare variabiles
  fstream f;
  f.open("../data2.dat", ios::in);

  if (!f.good())
    {
      cerr << "Error reading file." << endl;
      return 1;
    }

  // Save data from file in TGraphErrors
  int N = 100;
  double t, y;
  TGraphErrors *data = new TGraphErrors(N);
  for (int i = 0; i < N; i++)
    {
      f >> t >> y;
      data->SetPoint(i, t, y);
      data->SetPointError(i, 0, 0.1);
    }

  f.close();
  
  // Create Canvas
  TCanvas *c = new TCanvas("c", "Exercise 2", 600, 400);
  TF1 *fit = new TF1("fit", "0.5*[0]*x^2");
  data->Fit(fit);
  
  // Set fit options
  gStyle->SetOptFit();
  data->SetTitle("Exercise 2");
  data->GetXaxis()->SetTitle("t (s)");
  data->GetYaxis()->SetTitle("y(t)");
  data->Draw("A*");

  cout << "chi2 = " << fit->GetChisquare() << endl;
  cout << "g = " << fit->GetParameter(0) << endl;
  
  // Keep running the application
  app.Run();

  // Free memory
  delete c;
  delete data;
  delete fit;
  
  return 0;

}