/*
  Exercise: Histogram from file
  Author: Jesús - 2020
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TF1.h"
#include "TAxis.h"
#include "TStyle.h"
using namespace std;

int main(int argc, char** argv) {

  // Declare application
  TApplication app("App", &argc, argv);
  
  // Create variables
  TCanvas *c = new TCanvas("c", "Esercizio 4", 800, 500);
  TH1F *h1 = new TH1F("h1", "histogram", 50, -20, 25);
  fstream f;

  // Open file
  f.open("../data4.dat", ios::in);
  if (!f.good())
    {
      cerr << "Error reading file." << endl;
      return 1;
    }

  double data;
  for (;;)
    {
      f >> data;
      if (f.eof()) break;
      h1->Fill(data);
    }

  f.close();

  // Cosmetics for the plot
  h1->SetFillColor(kOrange);
  h1->SetLineColor(kBlue);
  h1->GetXaxis()->SetTitle("x");
  h1->GetYaxis()->SetTitle("frequency");
  h1->Draw();

  // Save plot to disk
  c->SaveAs("esercizio5.png");

  // Kepp the application running
  cout << "Press ctr+c to finish" << endl;
  app.Run();

  // Free memory
  delete c;
  delete h1;
  
  return 0;

}