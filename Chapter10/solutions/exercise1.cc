/*
  Exercise: Multi TGraph
  Author: Jesús Urtasun - 2020
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
using namespace std;

// Data structure
struct point2d {
  double x, y;
};

// Distance function
double distance(point2d const& p) {
  return sqrt(pow(p.x-0.5, 2) + pow(p.y-0.5, 2));
}

int main(int argc, char **argv) {

  // Update application
  TApplication app("App", &argc, argv);

  // Declare variables
  fstream f;
  f.open("../data1.dat", ios::in);

  if (!f.good())
    {
      cerr << "Error reading file." << endl;
      return 1;
    }

  // Save data from file in p
  int N = 1000;
  point2d *p = new point2d[N];
  for (int i = 0; i < N; i++)
    f >> p[i].x >> p[i].y;

  f.close();

  // Create Canvas
  TCanvas *c = new TCanvas("c", "Exercise 1", 800, 800);

  // Create TGrphs
  TGraph *g1 = new TGraph();
  TGraph *g2 = new TGraph();
  g1->SetMarkerColor(kBlue);
  g2->SetMarkerColor(kRed);

  // Fill the graps with the values of p
  int index1 = 0, index2 = 0;
  for (int i = 0; i < N; i++)
    {
      if (distance(p[i]) < 0.5)
      {
        g1->SetPoint(index1, p[i].x, p[i].y);
        index1++;
      }
          else
      {
        g2->SetPoint(index2, p[i].x, p[i].y);
        index2++;
      }
    }

  // Cosmetic fot the graphs
  g1->GetXaxis()->SetRangeUser(0,1);
  g1->GetYaxis()->SetRangeUser(0,1);
  g1->SetTitle("Esercizio 1");
  g1->GetXaxis()->SetTitle("x coordinate");
  g1->GetYaxis()->SetTitle("y coordinate");
  g1->Draw("A*");
  g2->Draw("*same");

  // Keep running the application
  app.Run();

  // Free memory
  delete c;
  delete[] p;
  delete g1;
  delete g2;

  return 0;

}