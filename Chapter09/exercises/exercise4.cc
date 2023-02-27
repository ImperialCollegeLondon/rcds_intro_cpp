/*
  Exercise: Program in C++ with ROOT
  Author: Jesús Urtasun - 20120
*/

#include <iostream>
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
using namespace std;

int main(int argc, char **argv) {

  // Updating application
  TApplication app("App", &argc, argv);

  // Create canvas
  TCanvas *c = new TCanvas("c", "Exercise 4", 800, 500);

  // Create function
  TF1 *f = new TF1("f", "1/x", -10, 10);
  f->Draw();

  c->SaveAs("exercise4.png");

  // Running the application
  cout << "Press ctr+c to finish" << endl;
  app.Run();
  
  // Free memory
  delete f;
  delete c;
  
  return 0;

}