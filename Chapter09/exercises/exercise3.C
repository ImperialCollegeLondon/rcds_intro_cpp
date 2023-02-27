// ROOT macro

void exercise3() {

  // Create TCanvas object
  TCanvas *c1 = new TCanvas("c1", "Esercizio 3A", 600, 400);

  // Create TF1 object
  TF1 *f1 = new TF1("f1", "x^2", -5, 5);

  // Modify the title and axis
  f1->SetTitle("Exercise 3A");
  f1->GetXaxis()->SetTitle("x");
  f1->GetYaxis()->SetTitle("y");

  // Draw
  f1->Draw();

  // Save as png
  c1->SaveAs("c1.png");

  // Create TCanvas object
  TCanvas *c2 = new TCanvas("c2", "Esercizio 3B", 600, 400);

  // Create TF1 object
  TF1 *f2 = new TF1("f2", "sin(x)/x", -5, 5);

  // Modify title and axis
  f2->SetTitle("Exercise 3B");
  f2->GetXaxis()->SetTitle("x");
  f2->GetYaxis()->SetTitle("y");

  // Design
  f2->Draw();

  // Save as png
  c2->SaveAs("c2.png");

}