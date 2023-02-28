/*
  Exercise: Histogram fit
  Author: Stefano Carrazza - 2020
*/

#include <iostream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TStyle.h"
using namespace std;

int main(int argc, char** argv) {

  // Declare application
  TApplication app("App", &argc, argv);
  
  // Create variables
  TCanvas *c = new TCanvas("c", "Exercise 3", 800, 500);
  TH1F *h1 = new TH1F("h1", "Exercise 3", 100, -4, 4);

  // Fill histogram with a gaussian
  h1->FillRandom("gaus", 5000);
  h1->SetFillColor(kOrange);
  h1->SetLineColor(kBlue);
  h1->GetXaxis()->SetTitle("x");
  h1->GetYaxis()->SetTitle("frequency");
  h1->Draw();

  // Fitting
  gStyle->SetOptFit();
  h1->Fit("gaus");

  // Save plot to disk
  c->SaveAs("exercise.png");

  // Keep the appliaction running
  cout << "Press ctr+c to finish" << endl;
  app.Run();
 
  // Free memory
  delete c;
  delete h1;
  
  return 0;

}